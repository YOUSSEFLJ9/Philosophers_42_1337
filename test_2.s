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
	movl	$0, -4(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-4(%rbp), %eax
	movl	%eax, %ecx
	addl	$1, %ecx
	movl	%ecx, -4(%rbp)
	cmpl	$100, %eax
	jge	LBB0_7                                ##   in Loop: Header=BB0_1 Depth=1
LBB0_6:                                 ##   in Loop: Header=BB0_1 Depth=1
	movl	_x(%rip), %eax
	cmpl	$0, _x(%rip)
	movl	$100, %edi
	callq	_usleep
	addl	$1, %eax
	movl	%eax, _x(%rip)
	jmp	LBB0_1
LBB0_7:
	xorl	%eax, %eax
                                        ## kill: def $rax killed $eax
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
	subq	$48, %rsp
	xorl	%eax, %eax
	movl	%eax, %ecx
	leaq	_rotine(%rip), %rdx
	movl	$0, -4(%rbp)
	leaq	-16(%rbp), %rdi
	movq	%rcx, %rsi
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
	movl	_x(%rip), %esi
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$0, -4(%rbp)
LBB1_17:
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_x                      ## @x
.zerofill __DATA,__common,_x,4,2
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d\n"

.subsections_via_symbols
