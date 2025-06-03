ASM      := nasm
ASMFLAGS := -f elf64
CC       := gcc
CFLAGS   := -no-pie -fno-pie
LDFLAGS  := -z noexecstack

SRCDIR   := src
OBJDIR   := build
OBJS     := \
    $(OBJDIR)/create_stack.o \
		$(OBJDIR)/stack_pop.o    \
		$(OBJDIR)/stack_push.o   \
		$(OBJDIR)/stack_utils.o  \
    $(OBJDIR)/main.o

.PHONY: all clean
all: stack

# Ensure build directory exists
$(OBJDIR):
	mkdir -p $@

# Assemble create_stack.asm into build/
$(OBJDIR)/create_stack.o: $(SRCDIR)/create_stack.asm $(SRCDIR)/structs.inc | $(OBJDIR)
	$(ASM) $(ASMFLAGS) $< -o $@

$(OBJDIR)/stack_pop.o: $(SRCDIR)/stack_pop.asm $(SRCDIR)/structs.inc | $(OBJDIR)
	$(ASM) $(ASMFLAGS) $< -o $@

$(OBJDIR)/stack_push.o: $(SRCDIR)/stack_push.asm $(SRCDIR)/structs.inc | $(OBJDIR)
	$(ASM) $(ASMFLAGS) $< -o $@

$(OBJDIR)/stack_utils.o: $(SRCDIR)/stack_utils.asm $(SRCDIR)/structs.inc | $(OBJDIR)
	$(ASM) $(ASMFLAGS) $< -o $@

# Compile C souorce codes
$(OBJDIR)/main.o: main.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Link all object files into final binary
stack: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -rf $(OBJDIR) stack

