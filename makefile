################################## VARIABLES ###################################

# Project name
PROJ = sieve-of-eratosthenes

# Executable name
EXEC = $(PROJ).exe

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic -fopenmp -O2

# Source and object directories
SRCDIR = src
OBJDIR = obj

# Sources, includes, and objects
SRC := $(wildcard $(SRCDIR)/*.c)
DEP := $(wildcard $(SRCDIR)/*.h)
OBJ := $(patsubst %.c,$(OBJDIR)/%.o,$(notdir $(SRC)))

#################################### RULES #####################################

# Rules for compiling
all: $(EXEC)

$(EXEC): $(OBJDIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEP)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for creating directories
$(OBJDIR) $(OUTDIR):
	@mkdir -p $@

# Rule for cleaning the directory
clean:
	rm -rf $(EXEC) $(OBJDIR)

.PHONY: all clean
