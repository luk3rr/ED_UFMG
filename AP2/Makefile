CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
MAIN = $(OBJ)/main.o
OBJS = $(OBJ)/fib.o $(OBJ)/fat.o
HDRS = $(INC)/fib.h $(INC)/fat.h
CFLAGS = -O0 -Wall -c -I$(INC)
EXE = $(BIN)/executable

default: $(EXE)
	$(EXE) $(func) $(value)

run: $(EXE)
	$(EXE) --r_fat 5
	$(EXE) --i_fat 5
	$(EXE) --r_fib 5
	$(EXE) --i_fib 5

$(BIN)/executable: $(MAIN)
	$(CC) -pg -o $(BIN)/executable $(OBJS) $(MAIN) $(LIBS)

$(OBJ)/main.o: $(OBJS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c

$(OBJ)/fib.o: $(HDRS) $(SRC)/fib.c
	$(CC) $(CFLAGS) -o $(OBJ)/fib.o $(SRC)/fib.c

$(OBJ)/fat.o: $(HDRS) $(SRC)/fat.c
	$(CC) $(CFLAGS) -o $(OBJ)/fat.o $(SRC)/fat.c

clean:
	rm -f $(EXE) $(OBJS) gmon.out
