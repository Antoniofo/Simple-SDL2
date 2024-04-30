CC=gcc
CFLAGS=-g -Wall
SRC=src
OBJ=obj
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
LIBS=`sdl2-config --cflags --static-libs` -lSDL2_image -lSDL2_ttf

BINDIR=bin
BIN=$(BINDIR)/main

RM_FILES = $(BINDIR)/* $(OBJ)/*

all: $(BIN)

$(BIN): $(OBJS) | $(BINDIR)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBS)

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(BINDIR):
	mkdir $@

$(OBJ):
	mkdir $@

clean:
	$(RM) $(RM_FILES)