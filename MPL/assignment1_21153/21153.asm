section .data
	msg db "Hello, I am Aditya",0xA,0xD
	msglen : equ $-msg
section .text
	global_start
	_start:
	;Display
	  mov rax,1
	  mov rdi,1
	  mov rsi,msg
	  mov rdx,msglen
	  syscall
	  mov rax,60
	  mov rdi,00
	  syscall
