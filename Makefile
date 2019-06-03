#Makefile

OBJ_DIR = ./build
BIN_DIR = ./bin
INC_DIR = ./include
SRC_DIR = ./src
EXE = $(BIN_DIR)/main 

CC = gcc
CFLAGS = -Wall -I$(INC_DIR)
SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/imagem.c $(SRC_DIR)/edicao.c
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/imagem.o $(OBJ_DIR)/edicao.o

$(EXE) : $(OBJS)
	$(CC) -o $(EXE) $(OBJS)

$(OBJ_DIR)/main.o : $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o
$(OBJ_DIR)/imagem.o : $(SRC_DIR)/imagem.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/imagem.c -o $(OBJ_DIR)/imagem.o
$(OBJ_DIR)/edicao.o : $(SRC_DIR)/edicao.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/edicao.c -o $(OBJ_DIR)/edicao.o

.PHONY: clean
clean:
	rm -f ./build/*.o ./bin/*
