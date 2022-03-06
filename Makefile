CC=gcc
CFLAGS=-Wall -g
LIBS=

NAME=DEE.out
SRC=src/*.c
BIN=bin

all:
	$(CC) -o $(BIN)/$(NAME) $(CFLAGS) $(SRC) $(LIBS)
	$(CC) -o $(BIN)/DEBDEE.out -D DEBON $(CFLAGS) $(SRC) $(LIBS)
