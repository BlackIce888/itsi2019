.section data

hallo:  .asciz "Hallo"
welt:   .asciz "Welt"

.section .text

.globl  _start

_start:
	mov $82, %rax
	mov $hallo, %rdi
	mov $welt, %rsi
	syscall

	mov $60 , %rax	# sys_exit
	mov $0 , %rdi	# exit  code 0
	syscall
