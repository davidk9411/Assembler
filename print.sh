#!/bin/bash


SET=$(seq 1 26)
for index in $SET
do
	echo "Printing Test Case $index"
	cat ./outputs/text/output$index.txt
done
