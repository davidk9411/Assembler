/** ICSI 404 Assignemnt 2
Assmbler for SIA instruction
Made by David Kim
Date:20200305
*/

//Header files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "define.h"

char *words[5];

/**
main function:
recives filename for input and output and processes from assembly instruction to binary output.
*/
int main (int argc, char **argv)  {
	if (argc != 3)  {printf ("info: assemble inputFile outputFile\n"); exit(1); }
	FILE *in = fopen(argv[1],"r");
	if (in == NULL) { printf ("error: unable to open input file\n"); exit(1); }
	FILE *out = fopen(argv[2],"wb");
	if (out == NULL) { printf ("error: unable to open output file\n"); exit(1); }

	char bytes[4], inputLine[100];
	while (!feof(in)) {
		if (NULL != fgets(inputLine,100,in)) {
			int outSize = assembleLine(inputLine,bytes);
			fwrite(bytes,outSize,1,out);
		}
	}
	fclose(in);
	fclose(out);
}

// Figure out from the first word which operation we are doing and do it...
int assembleLine(char *string, char *bytes) {
	getWords(string);

	//HALT instruction
	if (strcmp(words[0], "halt") == 0){
		return halt(bytes);
	}

	//ADD instruction
	if (strcmp(words[0] ,"add") == 0) {
		return add(bytes);
	}

	//AND instruction
	if (strcmp(words[0], "and") == 0) {
		return and(bytes);
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