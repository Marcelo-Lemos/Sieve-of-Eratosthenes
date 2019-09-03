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
all: sieve-parallel.exe sieve-sequential.exe

sieve-parallel.exe: src/sieve-parallel.c
	$(CC) $(CFLAGS) src/sieve-parallel.c -o $@ -lm

sieve-sequential.exe: src/sieve-sequential.c
	$(CC) $(CFLAGS) src/sieve-sequential.c -o $@ -lm

# Rule for cleaning the directory
clean:
	rm -rf *.exe $(OBJDIR)

.PHONY: all clean
