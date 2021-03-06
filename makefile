all: compile output

output:
	gcc -o assembler main.o instruction.o
compile: 
	gcc -c main.c instruction.c

test: assembler
	./assembler input.sia output.bin
	od -x --endian=big output.bin

reset: 
	rm output.bin

clear:
	rm -r assembler main.o instruction.o