import argparse
import shlex
import socket
import subprocess
import sys
import threading

class Netcat():
    def __init__(self, args, buffer=None):
        self.buffer = buffer
        self.args = args
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR,1)

    def start(self):
        if self.args.listen:
            self.listen()
        else:
            self.send()

    def listen(self):
        try:
            self.socket.bind((self.args.target, self.args.port))
            self.socket.listen(5)
            print(f"Listening on {self.args.target}:{self.args.port}")
            while True:
                client_socket, client_addr = self.socket.accept()
                print(f"Accepted connection from {client_addr[0]}:{client_addr[1]}")
                client_thread = threading.Thread(target=self.handle, args=(client_socket,))
                client_thread.start()
        except Exception as e:
            print(f"Server Killed: {e}")
            self.socket.close()
            sys.exit()

    def send(self):
        self.socket.connect((self.args.target, self.args.port))
        print(f"Connected to {self.args.target}:{self.args.port}")
        if self.buffer:
            self.socket.send(self.buffer)
        try:
            while True:
                recv_len = 1
                response = ""
                while recv_len:
                    data = self.socket.recv(4096)
                    recv_len = len(data)
                    response += data.decode()
                    if recv_len < 4096:
                        break
                if response:
                    print(response)
                    print("NC> ", end="")
                    buffer = input("> ")
                    buffer += "\n"
                    if "\\r" in buffer:
                        buffer = buffer.replace("\\r", "\r").replace("\\n", "\n")
                    self.socket.send(buffer.encode())
        except Exception as e:
            print(f"[!!] {e}")
            self.socket.close()
            sys.exit()

    def handle(self, client_socket):
        if self.args.execute:
            output = execute(self.args.execute)
            client_socket.send(output.encode())

        elif self.args.command:
            cmd_buffer = b""
            while True:
                try:
                    while "\n" not in cmd_buffer.decode():
                        cmd_buffer += client_socket.recv(1024)
                    output = execute(cmd_buffer.decode())
                    if output:
                        client_socket.send(output.encode())
                    cmd_buffer = b""
                except Exception as e:
                    print(f"Server Killed: {e}")
                    self.socket.close()
                    sys.exit()


def execute(cmd):
    cmd = cmd.strip()
    if not cmd:
        return
    output = subprocess.check_output(shlex.split(cmd), stderr=subprocess.STDOUT)
    return output.decode()

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description="BHP Net Tool")
    parser.add_argument("-c", "--command", action="store_true", help="command shell")
    parser.add_argument("-e", "--execute", help="execute specified command")
    parser.add_argument("-l", "--listen", action="store_true", help="listen")
    parser.add_argument("-p", "--port", type=int, default=1337, help="specified port")
    parser.add_argument("-t", "--target", default="127.0.0.1", help="specified IP")

    args = parser.parse_args()

    if args.listen:
        buffer = ""
    else:
        buffer = sys.stdin.read()
        buffer = buffer.replace("\\r", "\r").replace("\\n", "\n")
        print(buffer.encode())

    nc = Netcat(args, buffer.encode())
    nc.start()