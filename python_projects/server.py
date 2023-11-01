import socket
import threading

server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
server.bind(('0.0.0.0', 8888))
print("Server listening on port 8888")

def handle_udp_client(server):
    while True:
        data, client_addr = server.recvfrom(1024)
        print(f"Received {len(data)} bytes of data in total")
        print(f"Data: {data.decode()}")
        server.sendto(b"Talk to me child", client_addr)
        if not data:
            break


udp_thread = threading.Thread(target=handle_udp_client, args=(server,))
udp_thread.start()