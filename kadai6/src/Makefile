CC = cc
YACC = yacc -d
BRANCH = kadai6
f = pl0a.p


compile: y.tab.c lex.yy.c symbol_table.o code_generator.o
	$(CC) y.tab.c lex.yy.c -lm -ll -o parser symbol_table.o code_generator.o

lex.yy.c: scanner.l
	lex scanner.l

y.tab.c: parser.y
	$(YACC) parser.y

symbol_table.o: symbol_table.h symbol_table.c
	$(CC) -c symbol_table.c

code_generator.o: code_generator.h code_generator.c
	$(CC) -c code_generator.c

clean:
	rm -f *.o y.tab.*

push:
	git add ~/Documents/ex3/.
	git commit -am "${BRANCH} tmp"
	git push origin ${BRANCH}

pull:
	git pull origin kadai5
	${MAKE}

run:
	./parser ~/Documents/ex3/hrs/${f}
	cat result.ll