#Makefile

OBJ_DIR = ./build
BIN_DIR = ./bin
INC_DIR = ./include
SRC_DIR = ./src
EXE = $(BIN_DIR)/main 

CC = gcc
CFLAGS = -Wall -I$(INC_DIR)
SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/imagem.c $(SRC_DIR)/edicao.c $(SRC_DIR)/interface.c
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/imagem.o $(OBJ_DIR)/edicao.o $(OBJ_DIR)/interface.o
GTKFLAG = `pkg-config gtk+-3.0 --cflags --libs`

$(EXE) : $(OBJS)
	$(CC) -o $(EXE) $(OBJS) -lm $(GTKFLAG)

$(OBJ_DIR)/main.o : $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) -fPIC $(GTKFLAG) -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o
$(OBJ_DIR)/imagem.o : $(SRC_DIR)/imagem.c
	$(CC) $(CFLAGS) -fPIC $(GTKFLAG) -c $(SRC_DIR)/imagem.c -o $(OBJ_DIR)/imagem.o
$(OBJ_DIR)/edicao.o : $(SRC_DIR)/edicao.c
	$(CC) $(CFLAGS) -fPIC $(GTKFLAG) -c $(SRC_DIR)/edicao.c -o $(OBJ_DIR)/edicao.o
$(OBJ_DIR)/interface.o : $(SRC_DIR)/interface.c
	$(CC) $(CFLAGS) -fPIC $(GTKFLAG) -c $(SRC_DIR)/interface.c -o $(OBJ_DIR)/interface.o

.PHONY: clean
clean:
	rm -f ./build/*.o ./bin/*
