/**
 * Gruppe 7
 * Andreas Diesendorf
 * Artur Siubiak
 * Jan Wolfram
 * 
 * Kompiliert mit:
 * as -o objcode.o renameAssembler.asm; ld -o renameAssembler  objcode.o
 *
 * Ausgeführt:
 * ./renameAssembler
**/

.section data

hallo:  .asciZ "hallo.txt"
welt:   .asciz "welt.txt"

.section .text

.globl  _start

_start:
	mov $82, %rax		# sys_rename
	mov $hallo, %rdi	# old filename
	mov $welt, %rsi		# new filename
	syscall

	mov $60, %rax		# sys_exit
	mov $0, %rdi		# exit  code 0
	syscall
