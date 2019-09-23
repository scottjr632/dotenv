CC ?= cc
CFLAGS += -g -Wall -Wextra -ftrapv -Wshadow -Wundef -Wcast-align -Wunreachable-code
SRC = src/*.c

OBJ = dotenv.o
LIB = libdotenv.dylib

default: build install

build:
	$(CC) $(CFLAGS) -c -fpic -o $(OBJ) $(SRC)
	$(CC) -shared -fpic -o $(LIB) $(OBJ)
	rm $(OBJ)

install:
	sudo mv $(LIB) /usr/local/lib
	sudo cp src/dotenv.h /usr/local/include
