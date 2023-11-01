import socket
import sys
import threading

HEX_FILTER = "".join([(len(repr(chr(x))) == 3) and chr(x) or "." for x in range(0, 256)])

def hexdump(src, length=16, show=True):
    if  isinstance(src, bytes):
        src = src.decode()
    
    results = list()

    for i in range(0, len(src), length):
        word = str(src[i:i+length])
        printable = word.translate(HEX_FILTER)
        hexa = " ".join([f"{ord(c):02X}" for c in word])
        hexwidth = length*3
        results.append(f"{i:04x} {hexa:<{hexwidth}} {printable}")
    if show:
        for line in results:
            print(line)
    else:
        return results
    
def receive_from(connection):
    buffer = b""
    connection.settimeout(5)
    try:
        while True:
            data = connection.recv(4096)
            if not data:
                break
            buffer += data
    except Exception as e:
        print(f"Exception: {e}")
    return buffer

def request_handler(buffer):
    #modify packets

    return buffer

def response_handler(buffer):
    #modify packets

    return buffer  

def proxy_handler(client_socket, remote_host, remote_port, receive_first):
    remote_socket = socket.socket()
    remote_socket.connect((remote_host, remote_port))

    if receive_first:
        remote_buffer = receive_from(remote_socket)
        hexdump(remote_buffer)
        remote_buffer = response_handler(remote_buffer)
        if len(remote_buffer):
            print(f"[<==] Sending {len(remote_buffer)} bytes to localhost.")
            client_socket.send(remote_buffer)

    while True:
        local_buffer = receive_from(client_socket)
        hexdump(local_buffer)
        local_buffer = request_handler(local_buffer)
        if len(local_buffer):
            print(f"[==>] Sending {len(local_buffer)} bytes to remote.")
            remote_socket.send(local_buffer)

        remote_buffer = receive_from(remote_socket)
        hexdump(remote_buffer)
        remote_buffer = response_handler(remote_buffer)
        if len(remote_buffer):
            print(f"[<==] Sending {len(remote_buffer)} bytes to localhost.")
            client_socket.send(remote_buffer)

        if len(local_buffer) == 0 and len(remote_buffer) == 0:
            client_socket.close()
            remote_socket.close()
            break
    sys.exit()

def server_loop(local_host, local_port, remote_host, remote_port, receive_first):
    server = socket.socket()
    server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    try:
        server.bind((local_host, local_port))
    except Exception as e:
        print(f"Failed to listen on {local_host}:{local_port}")
        print(f"Exception: {e}")
        sys.exit()
    server.listen(5)
    print(f"Listening on {local_host}:{local_port}")
    while True:
        client_socket, addr = server.accept()
        print(f"Received incoming connection from {addr[0]}:{addr[1]}")
        proxy_thread = threading.Thread(target=proxy_handler, args=(client_socket, remote_host, remote_port, receive_first))
        proxy_thread.start()

if __name__ == '__main__':
    if len(sys.argv[1:]) != 5:
        print("Usage: ./proxy.py [localhost] [localport] [remotehost] [remoteport] [receive_first]")
        print("Example: ./proxy.py")
    
    local_host = sys.argv[1]
    local_port = int(sys.argv[2])
    remote_host = sys.argv[3]
    remote_port = int(sys.argv[4])
    receive_first = sys.argv[5]

    if "True" in receive_first:
        receive_first = True
    else:
        receive_first = False

    server_loop(local_host, local_port, remote_host, remote_port, receive_first)