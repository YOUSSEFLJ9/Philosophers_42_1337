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
	subq	$16, %rsp
	movq	_mutix@GOTPCREL(%rip), %rdi
	movq	$0, -8(%rbp)
	callq	_pthread_mutex_lock
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	addq	$1, %rcx
	movq	%rcx, -8(%rbp)
	cmpq	$1000000000, %rax       ## imm = 0x3B9ACA00
	jge	LBB0_3
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movq	_x(%rip), %rax
	addq	$1, %rax
	movq	%rax, _x(%rip)
	jmp	LBB0_1
LBB0_3:
	movq	_mutix@GOTPCREL(%rip), %rdi
	callq	_pthread_mutex_unlock
	xorl	%ecx, %ecx
	movl	%ecx, %edx
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	movq	%rdx, %rax
	addq	$16, %rsp
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
	subq	$64, %rsp
	movq	_mutix@GOTPCREL(%rip), %rdi
	xorl	%eax, %eax
	movl	%eax, %esi
	movl	$0, -4(%rbp)
	callq	_pthread_mutex_init
	xorl	%ecx, %ecx
	movl	%ecx, %edx
	leaq	_rotine(%rip), %rsi
	leaq	-16(%rbp), %rdi
	movq	%rsi, -48(%rbp)         ## 8-byte Spill
	movq	%rdx, %rsi
	movq	-48(%rbp), %r8          ## 8-byte Reload
	movq	%rdx, -56(%rbp)         ## 8-byte Spill
	movq	%r8, %rdx
	movq	-56(%rbp), %rcx         ## 8-byte Reload
	movl	%eax, -60(%rbp)         ## 4-byte Spill
	callq	_pthread_create
	cmpl	$0, %eax
	je	LBB1_2
## %bb.1:
	movl	$1, -4(%rbp)
	jmp	LBB1_17
LBB1_2:
	xorl	%eax, %eax
	movl	%eax, %ecx
	leaq	_rotine(%rip), %rdx
	leaq	-24(%rbp), %rdi
	movq	%rcx, %rsi
	callq	_pthread_create
	cmpl	$0, %eax
	je	LBB1_4
## %bb.3:
	movl	$3, -4(%rbp)
	jmp	LBB1_17
LBB1_4:
	xorl	%eax, %eax
	movl	%eax, %ecx
	leaq	_rotine(%rip), %rdx
	leaq	-32(%rbp), %rdi
	movq	%rcx, %rsi
	callq	_pthread_create
	cmpl	$0, %eax
	je	LBB1_6
## %bb.5:
	movl	$3, -4(%rbp)
	jmp	LBB1_17
LBB1_6:
	xorl	%eax, %eax
	movl	%eax, %ecx
	leaq	_rotine(%rip), %rdx
	leaq	-40(%rbp), %rdi
	movq	%rcx, %rsi
	callq	_pthread_create
	cmpl	$0, %eax
	je	LBB1_8
## %bb.7:
	movl	$3, -4(%rbp)
	jmp	LBB1_17
LBB1_8:
	xorl	%eax, %eax
	movl	%eax, %esi
	movq	-16(%rbp), %rdi
	callq	_pthread_join
	cmpl	$0, %eax
	je	LBB1_10
## %bb.9:
	movl	$2, -4(%rbp)
	jmp	LBB1_17
LBB1_10:
	xorl	%eax, %eax
	movl	%eax, %esi
	movq	-24(%rbp), %rdi
	callq	_pthread_join
	cmpl	$0, %eax
	je	LBB1_12
## %bb.11:
	movl	$3, -4(%rbp)
	jmp	LBB1_17
LBB1_12:
	xorl	%eax, %eax
	movl	%eax, %esi
	movq	-32(%rbp), %rdi
	callq	_pthread_join
	cmpl	$0, %eax
	je	LBB1_14
## %bb.13:
	movl	$3, -4(%rbp)
	jmp	LBB1_17
LBB1_14:
	xorl	%eax, %eax
	movl	%eax, %esi
	movq	-40(%rbp), %rdi
	callq	_pthread_join
	cmpl	$0, %eax
	je	LBB1_16
## %bb.15:
	movl	$3, -4(%rbp)
	jmp	LBB1_17
LBB1_16:
	movq	_mutix@GOTPCREL(%rip), %rdi
	callq	_pthread_mutex_destroy
	movq	_x(%rip), %rsi
	leaq	L_.str(%rip), %rdi
	movl	%eax, -64(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movl	$0, -4(%rbp)
LBB1_17:
	movl	-4(%rbp), %eax
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_x                      ## @x
.zerofill __DATA,__common,_x,8,3
	.comm	_mutix,64,3             ## @mutix
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%lu\n"

.subsections_via_symbols
