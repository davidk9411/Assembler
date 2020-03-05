output: main.o
	gcc -o assembler main.o

compile: main.c
	gcc -c main.c

test: assembler
	./assembler input.sia output.bin
	od -x --endian=big output.bin

reset: output.bin
	rm output.bin

clear: assembler main.o
	rm -r assembler main.o output.bin