all:
	yacc grammer.y -d	
	lex lexical.l
	gcc y.tab.c -ll -ly
	> inter.txt
	./a.out >> inter.txt
