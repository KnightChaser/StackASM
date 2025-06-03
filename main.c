// main.c
#include <stdbool.h>
#include <stdio.h>

typedef struct Stack Stack;

// Assembly-implemented routines (to be filled out)
extern Stack *stack_create(void);

int main(int argc, char *argv[]) {
    // Create a new stack
    Stack *stack = stack_create();
    if (stack == NULL) {
        fprintf(stderr, "Failed to create stack\n");
        return 1;
    }
    printf("Stack created successfully: %p\n", (void *)stack);

    return 0;
}
