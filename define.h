int assembleLine(char *string, char *bytes);
int getRegister (char* string);
void getWords(char *string);

int halt(char *bytes);
int add(char *bytes);
int and(char *bytes);
int divide(char *bytes);
int multiply(char *bytes);
int subtract(char *bytes);
int or(char *bytes);
int branchifless(char *bytes);
int branchiflessequal(char *bytes);
int branchifequal(char *bytes);
int branchifnotequal(char *bytes);
int branchifgreater(char *bytes);
int branchifgreaterequal(char *bytes);
int call(char *bytes);
int jump(char *bytes);