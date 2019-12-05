CC = cc
YACC = yacc -d


all:
	$(MAKE) yacc -s
	$(MAKE) compile -s

compile:
	lex scanner.l
	$(CC) y.tab.c lex.yy.c -ll -o parser

yacc:
	$(YACC) parser.y
