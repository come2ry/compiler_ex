CC = cc
YACC = yacc -d


compile: y.tab.c lex.yy.c symbol_table.o code_generator.o
	$(CC) y.tab.c lex.yy.c -lm -ll -o parser symbol_table.o code_generator.o -std=c99

lex.yy.c: scanner.l
	lex scanner.l

y.tab.c: parser.y
	$(YACC) parser.y

symbol_table.o: symbol_table.h symbol_table.c
	$(CC) -c symbol_table.c

code_generator.o: code_generator.h code_generator.c
	$(CC) -c code_generator.c