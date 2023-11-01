import socket

ip = '192.168.141.183'
port = 21

addr = (ip, port)

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

client.connect(addr)

buffer = input()
buffer = buffer

client.send(buffer.replace('\\r', '\r').replace('\\n', '\n').encode())

data = client.recv(1024)
'''
print(f'Received {len(data)} bytes of data:')
print(f"Data: {data.decode()}")
print(buffer.encode())
print(b"GET /get HTTP/1.1\r\nHost: httpbin.org\r\n\r\n")
print(buffer.replace('\\r', '\r').replace('\\n', '\n').encode())
'''