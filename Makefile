# Staunton Sample
# sbsample
# pa2
# Makefile

CC = gcc
CFLAGS = -g -Wall -Werror -std=c99
OBJECTS = Lex.o List.o

.PHONY: all
all: Lex

Lex	:	$(OBJECTS)
	$(CC) $(OBJECTS) -o Lex

Lex.o :	Lex.c
	$(CC) $(CFLAGS) -c Lex.c

List.o : List.c
	$(CC) $(CFLAGS) -c List.c



.PHONY: clean
clean:
	rm $(OBJECTS) Lex


