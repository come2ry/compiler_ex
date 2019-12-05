compile:
	lex scanner.l
	cc lex.yy.c -ll -o scanner

test:
	./scanner ../samples/array.p > ../samples_result/array.p.token
