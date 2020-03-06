#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"define.h"

extern char *words[5];

//Type 0: IFLESS
int branchifless(char *bytes){

	bytes[0] = (7 << 4) | 0;
	bytes[1] = (getRegister(words[1]) << 4) | getRegister(words[2]);
	bytes[2] = (atoi(words[3]) >> 8);
	bytes[3] = (atoi(words[3]) << 8) >> 8;
	//Total 32 bits operation = 4 bytes
	return 4;
}

//Type 1: IFLESSEQUAL
int branchiflessequal(char *bytes){

	bytes[0] = (7 << 4) | 1;
	bytes[1] = (getRegister(words[1]) << 4) | getRegister(words[2]);
	bytes[2] = (atoi(words[3]) >> 8);
	bytes[3] = (atoi(words[3]) << 8) >> 8;

	//Total 32 bits operation = 4 bytes
	return 4;
}

//Type 2: IFQUAL
int branchifequal(char *bytes){

	bytes[0] = (7 << 4) | 2;
	bytes[1] = (getRegister(words[1]) << 4) | getRegister(words[2]);
	bytes[2] = (atoi(words[3]) >> 8);
	bytes[3] = (atoi(words[3]) << 8) >> 8;

	//Total 32 bits operation = 4 bytes
	return 4;
}

//Type 3: IFNOTQUAL
int branchifnotequal(char *bytes){

	bytes[0] = (7 << 4) | 3;
	bytes[1] = (getRegister(words[1]) << 4) | getRegister(words[2]);
	bytes[2] = (atoi(words[3]) >> 8);
	bytes[3] = (atoi(words[3]) << 8) >> 8;

	//Total 32 bits operation = 4 bytes
	return 4;
}

//Type 4: IFGREATER
int branchifgreater(char *bytes){

	bytes[0] = (7 << 4) | 4;
	bytes[1] = (getRegister(words[1]) << 4) | getRegister(words[2]);
	bytes[2] = (atoi(words[3]) >> 8);
	bytes[3] = (atoi(words[3]) << 8) >> 8;

	//Total 32 bits operation = 4 bytes
	return 4;

}

//Type 5: IFGREATEREQUAL
int branchifgreaterequal(char *bytes){

	bytes[0] = (7 << 4) | 5;
	bytes[1] = (getRegister(words[1]) << 4) | getRegister(words[2]);
	bytes[2] = (atoi(words[3]) >> 8);
	bytes[3] = (atoi(words[3]) << 8) >> 8;

	//Total 32 bits operation = 4 bytes
	return 4;

}

//Type 6: CALL
int call(char *bytes){

	bytes[0] = (7 << 4) | 6;
	bytes[1] = (atoi(words[1]) >> 16);
	bytes[2] = (atoi(words[1]) >> 8);
	bytes[3] = (atoi(words[1]) << 8) >> 8;

	//Total 32 bits operation = 4 bytes
	return 4;
}

//Type 7: CALL
int jump(char *bytes){

	bytes[0] = (7 << 4) | 7;
	bytes[1] = (atoi(words[1]) >> 16);
	bytes[2] = (atoi(words[1]) >> 8);
	bytes[3] = (atoi(words[1]) << 8) >> 8;

	//Total 32 bits operation = 4 bytes
	return 4;
}