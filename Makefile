cc = gcc
cflags = -lm

all:
	$(cc) -o TS TrapeziosSimples.c $(cflags)
	$(cc) -o TC TrapeziosComposta.c $(cflags)