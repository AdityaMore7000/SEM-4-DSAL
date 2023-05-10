section .data
msg1  db "Elements in array are  : ",0xA,0xD
msg1len : equ $-msg1
msg2  db "Largest element is as follows :",0xA,0xD
msg2len : equ $-msg2
array db 0x0000000000000042,0x0000000000000044,0x0000000000000053,0x0000000000000069,0x0000000000000005

section .bss
counter resb 1
result resb 16

%macro write 2
	mov rax,01
	mov rdi,01
	mov rsi,%1
	mov rdx, %2
	syscall
%endmacro write

%macro exit 0
	mov rax,60
	mov rdi,00
	syscall
%endmacro exit

section .text
	global _start
	_start :
	write msg1, msg1len
	mov rsi,array
	mov byte[counter],05
	write msg2, msg2len
	call disp

	exit
	
	disp:
		mov al,[rsi]
		loop:
		mov bl,al
		rol bl,04
		and bl,0f
		cmp bl,09h
		jbe next30
		next30:
		add bl,30h
		mov byte[array],bl
		dec counter
		jnz loop
	
