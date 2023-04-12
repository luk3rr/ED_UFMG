CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
MAIN = $(OBJ)/main.o
OBJS = $(OBJ)/fila.o $(OBJ)/pilha.o $(OBJ)/excpt.o
HDRS = $(INC)/fila.hh $(INC)/pilha.hh $(INC)/excpt.hh
CFLAGS = -O0 -Wall -c -I$(INC)
EXE = $(BIN)/executable

run: $(EXE)
	$(EXE)

$(BIN)/executable: $(MAIN)
	$(CC) -o $(BIN)/executable $(OBJS) $(MAIN) $(LIBS)

$(OBJ)/main.o: $(OBJS) $(SRC)/main.cc
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cc

$(OBJ)/fila.o: $(HDRS) $(SRC)/fila.cc
	$(CC) $(CFLAGS) -o $(OBJ)/fila.o $(SRC)/fila.cc

$(OBJ)/pilha.o: $(HDRS) $(SRC)/pilha.cc
	$(CC) $(CFLAGS) -o $(OBJ)/pilha.o $(SRC)/pilha.cc

$(OBJ)/excpt.o: $(HDRS) $(SRC)/excpt.cc
	$(CC) $(CFLAGS) -o $(OBJ)/excpt.o $(SRC)/excpt.cc

clean:
	rm -f $(EXE) $(OBJS) $(MAIN) gmon.out
