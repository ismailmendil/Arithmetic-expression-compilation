%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "parser.tab.h"

    void yyerror(char *s);
    int wrapp(void);
    extern int line_nb;
    
%}

identifier [a-zA-Z][0-9a-zA-Z]*
%%

[\t ] ;
\+  { return PLUS; }
-  { return MINUS; }
\/  { return DIV; }
\*  { return TIMES; }
\( return OPENING_PARENTHESIS;
\) return CLOSING_PARENTHESIS;

[0-9]+(\.[0-9]+)? { yylval.n = atoi(yytext); return IDENT; }
, return COMMA;
somme   return SUM;
moyenne return MEAN;
var     return VAR;
produit return PRODUCT;
racine  return SQRT;
min  return MIN;
max  return MAX;
ecart-type return DEVIATION;
[a-zA-Z] { yylval.c = yytext[0]; return IDENT;}
\n {return STOP; fflush(stdin);}

. { 
    printf("%d - Lexical Error: Token non-recognized.\n", line_nb++);
    //fflush(stdin);
    return ERROR;
  }

%%
int wrapp(void) { return 1; }

