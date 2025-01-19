.intel_syntax noprefix

.global small_execve
.global small_exit
.global small_fork
.global small_read
.global small_waitid
.global small_write

small_execve:
mov rax, 59
syscall
ret

small_exit:
mov rax, 60
syscall

small_fork:
mov rax, 57
syscall
ret

small_read:
mov rax, 0
syscall
ret

small_waitid:
mov rax, 247
mov r10, rcx
syscall
ret

small_write:
mov rax, 1
syscall
ret
