// main.c
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack Stack;

// Assembly‐implemented routines (to be filled out next)
extern Stack *stack_create(void);
extern void stack_push(Stack *s, int64_t value);
extern int64_t stack_pop(Stack *s);
extern int64_t stack_peek(Stack *s);
extern long stack_count(Stack *s);
extern int stack_is_empty(Stack *s);
extern void stack_print(Stack *s);
extern void stack_destroy(Stack *s);

// Help text
static void help(void) {
    puts("Commands:");
    puts("  push <n>      Push integer n onto stack");
    puts("  pop           Pop & print top element");
    puts("  peek          Print top element without removing");
    puts("  print         Dump entire stack (top→bottom)");
    puts("  count         Show number of elements");
    puts("  empty         1 if empty, 0 otherwise");
    puts("  help          Show this message");
    puts("  exit          Quit");
}

int main(int argc, char *argv[]) {
    Stack *s = stack_create();
    if (!s) {
        fprintf(stderr, "ERROR: could not create stack\n");
        return EXIT_FAILURE;
    }

    char line[128];
    help();

    while (true) {
        printf("stack> ");
        if (!fgets(line, sizeof(line), stdin))
            break;
        line[strcspn(line, "\n")] = '\0'; // strip newline

        if (strncmp(line, "push ", 5) == 0) {
            // Insert a new element into the stack
            int64_t v;
            if (sscanf(line + 5, "%ld", &v) == 1) {
                stack_push(s, v);
                printf("pushed %ld\n", v);
            } else {
                puts("invalid number");
            }

        } else if (strcmp(line, "pop") == 0) {
            // Remove the top element from the stack
            if (stack_is_empty(s)) {
                puts("UNDERFLOW");
            } else {
                int64_t v = stack_pop(s);
                printf("popped %ld\n", v);
            }

        } else if (strcmp(line, "peek") == 0) {
            // Print the top element without removing it
            if (stack_is_empty(s)) {
                puts("EMPTY");
            } else {
                printf("top = %ld\n", stack_peek(s));
            }

        } else if (strcmp(line, "print") == 0) {
            // Print the entire stack from top to bottom
            stack_print(s);

        } else if (strcmp(line, "count") == 0) {
            // Print the number of elements in the stack
            printf("%ld\n", stack_count(s));

        } else if (strcmp(line, "empty") == 0) {
            // Check if the stack is empty
            printf("%s\n", stack_is_empty(s) ? "YES(empty)" : "NO(not empty)");

        } else if (strcmp(line, "help") == 0) {
            // Print the help message
            help();

        } else if (strcmp(line, "exit") == 0) {
            // Exit the program
            printf("See you next time! >_< \n");
            break;

        } else if (line[0] != '\0') {
            printf("unknown command: '%s'\n", line);
        }
    }

    stack_destroy(s);
    return EXIT_SUCCESS;
}
