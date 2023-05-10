%macro print 4
    mov rax,%1
    mov rdi,%2
    mov rsi,%3
    mov rdx,%4
    syscall
%endmacro

%macro exit 2
    mov rax,%1
    mov rdi,%2
    syscall
%endmacro

section .data
msg1 db "Given number is:",0xA,0xD
msg1len equ $-msg1

msg2 db "Factorial of given number is:",0xA,0xD
msg2len equ $-msg2

section .bss

section .text
global _start
_start:
print 1,1,msg1,msg1len
exit 60,00