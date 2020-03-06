all: compile output test

output:
	gcc -o assembler main.o 3Rinstruction.o

compile: 
	gcc -c main.c 3Rinstruction.c

test: assembler
	./assembler input.sia output.bin
	od -x --endian=big output.bin

reset: 
	rm output.bin

clear: reset
	rm -r assembler main.o 3Rinstruction.o 