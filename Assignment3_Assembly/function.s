# This function adds two static numbers together
#Subrtraction works through the neg instruction to convert into two's complement
#function2.s in the git repo reads input/ouput but i could not get it to work
.global _start

.welcomeMessage:       #welcome prompt assembly directive
        .ascii "Welcome: This program adds the numbers 1234 and 5678\12"
        .ascii "Equals: "

.negativeSign:        #negative sign assembly directive
	.ascii "-"

.newLine:             #new line directive
	.ascii "\n"

.data                   #pre initialized data before system runs
	x: .quad 1234   #x and y are the two static nums to be  added
        y: .quad 5678

.text

_add:
	movq x, %rdx     #argument x and y are moved into register          
        movq y, %rax
        addq %rdx, %rax  #add arguments and store in rax  
	ret

_start:
	push %rbp # Push base pointer to the stack
        movq %rsp, %rbp	# Moving the stack pointer to base on stack frame

	# syswrite the welcome prompt
	movq $1, %rax
        movq $1, %rdi
        leaq .welcomeMessage, %rsi
        movq $61, %rdx #size of ascii message
        syscall
	
  	call _add #Adds arguemnts and stores in %rax
	movq $0, %r10 # r10 is counter for loop to print the sum

	cmp $0, %rax      #if rax greater than 0 conditional
	jge longToString  # them jump to printing the sum
	neg %rax          #else negate the number (2's complement operation or multiple by -1)
	push %rax         #push to stack    

	movq $1, %rax     #sys write substratin result appended with negative sign
        movq $1, %rdi                  
        leaq .negativeSign, %rsi
        movq $1, %rdx
	syscall

	pop %rax #pop off top of stack 


longToString:          #loop to divide by 10 until reach 0. Remainder is pushed onto stack
	movq $0, %rdx   #move constant 0 into rdx         
	movq $10, %rbx  #move constant ten into rbx
	idivq %rbx      #divide rdx by 10
	addq $48, %rdx  #add 10 to rdx
	pushq %rdx      #push integer/each digit onto stack
	incq %r10       #increment counter loop
	cmpq $0, %rax   #if reach end/termination
	jz printNumber  #then jump to print number loop
	jmp longToString #else keep doing algorithm to add integrs to stack

printNumber:	                
	cmpq $0, %r10   #if counter is 0
	jz   exit       #then exit loop
	decq %r10       #else decrement counter by one
	movq $1, %rax   #syswrite stack pointer/integer digit           
	movq $1, %rdi
	movq %rsp, %rsi
	movq $1, %rdx
	syscall
	addq $8, %rsp   #offset for next stackpointer
	jmp printNumber #keep reiterating print loop until counter == 0

exit:
	movq $1, %rax          #syscall to write ouput to screen
	movq $1, %rdi
	leaq .newLine, %rsi
	movq $1, %rdx
	syscall

        movq $60, %rax        #sysexit program
        xor %rdi, %rdi
	syscall
	pop %rbp              #pop basepointer










