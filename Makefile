cc = gcc
cflags = -lm

all:
	$(cc) -o TS TrapeziosSimples.c $(cflags)
	$(cc) -o TC TrapeziosComposta.c $(cflags)
	$(cc) -o UmTerco UmTercoDeSimpson.c $(cflags)
	$(cc) -o TresOitavos TresOitavosDeSimpson.c $(cflags)
	$(cc) -o Euler Euler.c $(cflags)
	$(cc) -o Taylor SerieDeTaylor.c $(cflags)
	$(cc) -o Segunda SegundaRungeKutta.c $(cflags)
	$(cc) -o Terceira TerceiraRungeKutta.c $(cflags)
	$(cc) -o Quarta QuartaRungeKutta.c $(cflags)