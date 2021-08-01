README

Code Implements A Mini Compiler for Python:
	- Parsing
	- Symbol Table
	- Abstract Synatx Tree
	- Intermedite Code Generation
	- Optimization (Constant Folding and Constant Propagation)

Usage:

Sample Test Cases:
	The sample test cases can be run using the bash files listed below:
	- show_symbol.sh
	- show_error.sh
	- show_ast.sh
	- show_icg.sh
	- show_optimization.sh


Running a Python Script:
	The bash file ./run.sh is used to run any give script.
	./run.sh [-p] [-t] [-i] [-o] sample.py
		-p: Parsing
		-t: Abstract Syntax Tree
		-i: Intermediate Code Generation
		-o: Code Optimization

	example: ./run.sh -p -t -i -o sample.py
