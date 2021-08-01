#!/bin/bash

parse=0
tree=0
icg=0
optimize=0
params=""
validity=0

while (( "$#" )); do
  case "$1" in
    -p)
      parse=1
      shift 1
      ;;
    -t)
      tree=1
      shift 1
      ;;
    -i)
      icg=1
      shift 1
      ;;
    -o)
      optimize=1
      shift 1
      ;;
     *)
      params="$params $1"
      shift 1
      ;;
  esac
done

eval set -- "$params"

if [ $parse -eq 0 -a $tree -eq 0 -a $icg -eq 0 ]
	then
	parse=1
	tree=1
	icg=1
fi

if [ $parse -eq 1 ]
	then
	echo Phase: Parsing
	echo
	echo Integer: 0 
	echo Float: 1
	echo String: 2
	echo Boolean: 3
	echo List: 4
	echo
	yacc -d -v -b ./SymbolTable/y ./SymbolTable/yfile.y
	lex -l -o ./SymbolTable/lex.yy.c ./SymbolTable/lfile.l
	gcc ./SymbolTable/y.tab.c ./SymbolTable/lex.yy.c -I ./SymbolTable -ll -ly -o ./SymbolTable/runner -lm
	./SymbolTable/runner<"$1"
	validity=$?
	if [ $validity -eq 0 ]
		then
		echo Parsing Completed Successfully.
		else
		echo Parsing Unsuccessful.
	fi
	echo
	echo -----------------------------------------------
fi

if [ $tree -eq 1 ]
	then
	if [ $validity -eq 0 ]
		then
		echo Phase: Syntax Tree Generation
		echo 
		yacc -d -v -b ./SyntaxTree/y ./SyntaxTree/yfile.y
		lex -l -o ./SyntaxTree/lex.yy.c ./SyntaxTree/lfile.l
		gcc ./SyntaxTree/y.tab.c ./SyntaxTree/lex.yy.c -I ./SyntaxTree -ll -ly -o ./SyntaxTree/runner -lm
		./SyntaxTree/runner<"$1"
		if [ $? -eq 0 ]
			then
			echo Syntax Tree Generation Completed Successfully.
			else
			echo Syntax Tree Generation Unsuccessful.
		fi
		echo 
		else
		echo Syntax Tree Generation Cannot Be Done Due To Parsing Error
	fi
	echo -----------------------------------------------
fi

if [ $icg -eq 1 ]
	then
	if [ $validity -eq 0 ]
		then
		echo Phase: Intermediate Code Generation
		echo 
		yacc -d -v -b ./ICG/y ./ICG/yfile.y
		lex -l -o ./ICG/lex.yy.c ./ICG/lfile.l
		gcc ./ICG/y.tab.c ./ICG/lex.yy.c -I ./ICG -ll -ly -o ./ICG/runner -lm
		./ICG/runner<"$1">"icg.txt"
		if [ $? -eq 0 ]
			then
			cat icg.txt
			echo Intermediate Code Generation Completed Successfully.
			else
			echo Intermediate Code Generation Unsuccessful.
		fi
		else
		echo Intermediate Code Generation Cannot Be Done Due To Parsing Error
	fi
	echo -----------------------------------------------
fi

if [ $optimize -eq 1 ]
	then
	if [ $icg -eq 0 ]
		then
		echo
		echo Optimization Cannot be Done without Intermediate Code Generation
	else
		echo 
		python codeoptimization_new.py < icg.txt > optimized.txt
		echo Optimization of ICG:
		cat optimized.txt
		echo Optimization Completed Successfully.
	fi
fi


