a.out: add.o sub.o common.o validate.o main.o
	gcc *.o
add.o: src/add.c
	gcc -c src/add.c
sub.o: src/sub.c
	gcc -c src/sub.c
common.o: src/common.c
	gcc -c src/common.c
validate.o: src/validate.c
	gcc -c src/validate.c
main.o: src/main.c
	gcc -c src/main.c
clean:
	rm a.out *.o
