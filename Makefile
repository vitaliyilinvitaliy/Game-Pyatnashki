CFLAGS = -Wall 
SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
OBJ = g++ -std=c++11 $(CFLAGS) -c $< -o $@ $(SFML) 
TEST = g++ -std=c++11 $(GFAGS) -I thirtdparty/catch2 -c $< -o $@



.PHONY: clean 

all: folder1 folder2 folder3 bin/pyatnashki.exe

folder1:
	mkdir -p build/src

folder2:
	mkdir -p bin

folder3:
	mkdir -p build/test


bin/pyatnashki.exe: build/src/main.o build/src/menu.o build/src/records.o build/src/sort_dat.o build/src/write_records.o build/src/play_game.o build/src/zapolnenie.o build/src/check.o build/src/proverka.o build/src/dvig.o 
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

build/src/zapolnenie.o: src/zapolnenie.c src/pyatnashki.h
	$(OBJ)

build/src/check.o: src/check.c src/pyatnashki.h
	$(OBJ)

build/src/proverka.o: src/proverka.c src/pyatnashki.h
	$(OBJ)

build/src/dvig.o: src/dvig.c src/pyatnashki.h
	$(OBJ)

bin/pyatnashki-test.exe: build/test/test.o build/test/proverka-test.o
	g++ $(CFLAGS) -I thirtdparty/catch2  $^ -o $@

build/test/test.o: test/test.c test/pyatnashki.h
	$(TEST)	

build/test/proverka-test.o: test/proverka-test.c test/pyatnashki.h
	$(TEST)


clean:
	rm -R build
	rm -R bin
