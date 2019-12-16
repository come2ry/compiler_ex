CC = cc
YACC = yacc -d


compile: y.tab.c lex.yy.c symbol_table.o
	$(CC) y.tab.c lex.yy.c -ll -o parser symbol_table.o

lex.yy.c: scanner.l
	lex scanner.l

y.tab.c: parser.y
	$(YACC) parser.y

symbol_table.o: symbol_table.h symbol_table.c
	$(CC) -c symbol_table.c