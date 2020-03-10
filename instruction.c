/** ICSI 404 Assignemnt 2
Assmbler for SIA instruction
Made by David Kim
Date:20200305
*/

//Instruction handling functions

#include <stdlib.h>
#include <stdio.h>

#include "define.h"

extern char *words[5];

//3R Instructions: HALT, ADD, AND, DIVIDE, MULTIPLY, OR, SUBTRACT
int three_register_inst(char *bytes, int opcode){

	/*If instruction is halt, then assigns 0
	else process opcode and register 1 from instruction*/
	bytes[0] = opcode==0 ? 0 : (opcode << 4) | getRegister(words[1]);

	/*If instruction is halt, then assigns 0
	else register 2 and 3 from instruction*/
	bytes[1] = opcode==0 ? 0 : (getRegister(words[2]) << 4) | getRegister(words[3]);
	
	//Returns size of instruction in bytes
	return 2;
}

//Branch Instruction: BRANCHIF Series, CALL, JUMP
int branch(char *bytes, int brcode){

	//Process opcode 7 and branch type from instruction
	bytes[0] = (7 << 4) | brcode;
	
	//BRANCHIF series (TYPE 0-5)
	if(brcode<6){
		//Process Register 1 and 2 from instruction
		bytes[1] = (getRegister(words[1]) << 4) | getRegister(words[2]);
		//Address Processing from instruction
		bytes[2] = (atoi(words[3]) >> 8);
		bytes[3] = (atoi(words[3]) << 8) >> 8;		
	}
	
	//CALL, JUMP (TYPE 6,7)
	else{

		//Address processing
		bytes[1] = (atoi(words[1]) >> 16);
		bytes[2] = (atoi(words[1]) >> 8);
		bytes[3] = (atoi(words[1]) << 8) >> 8;
	}


	//Returns size of instruction in bytes
	return 4;
}

//LOAD and STORE instructions
int load_store(char *bytes, int opcode){
	
	//Opcode + Register 1
	bytes[0] = (opcode << 4) | getRegister(words[1]);
	//Register 2 + memory
	bytes[1] = (getRegister(words[2]) << 4) | atoi(words[3]);
	//Returns size of instruction in bytes
	return 2;
}

//POP, PUSH, and RETURN
int stack_ops(char *bytes, int type){

	//If type is 0(Retrun) assign opcode only
	//else, assign both opcode and register
	bytes[0] = type==0 ? (10 << 4) : (10 << 4) | getRegister(words[1]);
	//Assign type only, last 6 bit doesn't required
	bytes[1] = type*4<<4 | 0;

	//Returns size of instruction in bytes
	return 2;
}

//MOVE
int move(char *bytes){
	
	//Assign opcode and register
	bytes[0] = (11 << 4) | getRegister(words[1]);
	//Assign integers
	bytes[1] = atoi(words[2]);
	
	//Returns size of instruction in bytes
	return 2;
}

//Opcode 12(C): interrupt
int interrupt(char *bytes){
	
	//Assign opcode only, register doesn't required
	bytes[0] = (12 << 4);
	//Interrupt type
	bytes[1] = atoi(words[1]);
	
	//Returns size of instruction in bytes
	return 2;
}