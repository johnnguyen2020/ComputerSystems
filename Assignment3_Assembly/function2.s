# your code here
.global _start

.welcomeOne:
	.ascii "Please Enter 1 for Addition:\n"
	.ascii "Please Enter 2 for Subtraction:\n"
.welcomeTwo:
	.ascii "Enter x and y: \n"
.jumpAdd:
	.ascii "jumpAdd \n"	
.jumpSub:
	.ascii "jumpSub \n"	

.bss #data that is uninitialized

choice: .skip 16
x:      .skip 16
y:      .skip 16
sum:    .skip 16
	
.text

_printWelcome:
	movq $1, %rax         #Standard out message one syscall
	movq $1, %rdi
	leaq .welcomeOne, %rsi
	movq $61, %rdx
	syscall
	ret

_printWelcomeTwo:            #Standard out message two syscall
	movq $1, %rax
	movq $1, %rdi
	leaq .welcomeTwo, %rsi
	mov $16, %rdx
	syscall
	ret

_jumpAdd:
	movq $1, %rax         #Standard out message one syscall
	movq $1, %rdi
	leaq .jumpAdd, %rsi
	movq $8, %rdx
	syscall
	ret

_jumpSub:
	movq $1, %rax         #Standard out message one syscall
	movq $1, %rdi
	leaq .jumpSub, %rsi
	movq $8, %rdx
	syscall
	ret


_getSelection:             #Stnadard in syscall
	movq $0,%rax
	movq $0,%rdi
	movq $choice, %rsi #load effective address
	movq $2, %rdx
	syscall
	#call _printWelcomeTwo
	#call _getInputX
	#call _getInputY
	ret

_printSelection:
	movq $1, %rax
	movq $1, %rdi
	movq $choice, %rsi
	movq $16, %rdx
	syscall
	ret

_getInputX:	
	movq $0, %rax
	movq $0, %rdi
	leaq x, %rsi #load effective address
	movq $2, %rdx
	syscall
	ret
	
_getInputY:
	movq $0, %rax
	movq $0, %rdi
	leaq y, %rsi #load effective address
	movq $2, %rdx
	syscall
	ret

_printInput1:
	movq $1, %rax
	movq $1, %rdi
	leaq x, %rsi
	movq $2, %rdx
	syscall
	ret

_printInput2:
	movq $1, %rax
	movq $1, %rdi
	leaq y, %rsi
	movq $2, %rdx
	syscall
	ret

_chooseOperation:
	cmp $1, choice
	je _add
	cmp $2, choice
	je _sub
	ret

_add:
/*
	#addq x, %r10
	#addq y, %r10
	#leaq sum, %r10
	#call _printWelcome

	movq $48, -4(%rbp)
	leaq n, -8(%rbp)
	movq -4(%rbp), %edx
	movq -8(%rbp), %eax
	addq %edx, %eax
	movq %eax, -12(%rbp)
	
	movq $1, %rax
	movq $1, %rdi
	movq %rbp, %rsi
	movq $16, %rdx
	syscall
	ret

	movq x, %rax
	movq $0, %rdx
	addq n, %r 
	movq $0, %rdx

	push %rbp
	movq %rsp, %rbp
	push %rsi
	push %rdi
	push %rbx
	sub $4, %rsp
	movq 12(%rbp), %rbx
	add 8(%rbp), %rbx
	movq %rbx, -16(%rbp)
	movq -16(%rbp), %rax
	add $4, %rsp
	pop %rbx
	pop %rdi
	pop %rsi
	mov %rbx, %rsp
	pop %rbp
	ret
*/
	call _jumpAdd

_sub:
	call _jumpSub
/*
_writeOut:
	movq $1, %rax
	movq $1, %rdi
	movq $x, %rsi
	movq $2, %rdx
	syscall
	ret	
*/

_exit:
	mov $60, %rax
	xor %rdi, %rdi
	syscall

_start:
	movq %rsp,%rbp

	call _printWelcome
	call _getSelection
	call _printSelection
	call _printWelcomeTwo
	call _getInputX
	call _getInputY
	call _printInput1
	call _printInput2
	call _chooseOperation
	#call _writeOut
	call _exit
	popq %rbp






















