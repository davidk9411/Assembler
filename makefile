all: compile output test

output:
	gcc -o assembler main.o 3Rinstruction.o branchinstruction.o lsinstruction.o stackinstruction.o moveinstruction.o

compile: 
	gcc -c main.c 3Rinstruction.c branchinstruction.c lsinstruction.c stackinstruction.c moveinstruction.c

test: assembler
	./assembler input.sia output.bin
	od -x --endian=big output.bin

reset: 
	rm output.bin

clear: reset
	rm -r assembler main.o 3Rinstruction.o branchinstruction.o lsinstruction.o stackinstruction.o moveinstruction.o