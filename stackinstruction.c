#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "define.h"

extern char *words[5];

//Type 10: POP
int pop(char *bytes){

	bytes[0] = (10 << 4) | getRegister(words[1]);
	bytes[1] = 8<<4 | 0;

	return 2;
}

//Type 01: PUSH
int push(char *bytes){

	bytes[0] = (10 << 4) | getRegister(words[1]);
	bytes[1] = 4<<4 | 0;

	return 2;
}

//Type 00: RETURN
int rturn(char *bytes){

	bytes[0] = (10 << 4) ;
	bytes[1] = 0;

	return 2;
}