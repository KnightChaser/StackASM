// main.c
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef struct Stack Stack;

// Assembly-implemented routines (to be filled out)
extern Stack *stack_create(void);
extern int64_t stack_pop(Stack *stack);
extern void stack_push(Stack *stack, int64_t value);
extern void stack_destroy(Stack *stack);

int main(int argc, char *argv[]) {
    // Create a new stack
    Stack *stack = stack_create();
    if (stack == NULL) {
        fprintf(stderr, "Failed to create stack\n");
        return 1;
    }
    printf("Stack created successfully: %p\n", (void *)stack);

    // Push some values onto the stack
    for (int i = 0; i < 5; i++) {
        stack_push(stack, i * 10);
        printf("Pushed %d onto the stack\n", i * 10);
    }

    // Pop values from the stack
    for (int i = 0; i < 5; i++) {
        int64_t value = stack_pop(stack);
        printf("Popped %lld from the stack\n", (long long)value);
    }

    // Destroy the stack
    stack_destroy(stack);
    printf("Stack destroyed successfully\n");

    return 0;
}
