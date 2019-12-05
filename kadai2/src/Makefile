compile:
	lex scanner.l
	cc lex.yy.c -ll -o scanner

test:
	for f in {ls ../samples}; do
		./scanner ../samples/{f}.p > ../samples_result/{f}.p.token
	done