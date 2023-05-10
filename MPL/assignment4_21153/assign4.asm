%macro scall 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
%endmacro
section .data
    arr dq 000000000000003h,0000000000000002h
    n equ 2
	menu db 0xA,0xD,"===================MENU==================="
	db 0xA,0xD,"1. Addition"
	db 0xA,0xD,"2. Subtraction"
	db 0xA,0xD,"3. Multiplication"
	db 0xA,0xD,"4. Division"
	db 0xA,0xD,"5. Exit"
	db 0xA,0xD,"Enter your choice:-",0xA,0xD
	menuLen equ $-menu
	thankyou db "Thank You",0xA,0xD
	thnklen equ $-thankyou
	m1 db 0xa,0xd,"Addition :",0xa,0xd
	l1 equ $-m1
	m2 db 0xa,0xd,"Subtraction :",0xa,0xd
	l2 equ $-m2
	m3 db 0xa,0xd,"Multiplication :",0xa,0xd
	l3 equ $-m3
	m4 db 0xa,0xd,"Division :",0xa,0xd
	l4 equ $-m4
section .bss
	answer resb 16
	choice resb 2
section .text
	global _start
	_start:
		up: scall 1,1,menu,menuLen
		scall 0,0,choice,2
		cmp byte[choice],'1'
		jz case1
		cmp byte[choice],'2'
		jz case2
		cmp byte[choice],'3'
		jz case3
		cmp byte[choice],'4'
		jz case4
		cmp byte[choice],'5'
		jz case5
		
		case1:
			call addition 
			jmp up
		case2:
			call subtraction
			jmp up
		case3:
			call multiplication
			jmp up
		case4:
			call division
			jmp up
		case5:
			scall 1,1,thankyou,thnklen
			mov rax,60
			mov rdi,00
			syscall

	addition:
		scall 1,1,m1,l1
		ret
	subtraction:
		scall 1,1,m2,l2
		ret
	multiplication:
		scall 1,1,m3,l3
		ret
	division:
		scall 1,1,m4,l4
		ret