global  _sayHello
extern _puts
extern _myPuts
extern _myGTOD

section .text
_sayHello:
    push rbp
    mov rbp, rsp  ;set frame pointer

    mov rdi, helloString ; move hellostring to rdi
    call _puts           ;call puts
    pop rbp
    ret

_myPuts:
    mov rdx, rsi         ;move rsi(len) to rdx
    mov rsi, rdi         ;move rdi(*s) to rsi where string poiner is
    mov rdi, 1           ;set rdi for printing
    mov rax, 1           ;set rax for sys_write
    syscall
    ret

_myGTOD:
    push rbp
    mov rbp, rsp

    sub rsp, 16          ;set stack 16 bytes
    mov rdi, rsp         ;move to rdi for syscall
    mov rsi, 0           ;put null pointer in the rsi
    mov rax, 96          ;set rax for sys_gettimeofday
    syscall

    mov rax, [rsp]       ;move tv_sec from timeval struct
    mov rdx, [rsp+8]     ;move tv_usec from timeval struct
    add rsp, 16          ;give back stack space

    pop rbp
    ret

section .rodata
helloString:    db  "hello",0