# Assembler for Simple Instruction Architecture (SIA)
## Made by David Kim (SUNY at Albany)
## SP20 ICSI 404 Assignment 2 Assembler

### LOG:
<<<<<<< HEAD
Mar. 5th, 2020: 
1. Initial Edition Complete
Supported Instructions:
> ADD, AND, DIVIDE, HALT, MULTIPLY, OR, SUBTRACT, CALL, JUMP,
> LOAD, STORE, POP, PUSH, RETURN, MOVE, INTERRUPT,
> BRANCHIFSERIES
=======
Mar. 5th, 2020:
1.Initial Edition Complete
+ Supported Instructions:
>ADD, AND, DIVIDE, HALT, MULTIPLY, OR, SUBTRACT, CALL, JUMP,
>LOAD, STORE, POP, PUSH, RETURN, MOVE, INTERRUPT,
>BRANCHIFSERIES
>>>>>>> c2c2c697093ccb465cd3e9c60fafe406e4695dd2

Mar. 10th, 2020: 
1. Updates on instruction Handling
2. Test Case, and testing script uploaded
* test.sh, reset.sh, print.sh
> For WSL users, dos2unix is required
+ before executing scripts, type "dos2unix test.sh" first
3. Minor fixes on bugs (BRANCHIFGREATEROREQUAL)

How To?
* makefile is included with follwoing command:
1. make compile: compile only, no executable file
2. make output: generates executable file only
> make sure to compile first!!
3. make test: runs executable with input files (input.sia)
4. make reset: deletes output file only
5. make clear: deletes executable, object files, and output file
