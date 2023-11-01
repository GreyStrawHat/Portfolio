import socket
import sys
import threading

def handle_tcp_client(client):
    client.send(b"[Hello]")
    data = client.recv(1024)
    print(f"Received {len(data)} bytes of data in total")
    print(f"Data: {data.decode()}")
    if data.decode() == "[SYN]":
        client.send(b"[SYN-ACK]")
        data = client.recv(1024)
        if data.decode() == "[ACK]":
            print(f"Data: {data.decode()}")
            print("Connection established")

def handle_udp_client(client):
    data, client_addr = client.recvfrom(1024)
    print(f"Received {len(data)} bytes of data in total")
    print(f"Data: {data.decode()}")
    client.sendto(b"[ACK]", client_addr)

def main():
    server = socket.socket()
    server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server.bind(('127.0.0.1', 8080))
    server.listen(5)
    print("Server listening on port 8080")

    try:
        while True:
            client, addr = server.accept()
            print(f'Client {addr} connected')
            threading.Thread(target=handle_tcp_client, args=(client,)).start()
    except Exception as e:
        print("[!!] ", e)
        client.close()
        server.close()
        sys.exit()



if __name__ == '__main__':
    main()