; src/stack_push.asm

%include "src/structs.inc"

extern malloc
extern exit

global stack_push

section .text
;------------------------------------------------------------------------------
; void stack_push(Stack *s, int64_t value)
;  – allocates a Node, sets data & next, pushes onto stack
; Args:
;  RDI = pointer to Stack
;  RSI = int64_t value to push
;------------------------------------------------------------------------------
stack_push:
    push    rbp
    mov     rbp, rsp
    push    rbx        ; Save rbx for stack pointer
    mov     rbx, rdi   ; rbx <- s (Stack *)

    ; RSI holds the value;
    mov     rdx, rsi   ; rdx <- value (int64_t)
    push    rdx

    ; malloc a new node
    mov     rdi, NODE_SIZE
    call    malloc
    test    rax, rax
    je      .oom
    pop     rdx        ; Restore value from stack

    ; set up the new node
    mov     [rax + NODE_DATA], rdx   ; newNode->data = value (int64_t)
    mov     rcx, [rbx + STACK_TOP]   ; rcx <- s->top (Node *)
    mov     [rax + NODE_NEXT], rcx   ; newNode->next = s->top
    mov     [rbx + STACK_TOP], rax   ; s->top = newNode
    inc     qword [rbx + STACK_SIZE] ; s->size++

    pop     rbx       ; Restore rbx
    pop     rbp
    ret

.oom:
    ; malloc failed -> exit(1)
    mov     rdi, 1
    call    exit
