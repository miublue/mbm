
OUT = ./mbm
SRC = ./src/*.c ../mutils/*.c
LIB = -lncurses
INC = -I ./src -I ../mutils

all:
	tcc -o $(OUT) $(SRC) $(INC) $(LIB)

install: all
	mv $(OUT) /usr/bin/
