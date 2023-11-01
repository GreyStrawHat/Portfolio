import socket

ip = '127.0.0.1'
port = 8888

addr = (ip, port)

client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
#client.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

client.sendto(b"Hello, Server", addr)

data, ret_addr = client.recvfrom(1024)
    
print(f'Received {len(data)} bytes of data from {ret_addr[0]}:{ret_addr[1]}\n[*]', data.decode())