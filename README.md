# Assembler for Simple Instruction Architecture (SIA)
This is an assembler for SIA assembly language which takes SIA file as an input and assembles to binary file as an output.

Note: This is a Project #2 for Spring 2020 SUNY ALBANY ICSI 404 - Assembly Programming and Computer Organization.

## Compilation
Use the makefile to compile SIA assmebler
```bash
make (all)
make compile (Object-files only)
make output (Linking only)
make clear
```
For testing purposes use:
```bash
make test
make reset
```
## Usage
```bash
./assembler (inputfile) (output)
```
## Running the tests
Your output is a BINARY FILE of SIA machine language. 
Namely, this is a stream of numbers. You can verify your outputs in hex by using:
```bash
od -x (output)
```
If you want to use big-endian use:
```bash
od -x --endian=big (output)
```
### Devleopemnt Logs
Mar. 5th, 2020:

1.  **Initial Edition Completed**  Supported Instructions:

> ADD, AND, DIVIDE, HALT, MULTIPLY, OR, SUBTRACT, CALL, JUMP, LOAD, STORE, POP, PUSH, RETURN, MOVE, INTERRUPT, BRANCHIFSERIES

Mar. 10th, 2020:

1.  **Updates on instruction Handling**
2.  **Test Case, and testing script uploaded**

-   test.sh, reset.sh, print.sh

> _For  **WSL**  users,  **dos2unix**  is required_

-   before executing scripts, type "dos2unix test.sh" first

3.  **Minor fixes on bugs (BRANCHIFGREATEROREQUAL)**

Current State: Assignment 2 Submitted, Will create new repo for Assignment 3.

**makefile**  instructions

-   makefile is included with follwoing command:

1.  make compile: compile only, no executable file
2.  make output: generates executable file only

> make sure to compile first!!

3.  make test: runs executable with input files (input.sia)
4.  make reset: deletes output file only
5.  make clear: deletes executable, object files, and output file
