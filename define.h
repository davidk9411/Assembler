/** ICSI 404 Assignemnt 2
Assmbler for SIA instruction
Made by David Kim
Date:20200305
*/

//Function definition starts here

//Functions in main.c
int assembleLine(char *string, char *bytes);
int getRegister (char* string);
void getWords(char *string);

//Functions in instruction.c
int three_register_inst(char *bytes, int opcode);
int branch(char *bytes, int brcode);
int load_store(char *bytes, int opcode);
int stack_ops(char *bytes, int type);
int move(char *bytes);
int interrupt(char *bytes);