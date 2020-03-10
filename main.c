/** ICSI 404 Assignemnt 2
Assmbler for SIA instruction
Made by David Kim
Date:20200305
*/

//Header files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Function definition headers
#include "define.h"

char *words[5];

/**
main function:
recives filename for input and output and processes from assembly instruction to binary output.
*/
int main (int argc, char **argv)  {
	
	//Argument checker
	if (argc != 3)  
		{printf ("info: assemble inputFile outputFile\n"); exit(1); }
	
	//Input file open in read-only mode
	FILE *in = fopen(argv[1],"r");
	
	//Error handling for input file opening
	if (in == NULL) { printf ("error: unable to open input file\n"); exit(1); }
	
	//Output file creation and open in writing binary mode
	FILE *out = fopen(argv[2],"wb");
	
	//Error handling for output file
	if (out == NULL) { printf ("error: unable to open output file\n"); exit(1); }

	//output hex bytes array and input reader
	char bytes[4], inputLine[100];

	//loop keep goes on until end of file
	while (!feof(in)) {

		//if line is not empty
		if (NULL != fgets(inputLine,100,in)) {
			//process SIA instruction to hex/binary code
			//not that value of return is equivalent to instruction size in bytes
			int outSize = assembleLine(inputLine,bytes);
			//write processed code to outputfile
			fwrite(bytes,outSize,1,out);
		}
	}

	//closes input file
	fclose(in);

	//closes output file
	fclose(out);
}

// Figure out from the first word which operation we are doing and do it...
int assembleLine(char *string, char *bytes) {
	
	//Split words into array
	getWords(string);

	//HALT instruction
	if (strcmp(words[0], "halt") == 0){
		return three_register_inst(bytes, 0);
	}

	//ADD instruction
	else if (strcmp(words[0] ,"add") == 0) {
		return three_register_inst(bytes, 1);
	}

	//AND instruction
	else if (strcmp(words[0], "and") == 0) {
		return three_register_inst(bytes, 2);
	}

	//DIVIDE instruction
	else if (strcmp(words[0], "divide") ==0){
		return three_register_inst(bytes, 3);
	}

	//MULTIPLY instruction
	else if (strcmp(words[0], "multiply") ==0){
		return three_register_inst(bytes, 4);
	}

	//SUBTRACT instruction
	else if (strcmp(words[0], "subtract") ==0){
		return three_register_inst(bytes, 5);
	}

	//OR instruction
	else if (strcmp(words[0], "or") ==0){
		return three_register_inst(bytes, 6);
	}

	//BRANCHIFLESS instruction
	else if (strcmp(words[0], "branchifless") ==0){
		return branch(bytes, 0);
	}

	//BRANCHIFLESSEQUAL instruction
	else if (strcmp(words[0], "branchiflessequal") ==0){
		return branch(bytes, 1);
	}

	//BRANCHIFEQUAL instruction
	else if (strcmp(words[0], "branchifequal") ==0){
		return branch(bytes, 2);
	}

	//BRANCHIFNOTEQUAL instruction
	else if (strcmp(words[0], "branchifnotequal") ==0){
		return branch(bytes, 3);
	}

	//BRANCHIFGREATER instruction
	else if (strcmp(words[0], "branchifgreater") ==0){
		return branch(bytes, 4);
	}

	//BRANCHIFGREATEREQUAL instruction
	else if (strcmp(words[0], "branchifgreaterequal") ==0){
		return branch(bytes, 5);
	}

	//CALL instruction
	else if (strcmp(words[0], "call") ==0){
		return branch(bytes, 6);
	}

	//JUMP instruction
	else if (strcmp(words[0], "jump") ==0){
		return branch(bytes, 7);
	}

	//LOAD instruction
	else if (strcmp(words[0], "load") ==0){
		return load_store(bytes,8);
	}

	//STORE instruction
	else if (strcmp(words[0], "store") ==0){
		return load_store(bytes,9);
	}

	//POP instruction
	else if (strcmp(words[0], "pop") ==0){
		return stack_ops(bytes, 2);
	}

	//PUSH instruction
	else if (strcmp(words[0], "push") ==0){
		return stack_ops(bytes, 1);
	}

	//RETURN instruction
	else if (strcmp(words[0], "return") ==0){
		return stack_ops(bytes, 0);
	}

	//MOVE instruction
	else if (strcmp(words[0], "move") ==0){
		return move(bytes);
	}

	//INTERRUPT instruction
	else if (strcmp(words[0], "interrupt") ==0){
		return interrupt(bytes);
	}

}

// takes a string and returns register number or -1 if the string doesn't start with "r" or "R"
int getRegister (char* string) {
	if (string[0] != 'R' && string[0] != 'r') return -1;
	return atoi(string+1);
}

/* Take a string. Split it into different words, putting them in the words array. For example:
 * This is a string
 * Becomes:
 * words[0] = This
 * words[1] = is
 * words[2] = a
 * words[3] = string
 * Only safe when words is big enough...
 */
void getWords(char *string) { 
	printf ("input: %s\n",string);
	int curWord = 0;
	char *cur = string;
	words[curWord] = string;
	while (*cur != 0) {
		if (*cur == '\n' || *cur == '\r') *cur = ' ';
		if (*cur == ' ') {
			*cur = 0; // replace space with NUL
			curWord++;
			words[curWord] = cur+1; // set the start of the next word to the character after this one
		} cur++; } for (int i=0;i<curWord;i++) 
		printf ("word %d = %s\n",i,words[i]);
}