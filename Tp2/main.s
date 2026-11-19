	.file	"ex001.c"
	.text
	.section	.rodata
.LC0:
	.string	"Enter le nomber n : "
.LC1:
	.string	"%d"
.LC2:
	.string	"la somme est %d "
.LC3:
	.string	"\nla puissance : %d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-16(%rbp), %rax
	leaq	.LC1(%rip), %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movl	$0, %eax
	call	__isoc23_scanf@PLT
	movl	-16(%rbp), %eax
	movl	%eax, %edi
	call	somme
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	leaq	.LC2(%rip), %rdx
	movl	%eax, %esi
	movq	%rdx, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-16(%rbp), %eax
	movl	%eax, %edi
	call	puissance
	movl	%eax, %edx
	leaq	.LC3(%rip), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L3
	call	__stack_chk_fail@PLT
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	somme
	.type	somme, @function
somme:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	cmpl	$0, -4(%rbp)
	jne	.L5
	movl	$0, %eax
	jmp	.L6
.L5:
	movl	-4(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	call	somme
	movl	-4(%rbp), %edx
	addl	%edx, %eax
.L6:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	somme, .-somme
	.globl	puissance
	.type	puissance, @function
puissance:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	cmpl	$0, -4(%rbp)
	jne	.L8
	movl	$0, %eax
	jmp	.L9
.L8:
	pxor	%xmm2, %xmm2
	cvtsi2sdl	-4(%rbp), %xmm2
	movq	%xmm2, %rax
	movsd	.LC4(%rip), %xmm0
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	pow@PLT
	movsd	%xmm0, -16(%rbp)
	movl	-4(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	call	puissance
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%eax, %xmm0
	addsd	-16(%rbp), %xmm0
	cvttsd2sil	%xmm0, %eax
.L9:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	puissance, .-puissance
	.section	.rodata
	.align 8
.LC4:
	.long	0
	.long	1074790400
	.ident	"GCC: (GNU) 16.2.1 20260810"
	.section	.note.GNU-stack,"",@progbits
