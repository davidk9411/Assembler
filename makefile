all: output test

output:
	gcc -o assembler main.o instruction.o

compile: 
	gcc -c main.c instruction.c

test: assembler
	./assembler input.sia output.bin
	od -x --endian=big output.bin

reset: 
	rm output.bin

clear: reset
	rm -r assembler main.o instruction.o 