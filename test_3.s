	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15, 6
	.globl	_rotine                 ## -- Begin function rotine
	.p2align	4, 0x90
_rotine:                                ## @rotine
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movabsq	$4602678819172646912, %rax ## imm = 0x3FE0000000000000
	movq	%rax, -16(%rbp)
	cvttsd2si	-16(%rbp), %rax
                                        ## kill: def $eax killed $eax killed $rax
	movl	%eax, %edi
	callq	_sleep
	movq	-8(%rbp), %rcx
	movl	(%rcx), %edx
	movl	%edx, -20(%rbp)
	movslq	-20(%rbp), %rcx
	leaq	_d(%rip), %rsi
	movl	(%rsi,%rcx,4), %esi
	leaq	L_.str(%rip), %rdi
	movl	%eax, -24(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movq	-8(%rbp), %rdi
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	callq	_free
	xorl	%eax, %eax
                                        ## kill: def $rax killed $eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$96, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -12(%rbp)
	movl	%edi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movl	-16(%rbp), %ecx
	movl	%ecx, %eax
	movq	%rsp, %rdx
	movq	%rdx, -32(%rbp)
	leaq	15(,%rax,8), %rdx
	andq	$-16, %rdx
	movq	%rax, -72(%rbp)         ## 8-byte Spill
	movq	%rdx, %rax
	callq	____chkstk_darwin
	subq	%rax, %rsp
	movq	%rsp, %rax
	movq	-72(%rbp), %rdx         ## 8-byte Reload
	movq	%rdx, -40(%rbp)
	movq	%rax, -80(%rbp)         ## 8-byte Spill
	callq	_fork
	cmpl	$-1, %eax
	je	LBB1_14
## %bb.1:
	movq	_mutix@GOTPCREL(%rip), %rdi
	xorl	%eax, %eax
	movl	%eax, %esi
	callq	_pthread_mutex_init
	movl	$0, -44(%rbp)
LBB1_2:                                 ## =>This Inner Loop Header: Depth=1
	movl	-44(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jge	LBB1_6
## %bb.3:                               ##   in Loop: Header=BB1_2 Depth=1
	movl	$4, %edi
	callq	_malloc
	xorl	%ecx, %ecx
	movl	%ecx, %esi
	movq	%rax, -56(%rbp)
	movl	-44(%rbp), %ecx
	movq	-56(%rbp), %rax
	movl	%ecx, (%rax)
	movslq	-44(%rbp), %rax
	shlq	$3, %rax
	movq	-80(%rbp), %rdx         ## 8-byte Reload
	addq	%rax, %rdx
	movq	-56(%rbp), %rax
	movq	%rdx, %rdi
	leaq	_rotine(%rip), %rdx
	movq	%rax, %rcx
	callq	_pthread_create
	cmpl	$0, %eax
	je	LBB1_5
## %bb.4:
	movl	$1, -12(%rbp)
	movl	$1, -60(%rbp)
	jmp	LBB1_16
LBB1_5:                                 ##   in Loop: Header=BB1_2 Depth=1
	movl	-44(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -44(%rbp)
	jmp	LBB1_2
LBB1_6:
	movl	$0, -44(%rbp)
LBB1_7:                                 ## =>This Inner Loop Header: Depth=1
	movl	-44(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jge	LBB1_11
## %bb.8:                               ##   in Loop: Header=BB1_7 Depth=1
	xorl	%eax, %eax
	movl	%eax, %esi
	movl	-44(%rbp), %eax
	movl	%eax, %ecx
	addl	$1, %ecx
	movl	%ecx, -44(%rbp)
	movslq	%eax, %rdx
	movq	-80(%rbp), %rdi         ## 8-byte Reload
	movq	(%rdi,%rdx,8), %rdi
	callq	_pthread_join
	cmpl	$0, %eax
	je	LBB1_10
## %bb.9:
	movl	$6, -12(%rbp)
	movl	$1, -60(%rbp)
	jmp	LBB1_16
LBB1_10:                                ##   in Loop: Header=BB1_7 Depth=1
	jmp	LBB1_7
LBB1_11:
	movq	_mutix@GOTPCREL(%rip), %rdi
	callq	_pthread_mutex_destroy
	cmpl	$0, %eax
	je	LBB1_13
## %bb.12:
	movl	$5, -12(%rbp)
	movl	$1, -60(%rbp)
	jmp	LBB1_16
LBB1_13:
	movl	-16(%rbp), %edi
	movq	-24(%rbp), %rsi
	callq	_main
	movl	$5, %edi
	movl	%eax, -84(%rbp)         ## 4-byte Spill
	callq	_sleep
	jmp	LBB1_15
LBB1_14:
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$1, -12(%rbp)
	movl	$1, -60(%rbp)
	jmp	LBB1_16
LBB1_15:
	movl	$0, -12(%rbp)
	movl	$1, -60(%rbp)
LBB1_16:
	movq	-32(%rbp), %rax
	movq	%rax, %rsp
	movl	-12(%rbp), %eax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	-8(%rbp), %rdx
	cmpq	%rdx, %rcx
	movl	%eax, -88(%rbp)         ## 4-byte Spill
	jne	LBB1_18
## %bb.17:
	movl	-88(%rbp), %eax         ## 4-byte Reload
	movq	%rbp, %rsp
	popq	%rbp
	retq
LBB1_18:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.section	__DATA,__data
	.globl	_d                      ## @d
	.p2align	4
_d:
	.long	1                       ## 0x1
	.long	2                       ## 0x2
	.long	3                       ## 0x3
	.long	4                       ## 0x4
	.long	5                       ## 0x5
	.long	6                       ## 0x6
	.long	7                       ## 0x7
	.long	8                       ## 0x8
	.long	9                       ## 0x9
	.long	10                      ## 0xa

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d\n"

	.comm	_mutix,64,3             ## @mutix
L_.str.1:                               ## @.str.1
	.asciz	"fork failed\n"

.subsections_via_symbols
