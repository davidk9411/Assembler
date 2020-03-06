#include <stdlib.h>
#include <stdio.h>

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

//Opcode 3: Divide
int divide(char *bytes){
	bytes[0] = (3 << 4) | getRegister(words[1]);
	bytes[1] = (getRegister(words[2]) << 4) | getRegister(words[3]);
	
	//Total 16bits operation = 2 bytes
	return 2;
}

//Opcode 4: Multiply
int multiply(char *bytes){
	bytes[0] = (4 << 4) | getRegister(words[1]);
	bytes[1] = (getRegister(words[2]) << 4) | getRegister(words[3]);
	
	//Total 16bits operation = 2 bytes
	return 2;
}

//Opcode 5: Subtract
int subtract(char *bytes){
	bytes[0] = (5 << 4) | getRegister(words[1]);
	bytes[1] = (getRegister(words[2]) << 4) | getRegister(words[3]);
	
	//Total 16bits operation = 2 bytes
	return 2;
}

//Opcode 6: Or
int or(char *bytes){
	bytes[0] = (6 << 4) | getRegister(words[1]);
	bytes[1] = (getRegister(words[2]) << 4) | getRegister(words[3]);
	
	//Total 16bits operation = 2 bytes
	return 2;	
}