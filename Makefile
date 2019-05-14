CFLAGS = -Wall 
SFML = -lsfml-graphics -lsfml-window -lsfml-system 
OBJ = g++ $(CFLAGS) -c $< -o $@ $(SFML) 
 
.PHONY: clean 

all: folder1 folder2 bin/pyatnashki.exe

folder1:
	mkdir -p build/src

folder2:
	mkdir -p bin


bin/pyatnashki.exe: build/src/main.o build/src/menu.o build/src/records.o build/src/sort_dat.o build/src/write_records.o build/src/play_game.o
	g++ $(CFLAGS) $^ -o $@ $(SFML)

build/src/main.o: src/main.c src/pyatnashki.h
	$(OBJ) 

build/src/menu.o: src/menu.c src/pyatnashki.h
	$(OBJ)

build/src/records.o: src/records.c src/pyatnashki.h
	$(OBJ)

build/src/sort_dat.o: src/sort_dat.c src/pyatnashki.h
	$(OBJ)

build/src/write_records.o: src/write_records.c src/pyatnashki.h
	$(OBJ)

build/src/play_game.o: src/play_game.c src/pyatnashki.h
	$(OBJ)


clean:
	rm -R build
	rm -R bin
