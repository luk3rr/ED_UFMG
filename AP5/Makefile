# DIRETORIOS
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
BIN_DIR = bin

# NOME DOS EXECUTAVEIS
PROGRAM_NAME = program

# CONFIGURAÇÕES DO COMPILADOR
CC = g++
LIBS = -lm
CFLAGS = --std=c++20 -O0 -Wall

# ARQUIVOS
MAIN = $(OBJ_DIR)/main.o

PROGRAM_OBJS =  $(OBJ_DIR)/queue.o \
				$(OBJ_DIR)/queueExcpt.o \
				$(OBJ_DIR)/binaryTree.o \
				$(OBJ_DIR)/utils.o

# CASES
build: $(OBJ_DIR)/$(PROGRAM_NAME)

run: build
	$(BIN_DIR)/$(PROGRAM_NAME) -n 10

$(OBJ_DIR)/$(PROGRAM_NAME): $(PROGRAM_OBJS) $(MAIN)
	$(CC) $(CFLAGS) $(PROGRAM_OBJS) $(MAIN) -o $(BIN_DIR)/$(PROGRAM_NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc $(INC_DIR)/%.hh
	$(CC) -c $(CFLAGS) $< -I $(INC_DIR) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CC) -c $(CFLAGS) $< -I $(INC_DIR) -o $@

valgrind:
	valgrind --leak-check=full $(BIN_DIR)/$(PROGRAM_NAME)

clean:
	rm -f $(BIN_DIR)/* $(OBJ_DIR)/* gmon.out arvore.txt
