cc = gcc
cflags = -lm

all:
	$(cc) -o TS TrapeziosSimples.c $(cflags)
	$(cc) -o TC TrapeziosComposta.c $(cflags)
	$(cc) -o UmTerco UmTercoDeSimpson.c $(cflags)
	$(cc) -o TresOitavos TresOitavosDeSimpson.c $(cflags)