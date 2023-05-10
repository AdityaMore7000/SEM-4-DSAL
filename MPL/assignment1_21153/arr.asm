section .data
  arr db '1 ','2 ','3 ','4 ','5 ',0xA,0xD
  arrlen : equ $-arr
section .text
  global _start
  
  _start:
  	mov rax,1
  	mov rdi,1
  	mov rsi,arr
  	mov rdx,50
  	syscall
  	mov rax,60
  	mov rdi,00
  	syscall
