#include <stdlib.h>
#include <stdio.h>

#include "define.h"

extern char *words[5];

//Opcode 11(B): move
//TODO: integer size check??
int move(char *bytes){
	bytes[0] = (11 << 4) | getRegister(words[1]);
	bytes[1] = atoi(words[2]);
	
	//Total 16bits operation = 2 bytes
	return 2;
}

//Opcode 12(C): interrupt
int interrupt(char *bytes){
	bytes[0] = (12 << 4);
	bytes[1] = atoi(words[1]);
	
	//Total 16bits operation = 2 bytes
	return 2;
}