CC = cc
YACC = yacc -d


compile: lex.yy.c symbol_table.o code_generator.o y.tab.c
	$(CC) y.tab.c lex.yy.c -ll -o parser symbol_table.o code_generator.o

lex.yy.c: scanner.l
	lex scanner.l

symbol_table.o: symbol_table.h symbol_table.c
	$(CC) -c symbol_table.c

code_generator.o: code_generator.h code_generator.c
	$(CC) -c code_generator.c

y.tab.c: parser.y
	$(YACC) parser.y