#!/bin/bash

declare -a files=("symbol_table1" "symbol_table2" "symbol_table3")
num=0

for i in "${files[@]}"
do
	clear
	let "num++"
	echo Example Code $num:
	echo
	cat "./examples/$i"
	echo -----------------------------------------------
	echo
	./run.sh "./examples/$i" -p
	read -p "Press enter for next example"
done