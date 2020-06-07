Way to run the code is:
	$lex parser.l
	$yacc parser.y
	$gcc parser.tab.c -ll -ly
	$./a.out example.c
