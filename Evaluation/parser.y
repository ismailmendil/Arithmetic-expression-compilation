%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void yyerror(char* s);    

struct item{
    double value;
    struct item* next;

};

struct LinkedList{
    struct item* first;
    struct item* last;
};

struct tuple4{
   int op;
   int first_arg;
   int second_arg;
   int target;

};

struct entry {
    struct tuple4 content;
    struct entry* next;
};

struct tupleList{
    struct entry* first;
    struct entry* last;
};


int yylex (void);
double compute(int f_name, struct LinkedList *list);
struct LinkedList* createLinkedList();
void addItem(struct LinkedList* ll, double val);
void concatLL(struct LinkedList *ll1, struct LinkedList *ll2);
struct LinkedList* addItemInFront(double val, struct LinkedList *ll);

/*API for IR 4-tuple*/
struct tupleList* createTupleList();
struct entry* createEntry(int op, int first_arg, int second_arg, int target);
void addEntry(struct tupleList* list, struct entry *itm);


/*Functions that are supported*/
double sum(struct item *itm);
double mean(struct item *itm);
double var(struct item *itm);
double product(struct item *itm);
 
int line_nb = 0;
%}

%union {
    struct LinkedList* ll;
    double d;
    int n;
}

%start INPUT
%token <d> NUMBER 
%token <char> PLUS MINUS TIMES DIV OPENING_PARENTHESIS CLOSING_PARENTHESIS STOP COMMA  ERROR
%token <int> SUM MEAN VAR PRODUCT
%left PLUS MINUS
%left TIMES DIV
%nonassoc SIGN

%type <d> INPUT Z E T F func
%type <n> func_name
%type <ll>  arg_list

%%
INPUT: STOP {printf("%d - Input: ", line_nb++);}
     | Z INPUT ;
     ;

Z:E STOP {
                printf("%d - Output: %f.\n\n", line_nb++, $1);
                printf("%d - Input: ", line_nb++);
         }
 | STOP {$$ = STOP;};
 ;

E   : E PLUS T {$$ = $1 + $3;}  
    | E MINUS T {$$ = $1 - $3;} 
    | T
    
    | E PLUS T error { yyerror("Missing operand."); }    
    | E PLUS error { yyerror("Missing operand.");} 
    | E MINUS error { yyerror("Missing operand.");} 
    | T error { yyerror("Missing operator."); }  
    
    ;
T:  T TIMES F {$$ = $1 * $3;}
    | T DIV F {$$ = $1 / $3;}
    |  F {$$ = $1;}

    |  T TIMES F error { yyerror("Missing operand."); }
    |  T DIV F error { yyerror("Missing operand."); }
    |  T TIMES error { yyerror("Missing operand."); }        
    |  error TIMES T { yyerror("Missing operand."); }  
    |  T DIV error   { yyerror("Missing operand."); }        
    |  error DIV T   { yyerror("Missing operand."); } 
    
    ;
F:  OPENING_PARENTHESIS E CLOSING_PARENTHESIS {$$ = $2;}
    | MINUS F %prec SIGN {$$ = $2*(-1); }
    | PLUS F %prec SIGN {$$ = $2; }
    | NUMBER  {$$ = yylval.d;}
    | func   { $$ = $1;}
         
    | error CLOSING_PARENTHESIS { yyerror("Unbalanced number of parentheses.");  }
    | OPENING_PARENTHESIS error { yyerror("Unbalanced number of parentheses.");  }
    ;



func:func_name OPENING_PARENTHESIS arg_list CLOSING_PARENTHESIS { $$ = compute($1, $3);};
    
    
    | func_name error arg_list CLOSING_PARENTHESIS { yyerror("Unbalanced number of parentheses.");}
    | func_name OPENING_PARENTHESIS arg_list error { yyerror("Unbalanced number of parentheses.");}
    | func_name OPENING_PARENTHESIS error CLOSING_PARENTHESIS { yyerror("Missing separator.");}
    | error OPENING_PARENTHESIS arg_list CLOSING_PARENTHESIS { yyerror("Function does not exist.");}
    ;
func_name : SUM { $$ = SUM; }
          | MEAN { $$ = MEAN;}
          | VAR { $$ = VAR;}
          ;
arg_list : E COMMA arg_list { $$ = addItemInFront($1, $3);}
    
        | E {  $$ = createLinkedList($1); }
        ;
%%

void yyerror(char* s) 
{ 
    if(strcmp(s, "syntax error"))
    { 
        printf("%d - Syntax Error: %s\n", line_nb++,s);
        yyclearin; /* discard lookahead */
        
        //printf("%d - Input: ", line_nb++);
    }   
};

double compute(int f_name, struct LinkedList *list)
{   
    struct item* itm = (struct item *)list->first;

    switch(f_name)
    {
        case SUM     : return sum(itm);
        case MEAN    : return mean(itm);
        case VAR     : return var(itm);
        case PRODUCT : return product(itm);
    }
}

double sum(struct item *itm)
{
    double result = 0;
    while(itm != NULL) {result += itm->value; itm = itm->next;}
    return result;
}
double product(struct item * itm)
{
    double result = 1;
    while(itm != NULL) {result *= itm->value; itm = itm->next;}
    return result;
}
double mean(struct item * itm)
{
    double result = 0;
    int count = 0;

    while(itm != NULL) {result += itm->value; count++; itm = itm->next;}
    return result /= count;
}

double var(struct item * itm)
{
    double inter1 = 0;
    double inter2 = 0; 
    int count = 0;

    while(itm != NULL)
    {
        inter1 += itm->value; 
        inter2 += (itm->value) * (itm->value);
        count++;
        itm = itm->next;
    }
    inter1 /= count;
    inter1 *= inter1;
    inter2 /= count;
    return inter2 - inter1;
}

struct LinkedList* createLinkedList(double val)
{
    struct LinkedList* ll = (struct LinkedList *) malloc(sizeof(struct LinkedList));
    struct item* itm = malloc(sizeof(struct item));
    itm->value = val;
    itm->next = NULL;
    ll->first = itm;
    ll->last = itm;
    return ll;
}

/*
void addItem(struct LinkedList *ll, double val)
{
    printf("Here is addItem before malloc\n");
    struct item * itm_inter = NULL;
    struct item* itm = (struct item *)  malloc(sizeof(struct item));
     printf("Here is addItem after malloc\n");
    
    itm->value = val;
    itm->next = NULL;
    printf("Here is addItem itm initialized\n");
     printf("Here is addItem itm initialized 2\n");
     if (ll == NULL){
          printf("Here is addItem ll is NULL\n");
     }
    if((ll->first) != NULL)
    {
     
        printf("Here is addItem if \n");
        itm_inter =  ll->last; 
        itm_inter->next = itm;
        ll->last = itm;
    } else
    {
            printf("Here is addItem else \n");
        ll->first = itm;
        ll->last = itm;
    }

}
*/

struct LinkedList* addItemInFront(double val, struct LinkedList *ll)
{

    struct item* itm = (struct item *)  malloc(sizeof(struct item));
    itm->value = val;
    itm->next = ll->first;
    
    ll->first = itm;
    return ll;

}/*
void concatLL(struct LinkedList* ll1, struct LinkedList *ll2)
{
    ll1->last = ll2->first;

}*/

struct tupleList* createTupleList()
{
    struct tupleList* tlist = (struct tupleList*)malloc(sizeof(struct tupleList));
    return tlist;
}
struct entry* createEntry(int op, int first_arg, int second_arg, int target)
{
    struct entry* itm = (struct entry*)malloc(sizeof(struct entry));
    (itm->content).op         = op;
    (itm->content).first_arg  = first_arg;
    (itm->content).second_arg = second_arg;
    (itm->content).target     = target;
    itm->next = NULL;
    
    return itm;
}
void addEntry(struct tupleList* list, struct entry *itm)
{
     if(list->first == NULL)
     {
         list->first = itm;
         list->last = itm;
     } else
     {
         (list->last)->next = itm;
         list->last = itm;
     }
}

int main(void)
{
    printf("%d - Input: ", line_nb++);
    yyparse();
    return 0;
}
