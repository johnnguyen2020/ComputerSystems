# Build an executable using the following:
#
# clang barebones.s -o barebones  # clang is another compiler like gcc
#
.text
_barebones:

.data
	
.globl main

main:
					# (1) What are we setting up here?
					# Ans: The first instruction is sent and writes %rbp, the old base pointer into the stack and saved for later 
	pushq %rbp			# Then the register of the stack pointer is copied to the base pointer
	movq  %rsp, %rbp		# After this, %rbp points to the base of the main program's stack frame

					# (2) What is going on here
					# Ans: The arguments for the syscall are being writen $1 is for syswrite syscall
	movq $1, %rax			# $1 is a constant/immediate value for standard output file descriptor in rdi the 1st argument  
	movq $1, %rdi			# load effective adress of .hello.str into buffer filled in %rdi the second argument 
	leaq .hello.str,%rsi		# .hello.str is the assembly directive 


					# (3) What is syscall? We did not talk about this
					# in class.
					# Ans: Request form computer program for a service form the kernal of an OS
					# used by program to interact with the operating system
	syscall				# Which syscall is being run?
					# Ans: syswrite syscall

					# (4) What would another option be instead of 
					# using a syscall to achieve this?
					# Ans: instead of syscall, int 0x80 software interrupt could be use for system call

	movq	$60, %rax		# (5) We are again setting up another syscall
	movq	$0, %rdi		# What command is it?
					# Ans: syexit syscall	
	syscall

	popq %rbp			# (Note we do not really need
					# this command here after the syscall)

.hello.str:
	.string "Hello World!\n"
	.size	.hello.str,13		# (6) Why is there a 13 here?
					# Ans:13 is the size of the Hello World! string directive inluding the newline as 1 character	
