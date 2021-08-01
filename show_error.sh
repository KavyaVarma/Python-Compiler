#!/bin/bash

declare -a files=("error1" "error2" "error3" "error4" "error5" "error6")
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