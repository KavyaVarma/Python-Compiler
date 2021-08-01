#!/bin/bash

yacc -d yfile.y
lex -l lfile.l
gcc y.tab.c lex.yy.c -ll -ly -o runner -lm
./runner<"$1"
