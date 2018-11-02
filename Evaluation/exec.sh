flex lexer.l;
bison parser.y;
cc parser.tab.c lex.yy.c -ll;
clear;
./a.out;
