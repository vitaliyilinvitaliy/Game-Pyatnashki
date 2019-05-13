CFLAGS = -Wall -Werror
SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
OBJ = g++ $(CFLAGS) -c $< -o $@
 

.PHONY: clean

all: folder1 folder2 folder3 bin/pyatnashki.exe

folder1:
	mkdir -p build

folder2:
	mkdir -p bin

folder3:
	mkdir -p build/src

bin/pyatnashki.exe: build/src/main.o build/src/menu.o
	g++ $(CFLAGS) $^ -o $(SFML) $@

build/src/main.o: src/main.c src/pyatnashki.h
	$(OBJ)

build/src/menu.o: src menu.c src/pyatnashki.h
	$(OBG)
