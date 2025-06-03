// main.c
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef struct Stack Stack;

// Assembly-implemented routines (to be filled out)
extern Stack *stack_create(void);
extern void stack_push(Stack *stack, int64_t value);

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

    return 0;
}
