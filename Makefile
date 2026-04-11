all:
	gcc   -c src/main.c -Iinclude  -o src/main.o
	gcc   -c src/list.c  -Iinclude -o src/list.o
	gcc   -c src/file.c -Iinclude -o src/file.o
	gcc   -c src/hash.c -Iinclude -o src/hash.o
	gcc   -c src/work.c -Iinclude -o src/work.o
	gcc src/main.o src/list.o src/file.o src/hash.o src/work.o -o miniGit
clean:
	rm -f src/*.o
run: all
	./miniGit	