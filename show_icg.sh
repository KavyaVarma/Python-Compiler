#!/bin/bash

declare -a files=("expr" "for" "while2" "for_while")
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
	./run.sh "./examples/$i" -i
	read -p "Press enter for next example"
done