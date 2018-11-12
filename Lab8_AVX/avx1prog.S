	.file	"avx1.c"
	.section	.rodata.cst4,"aM",@progbits,4
	.align	4
.LCPI0_0:
	.long	1098907648              # float 16
	.text
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp3:
	.cfi_def_cfa_offset 16
.Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp5:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	andq	$-32, %rsp
	subq	$672, %rsp              # imm = 0x2A0
.Ltmp6:
	.cfi_offset %rbx, -56
.Ltmp7:
	.cfi_offset %r12, -48
.Ltmp8:
	.cfi_offset %r13, -40
.Ltmp9:
	.cfi_offset %r14, -32
.Ltmp10:
	.cfi_offset %r15, -24
	leaq	.L.str1, %rdi
	leaq	352(%rsp), %rax
	movl	$0, 508(%rsp)
	vmovups	.Lmain.evens(%rip), %ymm0
	vmovaps	%ymm0, 448(%rsp)
	movl	$1073741824, 572(%rsp)  # imm = 0x40000000
	movl	$1082130432, 568(%rsp)  # imm = 0x40800000
	movl	$1086324736, 564(%rsp)  # imm = 0x40C00000
	movl	$1090519040, 560(%rsp)  # imm = 0x41000000
	movl	$1092616192, 556(%rsp)  # imm = 0x41200000
	movl	$1094713344, 552(%rsp)  # imm = 0x41400000
	movl	$1096810496, 548(%rsp)  # imm = 0x41600000
	movl	$1098907648, 544(%rsp)  # imm = 0x41800000
	vmovss	564(%rsp), %xmm1
	vmovss	560(%rsp), %xmm2
	vinsertps	$16, %xmm1, %xmm2, %xmm1 # xmm1 = xmm2[0],xmm1[0],xmm2[2,3]
	vmovss	568(%rsp), %xmm2
	vinsertps	$32, %xmm2, %xmm1, %xmm1 # xmm1 = xmm1[0,1],xmm2[0],xmm1[3]
	vmovss	572(%rsp), %xmm2
	vinsertps	$48, %xmm2, %xmm1, %xmm1 # xmm1 = xmm1[0,1,2],xmm2[0]
	vmovss	.LCPI0_0(%rip), %xmm2
	vmovss	548(%rsp), %xmm3
	vinsertps	$16, %xmm3, %xmm2, %xmm2 # xmm2 = xmm2[0],xmm3[0],xmm2[2,3]
	vmovss	552(%rsp), %xmm3
	vinsertps	$32, %xmm3, %xmm2, %xmm2 # xmm2 = xmm2[0,1],xmm3[0],xmm2[3]
	vmovss	556(%rsp), %xmm3
	vinsertps	$48, %xmm3, %xmm2, %xmm2 # xmm2 = xmm2[0,1,2],xmm3[0]
                                        # implicit-def: YMM0
	vmovaps	%xmm2, %xmm0
	vinsertf128	$1, %xmm1, %ymm0, %ymm0
	vmovaps	%ymm0, 512(%rsp)
	vmovaps	%ymm0, 416(%rsp)
	leaq	448(%rsp), %rcx
	movq	%rcx, 408(%rsp)
	vmovss	448(%rsp), %xmm1
	vmovss	452(%rsp), %xmm2
                                        # implicit-def: XMM3
	vcvtss2sd	%xmm1, %xmm3, %xmm0
                                        # implicit-def: XMM1
	vcvtss2sd	%xmm2, %xmm1, %xmm1
	vmovss	456(%rsp), %xmm2
                                        # implicit-def: XMM3
	vcvtss2sd	%xmm2, %xmm3, %xmm2
	vmovss	460(%rsp), %xmm3
                                        # implicit-def: XMM4
	vcvtss2sd	%xmm3, %xmm4, %xmm3
	vmovss	464(%rsp), %xmm4
                                        # implicit-def: XMM5
	vcvtss2sd	%xmm4, %xmm5, %xmm4
	vmovss	468(%rsp), %xmm5
                                        # implicit-def: XMM6
	vcvtss2sd	%xmm5, %xmm6, %xmm5
	vmovss	472(%rsp), %xmm6
                                        # implicit-def: XMM7
	vcvtss2sd	%xmm6, %xmm7, %xmm6
	vmovss	476(%rsp), %xmm7
                                        # implicit-def: XMM8
	vcvtss2sd	%xmm7, %xmm8, %xmm7
	movl	$.L.str, %edx
	movl	%edx, %ecx
	movb	$8, %sil
	movq	%rdi, 336(%rsp)         # 8-byte Spill
	movq	%rcx, %rdi
	movq	%rax, 328(%rsp)         # 8-byte Spill
	movb	%sil, %al
	vzeroupper
	callq	printf
	movb	$97, 647(%rsp)
	movb	$98, 646(%rsp)
	movb	$99, 645(%rsp)
	movb	$100, 644(%rsp)
	movb	$101, 643(%rsp)
	movb	$102, 642(%rsp)
	movb	$103, 641(%rsp)
	movb	$104, 640(%rsp)
	movb	$105, 639(%rsp)
	movb	$106, 638(%rsp)
	movb	$107, 637(%rsp)
	movb	$108, 636(%rsp)
	movb	$109, 635(%rsp)
	movb	$110, 634(%rsp)
	movb	$111, 633(%rsp)
	movb	$112, 632(%rsp)
	movb	$113, 631(%rsp)
	movb	$114, 630(%rsp)
	movb	$115, 629(%rsp)
	movb	$116, 628(%rsp)
	movb	$117, 627(%rsp)
	movb	$118, 626(%rsp)
	movb	$119, 625(%rsp)
	movb	$120, 624(%rsp)
	movb	$121, 623(%rsp)
	movb	$122, 622(%rsp)
	movb	$48, 621(%rsp)
	movb	$49, 620(%rsp)
	movb	$50, 619(%rsp)
	movb	$51, 618(%rsp)
	movb	$52, 617(%rsp)
	movb	$53, 616(%rsp)
	movzbl	632(%rsp), %edx
	vmovd	%edx, %xmm0
	movzbl	633(%rsp), %edx
	vpinsrb	$1, %edx, %xmm0, %xmm0
	movzbl	634(%rsp), %edx
	vpinsrb	$2, %edx, %xmm0, %xmm0
	movzbl	635(%rsp), %edx
	vpinsrb	$3, %edx, %xmm0, %xmm0
	movzbl	636(%rsp), %edx
	vpinsrb	$4, %edx, %xmm0, %xmm0
	movzbl	637(%rsp), %edx
	vpinsrb	$5, %edx, %xmm0, %xmm0
	movzbl	638(%rsp), %edx
	vpinsrb	$6, %edx, %xmm0, %xmm0
	movzbl	639(%rsp), %edx
	vpinsrb	$7, %edx, %xmm0, %xmm0
	movzbl	640(%rsp), %edx
	vpinsrb	$8, %edx, %xmm0, %xmm0
	movzbl	641(%rsp), %edx
	vpinsrb	$9, %edx, %xmm0, %xmm0
	movzbl	642(%rsp), %edx
	vpinsrb	$10, %edx, %xmm0, %xmm0
	movzbl	643(%rsp), %edx
	vpinsrb	$11, %edx, %xmm0, %xmm0
	movzbl	644(%rsp), %edx
	vpinsrb	$12, %edx, %xmm0, %xmm0
	movzbl	645(%rsp), %edx
	vpinsrb	$13, %edx, %xmm0, %xmm0
	movzbl	646(%rsp), %edx
	vpinsrb	$14, %edx, %xmm0, %xmm0
	movzbl	647(%rsp), %edx
	vpinsrb	$15, %edx, %xmm0, %xmm0
	movl	$53, %edx
	vmovd	%edx, %xmm1
	movzbl	617(%rsp), %edx
	vpinsrb	$1, %edx, %xmm1, %xmm1
	movzbl	618(%rsp), %edx
	vpinsrb	$2, %edx, %xmm1, %xmm1
	movzbl	619(%rsp), %edx
	vpinsrb	$3, %edx, %xmm1, %xmm1
	movzbl	620(%rsp), %edx
	vpinsrb	$4, %edx, %xmm1, %xmm1
	movzbl	621(%rsp), %edx
	vpinsrb	$5, %edx, %xmm1, %xmm1
	movzbl	622(%rsp), %edx
	vpinsrb	$6, %edx, %xmm1, %xmm1
	movzbl	623(%rsp), %edx
	vpinsrb	$7, %edx, %xmm1, %xmm1
	movzbl	624(%rsp), %edx
	vpinsrb	$8, %edx, %xmm1, %xmm1
	movzbl	625(%rsp), %edx
	vpinsrb	$9, %edx, %xmm1, %xmm1
	movzbl	626(%rsp), %edx
	vpinsrb	$10, %edx, %xmm1, %xmm1
	movzbl	627(%rsp), %edx
	vpinsrb	$11, %edx, %xmm1, %xmm1
	movzbl	628(%rsp), %edx
	vpinsrb	$12, %edx, %xmm1, %xmm1
	movzbl	629(%rsp), %edx
	vpinsrb	$13, %edx, %xmm1, %xmm1
	movzbl	630(%rsp), %edx
	vpinsrb	$14, %edx, %xmm1, %xmm1
	movzbl	631(%rsp), %edx
	vpinsrb	$15, %edx, %xmm1, %xmm1
                                        # implicit-def: YMM9
	vmovaps	%xmm1, %xmm9
	vinserti128	$1, %xmm0, %ymm9, %ymm9
	vmovaps	%ymm9, 576(%rsp)
	vmovaps	%ymm9, 352(%rsp)
	movq	328(%rsp), %rcx         # 8-byte Reload
	movq	%rcx, 344(%rsp)
	movq	344(%rsp), %rcx
	movsbl	(%rcx), %esi
	movq	344(%rsp), %rcx
	movsbl	1(%rcx), %edx
	movq	344(%rsp), %rcx
	movsbl	2(%rcx), %ecx
	movq	344(%rsp), %rdi
	movsbl	3(%rdi), %r8d
	movq	344(%rsp), %rdi
	movsbl	4(%rdi), %r9d
	movq	344(%rsp), %rdi
	movsbl	5(%rdi), %r10d
	movq	344(%rsp), %rdi
	movsbl	6(%rdi), %r11d
	movq	344(%rsp), %rdi
	movsbl	7(%rdi), %ebx
	movq	344(%rsp), %rdi
	movsbl	8(%rdi), %r14d
	movq	344(%rsp), %rdi
	movsbl	9(%rdi), %r15d
	movq	344(%rsp), %rdi
	movsbl	10(%rdi), %r12d
	movq	344(%rsp), %rdi
	movsbl	11(%rdi), %r13d
	movq	344(%rsp), %rdi
	movsbl	12(%rdi), %edi
	movl	%esi, 324(%rsp)         # 4-byte Spill
	movq	344(%rsp), %rsi
	movsbl	13(%rsi), %esi
	movl	%esi, 320(%rsp)         # 4-byte Spill
	movq	344(%rsp), %rsi
	movsbl	14(%rsi), %esi
	movl	%esi, 316(%rsp)         # 4-byte Spill
	movq	344(%rsp), %rsi
	movsbl	15(%rsi), %esi
	movl	%esi, 312(%rsp)         # 4-byte Spill
	movq	344(%rsp), %rsi
	movsbl	16(%rsi), %esi
	movl	%esi, 308(%rsp)         # 4-byte Spill
	movq	344(%rsp), %rsi
	movsbl	17(%rsi), %esi
	movl	%esi, 304(%rsp)         # 4-byte Spill
	movq	344(%rsp), %rsi
	movsbl	18(%rsi), %esi
	movl	%esi, 300(%rsp)         # 4-byte Spill
	movq	344(%rsp), %rsi
	movsbl	19(%rsi), %esi
	movl	%esi, 296(%rsp)         # 4-byte Spill
	movq	344(%rsp), %rsi
	movsbl	20(%rsi), %esi
	movl	%esi, 292(%rsp)         # 4-byte Spill
	movq	344(%rsp), %rsi
	movsbl	21(%rsi), %esi
	movl	%esi, 288(%rsp)         # 4-byte Spill
	movq	344(%rsp), %rsi
	movsbl	22(%rsi), %esi
	movl	%esi, 284(%rsp)         # 4-byte Spill
	movq	344(%rsp), %rsi
	movsbl	23(%rsi), %esi
	movl	%esi, 280(%rsp)         # 4-byte Spill
	movq	344(%rsp), %rsi
	movsbl	24(%rsi), %esi
	movl	%esi, 276(%rsp)         # 4-byte Spill
	movq	344(%rsp), %rsi
	movsbl	25(%rsi), %esi
	movl	%esi, 272(%rsp)         # 4-byte Spill
	movq	344(%rsp), %rsi
	movsbl	26(%rsi), %esi
	movl	%esi, 268(%rsp)         # 4-byte Spill
	movq	344(%rsp), %rsi
	movsbl	27(%rsi), %esi
	movl	%esi, 264(%rsp)         # 4-byte Spill
	movq	344(%rsp), %rsi
	movsbl	28(%rsi), %esi
	movl	%esi, 260(%rsp)         # 4-byte Spill
	movq	344(%rsp), %rsi
	movsbl	29(%rsi), %esi
	movl	%esi, 256(%rsp)         # 4-byte Spill
	movq	344(%rsp), %rsi
	movsbl	30(%rsi), %esi
	movl	%esi, 252(%rsp)         # 4-byte Spill
	movq	344(%rsp), %rsi
	movsbl	31(%rsi), %esi
	movl	%esi, 248(%rsp)         # 4-byte Spill
	movq	336(%rsp), %rsi         # 8-byte Reload
	movl	%edi, 244(%rsp)         # 4-byte Spill
	movq	%rsi, %rdi
	movl	324(%rsp), %esi         # 4-byte Reload
	movl	%r10d, (%rsp)
	movl	%r11d, 8(%rsp)
	movl	%ebx, 16(%rsp)
	movl	%r14d, 24(%rsp)
	movl	%r15d, 32(%rsp)
	movl	%r12d, 40(%rsp)
	movl	%r13d, 48(%rsp)
	movl	244(%rsp), %r10d        # 4-byte Reload
	movl	%r10d, 56(%rsp)
	movl	320(%rsp), %r11d        # 4-byte Reload
	movl	%r11d, 64(%rsp)
	movl	316(%rsp), %ebx         # 4-byte Reload
	movl	%ebx, 72(%rsp)
	movl	312(%rsp), %r14d        # 4-byte Reload
	movl	%r14d, 80(%rsp)
	movl	308(%rsp), %r15d        # 4-byte Reload
	movl	%r15d, 88(%rsp)
	movl	304(%rsp), %r12d        # 4-byte Reload
	movl	%r12d, 96(%rsp)
	movl	300(%rsp), %r13d        # 4-byte Reload
	movl	%r13d, 104(%rsp)
	movl	296(%rsp), %r10d        # 4-byte Reload
	movl	%r10d, 112(%rsp)
	movl	292(%rsp), %r10d        # 4-byte Reload
	movl	%r10d, 120(%rsp)
	movl	288(%rsp), %r10d        # 4-byte Reload
	movl	%r10d, 128(%rsp)
	movl	284(%rsp), %r10d        # 4-byte Reload
	movl	%r10d, 136(%rsp)
	movl	280(%rsp), %r10d        # 4-byte Reload
	movl	%r10d, 144(%rsp)
	movl	276(%rsp), %r10d        # 4-byte Reload
	movl	%r10d, 152(%rsp)
	movl	272(%rsp), %r10d        # 4-byte Reload
	movl	%r10d, 160(%rsp)
	movl	268(%rsp), %r10d        # 4-byte Reload
	movl	%r10d, 168(%rsp)
	movl	264(%rsp), %r10d        # 4-byte Reload
	movl	%r10d, 176(%rsp)
	movl	260(%rsp), %r10d        # 4-byte Reload
	movl	%r10d, 184(%rsp)
	movl	256(%rsp), %r10d        # 4-byte Reload
	movl	%r10d, 192(%rsp)
	movl	252(%rsp), %r10d        # 4-byte Reload
	movl	%r10d, 200(%rsp)
	movl	248(%rsp), %r10d        # 4-byte Reload
	movl	%r10d, 208(%rsp)
	movl	%eax, 240(%rsp)         # 4-byte Spill
	movb	$0, %al
	vzeroupper
	callq	printf
	movl	$0, %ecx
	movl	%eax, 236(%rsp)         # 4-byte Spill
	movl	%ecx, %eax
	leaq	-40(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	ret
.Ltmp11:
	.size	main, .Ltmp11-main
	.cfi_endproc

	.type	.Lmain.evens,@object    # @main.evens
	.section	.rodata,"a",@progbits
	.align	16
.Lmain.evens:
	.long	1073741824              # float 2.000000e+00
	.long	1082130432              # float 4.000000e+00
	.long	1086324736              # float 6.000000e+00
	.long	1090519040              # float 8.000000e+00
	.long	1092616192              # float 1.000000e+01
	.long	1094713344              # float 1.200000e+01
	.long	1096810496              # float 1.400000e+01
	.long	1098907648              # float 1.600000e+01
	.size	.Lmain.evens, 32

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"%f %f %f %f %f %f %f %f\n"
	.size	.L.str, 25

	.type	.L.str1,@object         # @.str1
.L.str1:
	.asciz	"asciimessage: %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n"
	.size	.L.str1, 112


	.ident	"clang version 3.4.2 (tags/RELEASE_34/dot2-final)"
	.section	".note.GNU-stack","",@progbits
