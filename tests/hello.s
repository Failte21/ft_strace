; RDI, RSI, RDX, RCX, R8, R9
; nasm -f elf64 hello.s && ld -o hello hello.o

global _start

section .text
_start:
    mov rax, 1
    mov rdi, 1
    mov rsi, msg
    mov rdx, len
    syscall			; write(1, msg, len)

    mov rax, 60
    mov rdi, 0
    syscall			; exit(0)

section .rodata
msg: db "Hello, world!", 10
len: equ $ - msg
