; src/stack_utils.asm

%include "src/structs.inc"

extern free

global stack_destroy

section .text
;------------------------------------------------------------------------------
; void stack_destroy(Stack *s)
;  – walks through all nodes, frees each one, then frees the Stack struct
; Args:
;   RDI = pointer to Stack
;------------------------------------------------------------------------------
stack_destroy:
    push    rbp
    mov     rbp, rsp
    push    rbx        ; save RBX for stack pointer
    mov     rbx, rdi   ; rbx <- s (Stack *)

    ; load first node from s->top
    mov     rcx, [rbx + STACK_TOP]

.destroy_loop:
    test    rcx, rcx               ; if rcx == NULL, there is no more nodes to free
    je      .free_stack
    mov     rax, rcx               ; rax <- current node pointer
    mov     rcx, [rax + NODE_NEXT] ; load next node pointer
    mov     rdi, rax               ; rdi <- current node pointer (for free)
    call    free
    jmp     .destroy_loop

.free_stack:
    ; free the stack struct itself
    mov     rdi, rbx   ; rdi <- stack pointer (for free)
    call    free

    pop     rbx        ; restore RBX
    pop     rbp
    ret
