# modified from https://tcode2k16.github.io/blog/posts/picoctf-2018-writeup/reversing/#assembly-3

from __future__ import print_function
from unicorn import *
from unicorn.x86_const import *
from pwn import *

X86_CODE32 = asm(
'mov    DWORD PTR [ebp+0x10],0x260; \
mov    DWORD PTR [ebp+0xc],0x0; \
jmp    loop1; \
loop12: \
add    DWORD PTR [ebp+0xc],0x1; \
loop1: \
mov    eax,DWORD PTR [ebp+0x8]; \
add    eax,edx; \
mov eax, 0x0; \
add eax, al; \
test   al,al; \
jne    loop12; \
mov    DWORD PTR [ebp+0x14],0x1; \
mov eax,DWORD PTR [ebp+0x10]', 
arch = 'i386', os = 'linux')

ADDRESS = 0x1000000
STACK = 0x2000000
print("Emulate i386 code")
try:
  mu = Uc(UC_ARCH_X86, UC_MODE_64)

  mu.mem_map(ADDRESS, 2 * 1024 * 1024)
  mu.mem_map(STACK, 2 * 1024 * 1024)

  mu.mem_write(ADDRESS, X86_CODE32)
  #mu.mem_write(STACK, '\x0a\x0a\x0a\x0a\x0a\x0a\x0a\x0a'+p32(0xb5e8e971)+p32(0xc6b58a95)+p32(0xe20737e9))
  #0xdff83990,0xeeff29ae,0xfa706498 --- e1b123c5 f0cd08cd 85fc47f1 --- c523b1e1 cd08cdf0 f147fc85
  #mu.mem_write(STACK, '\x0a\x0a\x0a\x0a\x0a\x0a\x0a\x0a'+p32(0xc523b1e1)+p32(0xcd08cdf0)+p32(0xf147fc85))
  mu.mem_write(STACK, '\x0a\x0a\x0a\x0a\x0a\x0a\x0a\x0a'+p32(0x7069636f)+p32(0x4354465f)+p32(0x66646235)+p32(0x00000035))
 
  mu.reg_write(UC_X86_REG_EBP, STACK)
  
  mu.emu_start(ADDRESS, ADDRESS + len(X86_CODE32))

  print("Emulation done. Below is the CPU context")

  r_eax = mu.reg_read(UC_X86_REG_EAX)
  r_ebx = mu.reg_read(UC_X86_REG_EBX)
  print(">>> EAX = 0x%x" % r_eax)
except UcError as e:
  print("ERROR: %s" % e)
