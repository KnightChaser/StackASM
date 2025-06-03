// main.c
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef struct Stack Stack;

// Assembly-implemented routines (to be filled out)
extern Stack *stack_create(void);
extern int64_t stack_pop(Stack *stack);
extern void stack_push(Stack *stack, int64_t value);
extern int64_t stack_peek(Stack *stack);
extern int64_t stack_count(Stack *stack);
extern bool stack_is_empty(Stack *stack);
extern void stack_print(Stack *stack);
extern void stack_destroy(Stack *stack);

int main(int argc, char *argv[]) {
    // Create a new stack
    Stack *stack = stack_create();
    if (stack == NULL) {
        fprintf(stderr, "Failed to create stack\n");
        return 1;
    }
    printf("Stack created successfully: %p\n", (void *)stack);
    printf("Stack count: %lld\n", (long long)stack_count(stack));
    printf("Is stack empty? %s\n", stack_is_empty(stack) ? "Yes" : "No");

    // Push some values onto the stack
    for (int i = 0; i < 5; i++) {
        stack_push(stack, i * 10);
        printf("Pushed %d onto the stack, current count: %lld\n", i * 10,
               (long long)stack_count(stack));
    }
    printf("Stack peek: %lld\n", (long long)stack_peek(stack));
    stack_print(stack);

    // Pop values from the stack
    for (int i = 0; i < 5; i++) {
        int64_t value = stack_pop(stack);
        printf("Popped %lld from the stack, current count: %lld\n",
               (long long)value, (long long)stack_count(stack));
    }

    // Destroy the stack
    stack_destroy(stack);
    printf("Stack destroyed successfully\n");

    return 0;
}
