section .data
msg1 db "Enter the string:",0xA,0xD
msg1len equ $-msg1
section .bss
string resb 1
result resb 1

global _start

section .text
	_start:
	
	mov rax,1
	mov rdi,1
	mov rsi,msg1
	mov rdx,msg1len
	syscall	
	
	mov rax,0
	mov rdi,0
	mov rsi, string
	mov rdx,200
	syscall
	
	dec rax
	mov rbx,rax
	mov rdi,result
	mov cx,16
	b1: rol rbx,4
	mov al,bl
	and al,0fh
	cmp al,09h
	Jg l1
	add al,30h
	
	jmp l2
	l1 : add al,37h
	l2 : mov [rdi],al
	inc rdi
	dec cx
	jnz b1
	
	mov rax,1
	mov rdi,1
	mov rsi, result
	mov rdx, 16
	syscall
	
	mov rax,60
	mov rdi,00
	syscall
