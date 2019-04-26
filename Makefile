CFLAGS = -Wall -Werror
OBJ = g++ $(CFLAGS) -c $< -o $@
TEST = g++ $(GFLAGS) -I thirtdparty/catch2 -c $< -o $@ 

.PHONY: clean

all: folder1 folder2 folder3 folder4 bin/pyatnashki.exe

folder1:
	mkdir -p build

folder2:
	mkdir -p bin

folder3:
	mkdir -p build/src

folder4:
	mkdir -p build/test

bin/pyatnashki.exe: build/src/main.o build/src/position.o build/src/zapoln.o build/src/print.o build/src/check.o build/src/restart.o build/src/menu.o build/src/view.o build/src/proverka.o
	g++ $(CFLAGS) $^ -o $@

build/src/main.o: src/main.c src/pyatnashki.h
	$(OBJ)

build/src/position.o: src/position.c src/pyatnashki.h
	$(OBJ)

build/src/zapoln.o: src/zapoln.c src/pyatnashki.h
	$(OBJ)

build/src/print.o: src/print.c src/pyatnashki.h
	$(OBJ)

build/src/check.o: src/check.c src/pyatnashki.h
	$(OBJ)

build/src/restart.o: src/restart.c src/pyatnashki.h
	$(OBJ)

build/src/menu.o: src/menu.c src/pyatnashki.h
	$(OBJ)

build/src/view.o: src/view.c src/pyatnashki.h
	$(OBJ)

build/src/proverka.o: src/proverka.c src/pyatnashki.h
	$(OBJ)



bin/pyatnashki-test.exe: build/test/test.o build/test/check-test.o build/test/menu-test.o build/test/proverka-test.o build/test/position-test.o 
	g++ $(GFLAGS) $^ -o $@


build/test/test.o: test/test.c 
	$(TEST)

build/test/check-test.o: test/check-test.c test/pyatnashki.h
	$(TEST)

build/test/menu-test.o: test/menu-test.c test/pyatnashki.h
	$(TEST)

build/test/proverka-test.o: test/proverka-test.c test/pyatnashki.h
	$(TEST)

build/test/position-test.o: test/position-test.c test/pyatnashki.h
	$(TEST)



clean:
	rm -f build/*.o
	rm -f bin/*.exe
	rm -R bin
	rm -R build
