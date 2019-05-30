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

build/src/main.o: src/main.cpp src/pyatnashki.h
	$(OBJ) 

build/src/menu.o: src/menu.cpp src/pyatnashki.h
	$(OBJ)

build/src/records.o: src/records.cpp src/pyatnashki.h
	$(OBJ)

build/src/sort_dat.o: src/sort_dat.cpp src/pyatnashki.h
	$(OBJ)

build/src/write_records.o: src/write_records.cpp src/pyatnashki.h
	$(OBJ)

build/src/play_game.o: src/play_game.cpp src/pyatnashki.h
	$(OBJ)

build/src/zapolnenie.o: src/zapolnenie.cpp src/pyatnashki.h
	$(OBJ)

build/src/check.o: src/check.cpp src/pyatnashki.h
	$(OBJ)

build/src/proverka.o: src/proverka.cpp src/pyatnashki.h
	$(OBJ)

build/src/dvig.o: src/dvig.cpp src/pyatnashki.h
	$(OBJ)

bin/pyatnashki-test.exe: build/test/test.o build/test/proverka-test.o build/test/check-test.o build/test/dvig-test.o
	g++ $(CFLAGS) -I thirtdparty/catch2  $^ -o $@

build/test/test.o: test/test.cpp test/pyatnashki.h
	$(TEST)	

build/test/proverka-test.o: test/proverka-test.cpp test/pyatnashki.h
	$(TEST)

build/test/check-test.o: test/check-test.cpp test/pyatnashki.h
	$(TEST)

build/test/dvig-test.o: test/dvig-test.cpp test/pyatnashki.h
	$(TEST)



clean:
	rm -rf build
	rm -rf bin
