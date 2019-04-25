CFLAGS = -Wall -Werror
OBJ = g++ $(CFAGS) -c $< -o $@

.PHONY: clean

all: folder1 folder2 bin/pyatnashki.exe

folder1:
	mkdir -p build

folder2:
	mkdir -p bin

bin/pyatnashki.exe: build/main.o build/position.o build/zapoln.o build/print.o build/check.o build/restart.o build/menu.o build/view.o build/proverka.o
	g++ $(CFLAGS) $^ -o $@

build/main.o: src/main.c src/pyatnashki.h
	$(OBJ)

build/position.o: src/position.c src/pyatnashki.h
	$(OBJ)

build/zapoln.o: src/zapoln.c src/pyatnashki.h
	$(OBJ)

build/print.o: src/print.c src/pyatnashki.h
	$(OBJ)

build/check.o: src/check.c src/pyatnashki.h
	$(OBJ)

build/restart.o: src/restart.c src/pyatnashki.h
	$(OBJ)

build/menu.o: src/menu.c src/pyatnashki.h
	$(OBJ)

build/view.o: src/view.c src/pyatnashki.h
	$(OBJ)

build/proverka.o: src/proverka.c src/pyatnashki.h
	$(OBJ)




clean:
	rm -f build/*.o
	rm -f bin/*.exe
	rm -R build
	rm -R bin
