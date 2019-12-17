CC = cc
YACC = yacc -d


compile: y.tab.c lex.yy.c
	$(CC) y.tab.c lex.yy.c -ll -o parser

lex.yy.c: scanner.l
	lex scanner.l

y.tab.c: parser.y
	$(YACC) parser.y
