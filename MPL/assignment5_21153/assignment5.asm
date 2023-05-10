section .data
array dq 0xffff111133332222,0x1111222233334444,0x5555333344442222,0x1111444422225555,0x1111555522223333
msg1    db   "Count of positive number is:" , 0xA
len1    equ  $-msg1
msg2    db   "Count of negative number is:" , 0xA
len2    equ  $-msg2

count db 05h    
positive db 00h
negative db 00h


section .text

global _start
_start:

mov rsi ,array


l1:
mov rax,qword[rsi]     
bt rax,63          
jnc l2
inc byte[negative]  
jmp update

l2:
inc byte[positive]

update:
inc rsi
dec byte[count]
jnz l1

add byte[positive],30h
add byte[negative],30h

mov  rax , 01
mov  rdi , 01
mov  rsi , msg1
mov  rdx , len1
syscall

mov  rax , 01
mov  rdi , 01
mov  rsi , positive
mov  rdx , 01
syscall

mov rax , 01
mov rdi , 01
mov rsi , msg2
mov rdx , len2
syscall

mov rax , 01
mov rdi , 01
mov rsi , negative
mov rdx , 01
syscall

mov  rax , 60
mov  rdx , 00   
syscall 






