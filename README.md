# Assembler for Simple Instruction Architecture (SIA)
## Made by David Kim (SUNY at Albany)
## SP20 ICSI 404 Assignment 2 Assembler

### LOG:
Mar. 5th, 2020: Initial Edition Complete
> Instruction incorporates:
>>ADD, AND, DIVIDE, HALT, MULTIPLY, OR, SUBTRACT, CALL, JUMP,
>>LOAD, STORE, POP, PUSH, RETURN, MOVE, INTERRUPT,
>>BRANCHIFSERIES

How To?
* makefile is included with follwoing command:
1. make compile: compile only, no executable file
2. make output: generates executable file only
> make sure to compile first!!
3. make test: runs executable with input files (input.sia)
4. make reset: deletes output file only
5. make clear: deletes executable, object files, and output file