from pwn import *
from time import *

janken = remote('165.232.98.69',30708)

janken.sendline(b'1')

for i in range(99):
    sleep(1)
    janken.sendline(b'("rock"|"paper"|"scissors")')

janken.recvall()
janken.interactive()
