## `StackASM` 🗄️

> A dynamic integer (`int64_t`) stack implemented in **Assembly** (x86_64 NASM, System V AMD64 ABI) with a C-based interactive CLI wrapper. Maybe perfect for learning linked lists as a LIFO stack—zero BS.

### Preview
![image](https://github.com/user-attachments/assets/d5010918-77cf-47b6-9689-64da1e3366d5)


### File Structure

* **Assembly core** in `src/` handles all stack operations (create, push, pop, peek, count, empty check, print, destroy).
* **C CLI** in `main.c` offers an interactive shell for exercising the stack: `push`, `pop`, `peek`, `print`, `count`, `empty`, `help`, `exit`.

```
.
├── Makefile               # build rules using NASM and GCC
├── main.c                 # interactive command-line interface in C
├── README.md              # this documentation >\_<
└── src
    ├── structs.inc        # Node and Stack struct layouts & constants
    ├── create_stack.asm   # stack_create
    ├── stack_push.asm     # stack_push
    ├── stack_pop.asm      # stack_pop
    └── stack_utils.asm    # stack_peek, stack_count, stack_is\_empty, stack_print, stack_destroy (utilities)
```

### Build & Run

```bash
make clean && make    # assemble, compile, and link into ./stack
./stack              # launch the interactive CLI
````

### CLI Commands

* `push <n>`  : push integer `n` onto the stack
* `pop`       : pop & print the top element (underflow exits with error)
* `peek`      : print the top element without removing
* `print`     : dump all elements in LIFO order (`top -> next -> ...`)
* `count`     : display the number of elements
* `empty`     : prints `1` if empty, `0` otherwise
* `help`      : show this help message
* `exit`      : quit the program (frees all memory)

### License & Contributions

This project is open source under the MIT License. Contributions, issues, and patches are welcome — let's keep it lean and mean! >_<
