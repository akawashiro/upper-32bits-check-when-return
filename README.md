# Description
The purpose of this mini-project is to protect programs from the return-to-libc
attack. When a program return from a function, it read the return address from
the top of the stack. In the return-to-libc attack, attacker rewrites the top
of the stack with arbitrary value, e.g., some libc function. We prevent this
attack by rewrite the upper 32 bits of return address with the upper 32 bits of
RIP (the program counter). By this prevention, the program cannot return to
functions in different object files.

In detail, we add following instructions just before the `ret` instruction.
```
lea     (%rip), %rcx
shr     $32, %rcx
shl     $32, %rcx
or      %rcx, (%rsp)
```

## CAUTION
To check the effect of this protection method, you must care about the value
of the buffer overflow. Otherwise, your attack is detected by stack canary.

# Files
- vuln.c  
    Source file with vulnerablity (use of gets function)
- vuln.s  
    Assembler file without the protection  
- vuln.out
    Executable file with the protection  
- vuln-with-aslr-check.s  
    Assembler file with the protection  
- vuln-with-aslr-check.out  
    Executable file with the protection  
