#include <stdlib.h>

#include "define.h"

extern char *words[5];

////Opcode 0: Halt
int halt(char *bytes){
	bytes[0] = 0;
	bytes[1] = 0;

	//Total 16bits operation = 2 bytes
	return 2;
}

//Opcode 1: ADD
int add(char *bytes){
	bytes[0] = (1 << 4) | getRegister(words[1]);
	bytes[1] = (getRegister(words[2]) << 4) | getRegister(words[3]);
	
	//Total 16bits operation = 2 bytes
	return 2;
}

//Opcode 2: AND
int and(char *bytes){
	bytes[0] = (2 << 4) | getRegister(words[1]);
	bytes[1] = (getRegister(words[2]) << 4) | getRegister(words[3]);
	
	//Total 16bits operation = 2 bytes
	return 2;
}