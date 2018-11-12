	.file	"avx2.c"
	.text
	.globl	print__m256
	.align	16, 0x90
	.type	print__m256,@function
print__m256:                            # @print__m256
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp2:
	.cfi_def_cfa_offset 16
.Ltmp3:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp4:
	.cfi_def_cfa_register %rbp
	andq	$-32, %rsp
	subq	$64, %rsp
	vmovaps	%ymm0, (%rsp)
	movq	%rbp, %rsp
	popq	%rbp
	vzeroupper
	ret
.Ltmp5:
	.size	print__m256, .Ltmp5-print__m256
	.cfi_endproc

	.section	.rodata.cst4,"aM",@progbits,4
	.align	4
.LCPI1_0:
	.long	1098907648              # float 16
.LCPI1_1:
	.long	1109917696              # float 42
.LCPI1_2:
	.long	1088421888              # float 7
	.text
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp8:
	.cfi_def_cfa_offset 16
.Ltmp9:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp10:
	.cfi_def_cfa_register %rbp
	andq	$-32, %rsp
	subq	$544, %rsp              # imm = 0x220
	movl	$0, 252(%rsp)
	movl	$1073741824, 316(%rsp)  # imm = 0x40000000
	movl	$1082130432, 312(%rsp)  # imm = 0x40800000
	movl	$1086324736, 308(%rsp)  # imm = 0x40C00000
	movl	$1090519040, 304(%rsp)  # imm = 0x41000000
	movl	$1092616192, 300(%rsp)  # imm = 0x41200000
	movl	$1094713344, 296(%rsp)  # imm = 0x41400000
	movl	$1096810496, 292(%rsp)  # imm = 0x41600000
	movl	$1098907648, 288(%rsp)  # imm = 0x41800000
	vmovss	308(%rsp), %xmm0
	vmovss	304(%rsp), %xmm1
	vinsertps	$16, %xmm0, %xmm1, %xmm0 # xmm0 = xmm1[0],xmm0[0],xmm1[2,3]
	vmovss	312(%rsp), %xmm1
	vinsertps	$32, %xmm1, %xmm0, %xmm0 # xmm0 = xmm0[0,1],xmm1[0],xmm0[3]
	vmovss	316(%rsp), %xmm1
	vinsertps	$48, %xmm1, %xmm0, %xmm0 # xmm0 = xmm0[0,1,2],xmm1[0]
	vmovss	.LCPI1_0(%rip), %xmm1
	vmovss	292(%rsp), %xmm2
	vinsertps	$16, %xmm2, %xmm1, %xmm1 # xmm1 = xmm1[0],xmm2[0],xmm1[2,3]
	vmovss	296(%rsp), %xmm2
	vinsertps	$32, %xmm2, %xmm1, %xmm1 # xmm1 = xmm1[0,1],xmm2[0],xmm1[3]
	vmovss	300(%rsp), %xmm2
	vinsertps	$48, %xmm2, %xmm1, %xmm1 # xmm1 = xmm1[0,1,2],xmm2[0]
                                        # implicit-def: YMM3
	vmovaps	%xmm1, %xmm3
	vinsertf128	$1, %xmm0, %ymm3, %ymm3
	vmovaps	%ymm3, 256(%rsp)
	vmovaps	%ymm3, 192(%rsp)
	movl	$.L.str, %eax
	movl	%eax, %edi
	xorl	%eax, %eax
	movb	%al, %cl
	movb	%cl, %al
	movb	%cl, 31(%rsp)           # 1-byte Spill
	vzeroupper
	callq	printf
	vmovaps	192(%rsp), %ymm0
	movl	%eax, 24(%rsp)          # 4-byte Spill
	callq	print__m256
	vxorps	%ymm0, %ymm0, %ymm0
	vmovaps	%ymm0, 320(%rsp)
	vmovaps	%ymm0, 160(%rsp)
	movl	$1109917696, 444(%rsp)  # imm = 0x42280000
	vbroadcastss	.LCPI1_1(%rip), %ymm0
	vmovaps	%ymm0, 384(%rsp)
	vmovaps	%ymm0, 128(%rsp)
	movl	$.L.str1, %eax
	movl	%eax, %edi
	movb	31(%rsp), %al           # 1-byte Reload
	vzeroupper
	callq	printf
	vmovaps	160(%rsp), %ymm0
	movl	%eax, 20(%rsp)          # 4-byte Spill
	callq	print__m256
	vmovaps	128(%rsp), %ymm0
	callq	print__m256
	movl	$0, 524(%rsp)
	movl	$1065353216, 520(%rsp)  # imm = 0x3F800000
	movl	$1073741824, 516(%rsp)  # imm = 0x40000000
	movl	$1077936128, 512(%rsp)  # imm = 0x40400000
	movl	$1082130432, 508(%rsp)  # imm = 0x40800000
	movl	$1084227584, 504(%rsp)  # imm = 0x40A00000
	movl	$1086324736, 500(%rsp)  # imm = 0x40C00000
	movl	$1088421888, 496(%rsp)  # imm = 0x40E00000
	vmovss	516(%rsp), %xmm1
	vmovss	512(%rsp), %xmm2
	vinsertps	$16, %xmm1, %xmm2, %xmm1 # xmm1 = xmm2[0],xmm1[0],xmm2[2,3]
	vmovss	520(%rsp), %xmm2
	vinsertps	$32, %xmm2, %xmm1, %xmm1 # xmm1 = xmm1[0,1],xmm2[0],xmm1[3]
	vmovss	524(%rsp), %xmm2
	vinsertps	$48, %xmm2, %xmm1, %xmm1 # xmm1 = xmm1[0,1,2],xmm2[0]
	vmovss	.LCPI1_2(%rip), %xmm2
	vmovss	500(%rsp), %xmm4
	vinsertps	$16, %xmm4, %xmm2, %xmm2 # xmm2 = xmm2[0],xmm4[0],xmm2[2,3]
	vmovss	504(%rsp), %xmm4
	vinsertps	$32, %xmm4, %xmm2, %xmm2 # xmm2 = xmm2[0,1],xmm4[0],xmm2[3]
	vmovss	508(%rsp), %xmm4
	vinsertps	$48, %xmm4, %xmm2, %xmm2 # xmm2 = xmm2[0,1,2],xmm4[0]
                                        # implicit-def: YMM0
	vmovaps	%xmm2, %xmm0
	vinsertf128	$1, %xmm1, %ymm0, %ymm0
	vmovaps	%ymm0, 448(%rsp)
	vmovaps	%ymm0, 96(%rsp)
	movl	$.L.str2, %eax
	movl	%eax, %edi
	movb	31(%rsp), %al           # 1-byte Reload
	vzeroupper
	callq	printf
	vmovaps	96(%rsp), %ymm0
	movl	%eax, 16(%rsp)          # 4-byte Spill
	callq	print__m256
	movl	$32, %eax
	movl	%eax, %edi
	movl	$256, %eax              # imm = 0x100
	movl	%eax, %esi
	vzeroupper
	callq	aligned_alloc
	movq	%rax, 88(%rsp)
	movl	$.L.str3, %edx
	movl	%edx, %edi
	movb	31(%rsp), %al           # 1-byte Reload
	callq	printf
	movl	$.L.str4, %edx
	movl	%edx, %edi
	movl	$4, %edx
	movl	%edx, %esi
	movb	31(%rsp), %cl           # 1-byte Reload
	movl	%eax, 12(%rsp)          # 4-byte Spill
	movb	%cl, %al
	callq	printf
	movq	88(%rsp), %rsi
	movl	$0, (%rsi)
	movq	88(%rsp), %rsi
	movl	$1065353216, 4(%rsi)    # imm = 0x3F800000
	movq	88(%rsp), %rsi
	movl	$1073741824, 8(%rsi)    # imm = 0x40000000
	movq	88(%rsp), %rsi
	movl	$1077936128, 12(%rsi)   # imm = 0x40400000
	movq	88(%rsp), %rsi
	movl	$1082130432, 16(%rsi)   # imm = 0x40800000
	movq	88(%rsp), %rsi
	movl	$1084227584, 20(%rsi)   # imm = 0x40A00000
	movq	88(%rsp), %rsi
	movl	$1086324736, 24(%rsi)   # imm = 0x40C00000
	movq	88(%rsp), %rsi
	movl	$1088421888, 28(%rsi)   # imm = 0x40E00000
	movq	88(%rsp), %rsi
	movq	%rsi, 376(%rsp)
	vmovaps	(%rsi), %ymm0
	vmovaps	%ymm0, 32(%rsp)
	movl	%eax, 8(%rsp)           # 4-byte Spill
	callq	print__m256
	movl	$0, %eax
	movq	%rbp, %rsp
	popq	%rbp
	vzeroupper
	ret
.Ltmp11:
	.size	main, .Ltmp11-main
	.cfi_endproc

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"=========Printing evens=========\n\n"
	.size	.L.str, 35

	.type	.L.str1,@object         # @.str1
.L.str1:
	.asciz	"=========Printing 0's and 42's=========\n\n"
	.size	.L.str1, 42

	.type	.L.str2,@object         # @.str2
.L.str2:
	.asciz	"=========Printing _mm256_set_ps=========\n\n"
	.size	.L.str2, 43

	.type	.L.str3,@object         # @.str3
.L.str3:
	.asciz	"=========Loading aligned data=========\n"
	.size	.L.str3, 40

	.type	.L.str4,@object         # @.str4
.L.str4:
	.asciz	"sizeof(float)=%lu\n"
	.size	.L.str4, 19


	.ident	"clang version 3.4.2 (tags/RELEASE_34/dot2-final)"
	.section	".note.GNU-stack","",@progbits
