# DIRETORIOS
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
BIN_DIR = bin

# NOME DOS EXECUTAVEIS
PROGRAM_NAME = program

# CONFIGURAÇÕES DO COMPILADOR
CC = gcc
LIBS = -lm
CFLAGS = -g

nc = 500
nm = 100
CARGA = -DCARGA=$(nc)
ORDEM = -Dm=$(nm)

# ARQUIVOS
PROGRAM_OBJS = $(OBJ_DIR)/arvexp.o \
	       $(OBJ_DIR)/main.o

# CASES
run: exp1 exp2

exp2:
	$(info ------ Experimento 2 ------)
	$(eval nm = 100)
	$(eval nc = 50)
	$(CC) $(ORDEM) $(CARGA) $(CFLAGS) $(LIBS) $(PROGRAM_OBJS) -o $(BIN_DIR)/$(PROGRAM_NAME)
	time -p  $(BIN_DIR)/$(PROGRAM_NAME)
	$(eval nm = 100)
	$(eval nc = 100)
	$(CC) $(ORDEM) $(CARGA) $(CFLAGS) $(LIBS) $(PROGRAM_OBJS) -o $(BIN_DIR)/$(PROGRAM_NAME)
	time -p  $(BIN_DIR)/$(PROGRAM_NAME)
	$(eval nm = 100)
	$(eval nc = 200)
	$(CC) $(ORDEM) $(CARGA) $(CFLAGS) $(LIBS) $(PROGRAM_OBJS) -o $(BIN_DIR)/$(PROGRAM_NAME)
	time -p  $(BIN_DIR)/$(PROGRAM_NAME)
	$(eval nm = 100)
	$(eval nc = 500)
	$(CC) $(ORDEM) $(CARGA) $(CFLAGS) $(LIBS) $(PROGRAM_OBJS) -o $(BIN_DIR)/$(PROGRAM_NAME)
	time -p  $(BIN_DIR)/$(PROGRAM_NAME)

exp1:
	$(info ------ Experimento 1 ------)
	$(eval nm = 10)
	$(eval nc = 100)
	$(CC) $(ORDEM) $(CARGA) $(CFLAGS) $(LIBS) $(PROGRAM_OBJS) -o $(BIN_DIR)/$(PROGRAM_NAME)
	time -p  $(BIN_DIR)/$(PROGRAM_NAME)
	$(eval nm = 50)
	$(eval nc = 100)
	$(CC) $(ORDEM) $(CARGA) $(CFLAGS) $(LIBS) $(PROGRAM_OBJS) -o $(BIN_DIR)/$(PROGRAM_NAME)
	time -p  $(BIN_DIR)/$(PROGRAM_NAME)
	$(eval nm = 100)
	$(eval nc = 100)
	$(CC) $(ORDEM) $(CARGA) $(CFLAGS) $(LIBS) $(PROGRAM_OBJS) -o $(BIN_DIR)/$(PROGRAM_NAME)
	time -p  $(BIN_DIR)/$(PROGRAM_NAME)
	$(eval nm = 100)
	$(eval nc = 500)
	$(CC) $(ORDEM) $(CARGA) $(CFLAGS) $(LIBS) $(PROGRAM_OBJS) -o $(BIN_DIR)/$(PROGRAM_NAME)
	time -p  $(BIN_DIR)/$(PROGRAM_NAME)

$(PROGRAM_NAME): $(PROGRAM_OBJS)
	$(CC) $(ORDEM) $(CARGA) $(CFLAGS) $(LIBS) $(PROGRAM_OBJS) -o $(BIN_DIR)/$(PROGRAM_NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/%.h
	$(CC) -c $(ORDEM) $(CARGA) $(CFLAGS) $< -I $(INC_DIR) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(ORDEM) $(CARGA) $(CFLAGS) $< -I $(INC_DIR) -o $@

clean:
	rm -f $(BIN_DIR)/* $(OBJ_DIR)/* gmon.out data.dat grafico.png
