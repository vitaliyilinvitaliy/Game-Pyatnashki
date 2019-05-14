CFLAGS = -Wall 
SFML = -lsfml-graphics -lsfml-window -lsfml-system 
OBJ = g++ $(CFLAGS) -c $< -o $@ $(SFML) 
 
.PHONY: clean 

all: folder1 folder2 bin/pyatnashki.exe

folder1:
	mkdir -p build/src

folder2:
	mkdir -p bin


bin/pyatnashki.exe: build/src/main.o build/src/menu.o
	g++ $(CFLAGS) $^ -o $@ $(SFML)

build/src/main.o: src/main.c src/pyatnashki.h
	$(OBJ) 
build/src/menu.o: src/menu.c src/pyatnashki.h
	$(OBJ)

clean:
	rm -R build
	rm -R bin
