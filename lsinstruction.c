#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "define.h"

extern char *words[5];

//OPCODE 8: LOAD
int load(char *bytes){
	bytes[0] = (8 << 4) | getRegister(words[1]);
	bytes[1] = (getRegister(words[2]) << 4) | atoi(words[3]);
	//Total 16bits operation = 2 bytes
	return 2;
}

//OPCODE 9: STORE
//TODO: words[3] size check -> less than 15?
int store(char *bytes){
	bytes[0] = (9 << 4) | getRegister(words[1]);
	bytes[1] = (getRegister(words[2]) << 4) | atoi(words[3]);
	//Total 16bits operation = 2 bytes
	return 2;
}