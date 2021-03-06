#!/bin/bash

make

mkdir -p outputs
mkdir -p outputs/bin
mkdir -p outputs/text
mkdir -p outputs/process

SET=$(seq 1 26)
for index in $SET
do
	echo "Running Test Case $index"
	./assembler ./inputs/test$index.sia ./outputs/bin/result$index.bin >> ./outputs/process/case$index.txt
	od -x --endian=big ./outputs/bin/result$index.bin >> ./outputs/text/output$index.txt
done
