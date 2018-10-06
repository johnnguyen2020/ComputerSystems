# your code here
.global _start

.welcomePrompt:
        .ascii "Welcome, this program adds the numbers 5000 and 6000\12"
        .ascii "Result: "

.negativeSign:
	.ascii "-"

.data
        staticNum1: .quad 5000
        staticNum2: .quad 6000
	ten: .long 10
.text

_add:
	movq staticNum1, %rdx
        movq staticNum2, %rax
        addq %rdx, %rax
	ret

#_sub:
#	movq staticNum1, %rdx
#       movq staticNum2, %rax
#        subq %rdx, %rax
#        ret

#_exit:
#        movq $60, %rax
#        xor %rdi, %rdi
#        syscall

_start:
	push %rbp # Pushing the base pointer to the stack
        movq %rsp, %rbp	# Moving the stack pointer (points to head of stack) to base (only thing on stack right now)

	# Printing the welcome prompt
	movq $1, %rax
        movq $1, %rdi
        leaq .welcomePrompt, %rsi
        movq $61, %rdx
        syscall
	
  	call _add # The _addfunction is called and puts the result of the addition in %rax
	movq $0, %r8 # Register r8 will serve as a counter for the loop to print the result
	cmp $0, %rax # The addition result in rax is compared with the direct value 0 to determine if it is negative
	jge longToString # If the result of comparison was that rax is greater than 0, the program jums to longToString (printing the number)
	neg %rax
	push %rax
	movq $1, %rax
        movq $1, %rdi
        leaq .negativeSign, %rsi
        movq $1, %rdx
	syscall
	pop %rax

longToString:
	movq $0, %rdx
	divq ten
	addq $48, %rdx
	pushq %rdx
	incq %r8
	cmpq $0, %rax
	jz printNumber
	jmp longToString

printNumber:	
	cmpq $0, %r8
	jz   exit
	decq %r8
	movq $1, %rax
	movq $1, %rdi
	movq %rsp, %rsi
	movq $1, %rdx
	syscall
	addq $8, %rsp
	jmp  printNumber

exit:
        movq $60, %rax
        xor %rdi, %rdi
        syscall    
	#call _exit
        pop %rbp

#_sub:
#        movq staticNum1, %rdx
#        movq staticNum2, %rax
#        subq %rdx, %rax
#        ret