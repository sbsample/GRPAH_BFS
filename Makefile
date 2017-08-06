# Staunton Sample
# sbsample
# pa2
# Makefile

CC = gcc
CFLAGS = -g -Wall -Werror -std=c99
OBJECTS = Graph.o List.o FindPath.o

.PHONY: all
all: FindPath

FindPath	:	$(OBJECTS)
	$(CC) $(OBJECTS) -o FindPath

FindPath.o :	FindPath.c
	$(CC) $(CFLAGS) -c FindPath.c

List.o : List.c
	$(CC) $(CFLAGS) -c List.c

Graph.o : Graph.c
	$(CC) $(CFLAGS) -c Graph.c



.PHONY: clean
clean:
	rm $(OBJECTS) FindPath


