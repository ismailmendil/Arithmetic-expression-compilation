%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void yyerror(char* s);    

struct item{
    int value;
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
    struct tuple4* content;
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
struct LinkedList* addItemInFront(int val, struct LinkedList *ll);
int ll_len(struct item* ll);

/*API for IR 4-tuple*/
struct tupleList* createTupleList();
struct entry* createEntry(int op, int first_arg, int second_arg, int target);
void addEntry(struct tupleList* list, struct entry *itm);
void displayTuples(struct tupleList *tlist);


/*Functions that are supported*/
double sum(struct item *itm);
double mean(struct item *itm);
double var(struct item *itm);
double product(struct item *itm);
 
 
 /*Produce RI*/
int produce_function(int f_name, struct LinkedList* ll);
int produce_mean(struct item * itm);
int produce_sum(struct item * itm);
int produce_sqrt(int number);
int produce_var(struct item * itm);
int produce_deviation(struct item * itm);
int produce_min(struct item * itm);
int produce_max(struct item * itm);


int line_nb = 0;
int temp = 300;
int address = 0;
struct tupleList* tlist = NULL;
const char * path = "ri_output";
FILE * output_file = NULL;



%}

%union {
    struct LinkedList* ll; 
    double d;
    int n;
    char c;
}

%start INPUT
%token <d> NUMBER 
%token <char> PLUS MINUS TIMES DIV SIGN OPENING_PARENTHESIS CLOSING_PARENTHESIS STOP COMMA  ERROR
%token <int> SUM MEAN VAR PRODUCT SQRT MIN MAX DEVIATION
%token <c> IDENT
%left PLUS MINUS
%left TIMES DIV
%nonassoc SIGN


%type <n> INPUT Z E T F func
%type <n> func_name
%type <ll>  arg_list

%%
INPUT: STOP {printf("%2d - Input: ", line_nb++);}
     | Z INPUT ;
     ;

Z:E STOP {
                fprintf(output_file, "%2d - The Intermidiate Representation of the input is:\n", line_nb++);
                displayTuples(tlist);
                tlist = createTupleList();
                temp = 300;
                printf("\n\n");
                fprintf(stdout, "%2d - Input: ", line_nb++);
         }
 | STOP {$$ = STOP;}
 ;

E   : E PLUS T {   
                    struct entry* entry = createEntry('+', $1, $3, temp++);                 
                    addEntry(tlist, entry);
 		    $$ = temp - 1; 

                                 
                }  
    | E MINUS T {   $$ = temp; 
                    struct entry* entry = createEntry('-', $1, $3, temp++);
                    addEntry(tlist, entry);
                } 
    | T
    
    
    | E PLUS T error { yyerror("Missing operand."); }    
    | E PLUS error { yyerror("Missing operand.");} 
    | E MINUS error { yyerror("Missing operand.");} 
    | T error { yyerror("Missing operator."); }  
    
    ;
T:  T TIMES F {
                    $$ = temp; 
                    
                    struct entry* entry = createEntry('*', $1, $3, temp++ );
                    addEntry(tlist, entry);
                    
              }
    | T DIV F {
                    $$ = temp; 
                    struct entry* entry = createEntry('/', $1, $3, temp++);
                    addEntry(tlist, entry);
              }
    |  F {$$ = $1;}

    |  T TIMES F error { yyerror("Missing operand."); }
    |  T DIV F error { yyerror("Missing operand."); }
    |  T TIMES error { yyerror("Missing operand."); }        
    |  error TIMES T { yyerror("Missing operand."); }  
    |  T DIV error   { yyerror("Missing operand."); }        
    |  error DIV T   { yyerror("Missing operand."); } 
    
    ;
F:  OPENING_PARENTHESIS E CLOSING_PARENTHESIS {$$ = $2; }
    | MINUS F %prec SIGN {
			
				struct entry* entry = createEntry('I', $2, '_', temp++);
                    		addEntry(tlist, entry);
				$$ = temp - 1;
			 }
    | PLUS F %prec SIGN {$$ = $2; }
    | NUMBER {$$ = yylval.d;}
    | func  {$$ = $1;}
    | IDENT { $$ = yylval.c;}
         
    | error CLOSING_PARENTHESIS { yyerror("Unbalanced number of parentheses.");  }
    | OPENING_PARENTHESIS error { yyerror("Unbalanced number of parentheses.");  }
    ;
func:func_name OPENING_PARENTHESIS arg_list CLOSING_PARENTHESIS { $$ = produce_function($1, $3);}
    | SQRT  OPENING_PARENTHESIS E CLOSING_PARENTHESIS { $$ = produce_sqrt((int)$3);}
    	
    
    
    | func_name error arg_list CLOSING_PARENTHESIS { yyerror("Unbalanced number of parentheses.");}
    | func_name OPENING_PARENTHESIS arg_list error { yyerror("Unbalanced number of parentheses.");}
    | func_name OPENING_PARENTHESIS error CLOSING_PARENTHESIS { yyerror("Missing separator.");}
    | error OPENING_PARENTHESIS arg_list CLOSING_PARENTHESIS { yyerror("Function does not exist.");}
    ;

func_name : SUM  { $$ = SUM; }
          | MEAN { $$ = MEAN;}
          | VAR  { $$ = VAR;}
          | MIN  { $$ = MIN;}
          | MAX  { $$ = MAX;}
	  | DEVIATION { $$ = DEVIATION;}
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
        
        //printf("%2d - Input: ", line_nb++);
    }   
};
/*
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
*/
int produce_function(int f_name, struct LinkedList *list)
{   
    struct item* itm = (struct item *)list->first;

    switch(f_name)
    {
      case MEAN    : return produce_mean(itm);
      case SUM	   : return produce_sum(itm);
      case VAR     : return produce_var(itm);
      case MIN     : return produce_min(itm);
      case MAX     : return produce_max(itm);
      case DEVIATION : return produce_deviation(itm);
    }
}

/*
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
*/
int produce_mean(struct item * itm)
{

    struct entry* entry = NULL;
    temp ++;
    temp ++;
        
    entry = createEntry('M', '0', '_', temp - 2);
    addEntry(tlist, entry);

    entry = createEntry('M',  '0', '_', temp - 1);  
    addEntry(tlist, entry);
    while(itm != NULL) { 
        
          entry = createEntry('+', itm->value, temp - 1, temp - 1);
          addEntry(tlist, entry);

          entry = createEntry('+',  temp - 2, '1', temp - 2);  
          addEntry(tlist, entry);
          itm = itm->next;
          
         
    }
   
      entry = createEntry('/', temp - 2, temp - 1, temp - 2);      
      addEntry(tlist, entry);   
    return temp - 2;
}

int produce_sum(struct item * itm)
{

    struct entry* entry = NULL;
    temp ++;
    entry = createEntry('M', '0', '_', temp - 1);
    addEntry(tlist, entry);
    while(itm != NULL) { 
        
          entry = createEntry('+', itm->value, temp - 1, temp - 1);
          addEntry(tlist, entry);

          itm = itm->next;
          
         
    }
    return temp - 1;
}

int produce_var(struct item * itm)
{

    struct entry* entry = NULL;
    temp ++;
    temp ++;
    temp ++;
    temp++;
           
    entry = createEntry('M', '0', '_', temp - 4);
    addEntry(tlist, entry);           
    entry = createEntry('M', '0', '_', temp - 3);
    addEntry(tlist, entry);   
    entry = createEntry('M', '0', '_', temp - 2);
    addEntry(tlist, entry);
    entry = createEntry('M',  '0', '_', temp - 1);  
    addEntry(tlist, entry);

    while(itm != NULL) { 
       
          entry = createEntry('*', itm->value, itm->value, temp - 4);
          addEntry(tlist, entry);

          entry = createEntry('+',  temp - 3, temp - 4, temp - 3);  
          addEntry(tlist, entry);

          entry = createEntry('+',  temp - 2, itm->value, temp - 2);  
          addEntry(tlist, entry);
          
  	  entry = createEntry('+',  temp - 1, '1', temp-1);  
          addEntry(tlist, entry);
          itm = itm->next;
          
          
         
    }
   
      entry = createEntry('*', temp - 2, temp - 2, temp - 2);      
      addEntry(tlist, entry);   
      entry = createEntry('/', temp - 2, temp - 1, temp - 2);      
      addEntry(tlist, entry); 
      entry = createEntry('/', temp - 3, temp - 1, temp - 3);      
      addEntry(tlist, entry); 
      entry = createEntry('-', temp - 3, temp - 2, temp - 2);      
      addEntry(tlist, entry);     
    return temp - 2;
}


int produce_sqrt(int number)
{	
    struct entry* entry = NULL;

    // will need 3 temps to compute to sqrt of 'number'. Will use the Heron algorithm, in fact we get quickly a very good apporoximation of 	  sqrt.
    temp++;
    temp++;
    temp++;
    // intialize Un and Un+1 represented respectively by (temp-3) and (temp-2) 
    entry = createEntry('M', '1', '_', temp - 3);
    addEntry(tlist, entry);
    entry = createEntry('M', '1', '_', temp - 2);
    addEntry(tlist, entry);
    entry = createEntry('M', '1', '_', temp - 1);
    addEntry(tlist, entry);
    entry = createEntry('C', temp - 1, '6', '_');
    addEntry(tlist, entry);
          entry = createEntry('G',  '_', '_', address + 7);  
    addEntry(tlist, entry);
    
    	
	entry = createEntry('/', number, temp - 3, temp - 2);
    	addEntry(tlist, entry);
    	entry = createEntry('+', temp - 3, temp - 2, temp - 2);
    	addEntry(tlist, entry);	
    	entry = createEntry('/', temp - 2, '2', temp - 2);
    	addEntry(tlist, entry);	
    	entry = createEntry('M', temp - 2, '_', temp - 3);
	addEntry(tlist, entry);
	entry = createEntry('+', temp - 1, '1', temp - 1);
	addEntry(tlist, entry);
          entry = createEntry('J',  '_', '_', address -7);  
	addEntry(tlist, entry);
    	
    return temp - 3;
}


int produce_min(struct item * itm)
{
    struct entry* entry = NULL;
    temp++;
           
    if(itm)
    {
	entry = createEntry('M',  itm->value, '_', temp - 1);  
    	addEntry(tlist, entry);
        itm = itm->next;
    } 


    while(itm != NULL) { 
       
          entry = createEntry('C', temp - 1, itm->value, '_');
          addEntry(tlist, entry);

          entry = createEntry('L',  '_', '_', address + 2);  
          addEntry(tlist, entry);

          entry = createEntry('M',  itm->value,  '_', temp - 1);  
          addEntry(tlist, entry);

          itm = itm->next;
          
          
         
    }
       
    return temp - 1;
}

int produce_max(struct item * itm)
{
    struct entry* entry = NULL;
    temp++;
           
    if(itm)
    {
	entry = createEntry('M',  itm->value, '_', temp - 1);  
    	addEntry(tlist, entry);
        itm = itm->next;
    } 


    while(itm != NULL) { 
       
          entry = createEntry('C', temp - 1, itm->value, '_');
          addEntry(tlist, entry);

          entry = createEntry('G',  '_', '_', address + 2);  
          addEntry(tlist, entry);

          entry = createEntry('M',  itm->value,  '_', temp - 1);  
          addEntry(tlist, entry);

          itm = itm->next;
          
          
         
    }
       
    return temp - 1;
}
int produce_deviation(struct item * itm)
{
  return produce_sqrt(produce_var(itm));   
		
}



struct LinkedList* createLinkedList(int val)
{

    struct LinkedList* ll = (struct LinkedList *) malloc(sizeof(struct LinkedList));
    struct item* itm = malloc(sizeof(struct item));
    itm->value = val;
    itm->next = NULL;
    ll->first = itm;
    ll->last = itm;
    return ll;
}


struct LinkedList* addItemInFront(int val, struct LinkedList *ll)
{

    struct item* itm = (struct item *)  malloc(sizeof(struct item));
    itm->value = val;
    itm->next = ll->first;
    
    ll->first = itm;
    return ll;

}
int ll_len(struct item* itm)
{
 int count = 0;

 while(itm != NULL)
 {
 	count++;
	itm = itm->next;
 }
 return count;
}

struct tupleList* createTupleList()
{
    struct tupleList* tlist = (struct tupleList*)malloc(sizeof(struct tupleList));
    tlist->first = NULL;
    tlist->last =NULL;
    return tlist;
}
struct entry* createEntry(int op, int first_arg, int second_arg, int target)
{
    struct entry* itm = (struct entry*)malloc(sizeof(struct entry));
    itm->content = (struct tuple4*) malloc(sizeof(struct tuple4));
    (itm->content)->op         = op;
    (itm->content)->first_arg  = first_arg;
    (itm->content)->second_arg = second_arg;
    (itm->content)->target     = target;
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
     address++;
}

void displayTuples(struct tupleList *tlist)
{

    int local_address = 0;
    struct entry* itm = NULL;
    struct tuple4* tuple = (struct tuple4*) malloc(sizeof(struct tuple4));
    itm = tlist->first;
    


    while(itm)
    {
        
        tuple = itm->content;
        fprintf(output_file,"\n");
        fprintf(output_file, "\t------------------------------------");
        fprintf(output_file, "\n\t%2d : %c ", local_address++,tuple->op);
        if(tuple->first_arg < 300)
        {
   	   fprintf(output_file, "%7c ", tuple->first_arg);

        } else 
        {
            fprintf(output_file, "   tmp%d ", tuple->first_arg%300);
        }

         if(tuple->second_arg < 300)
        {
            fprintf(output_file, "%7c ", tuple->second_arg);
        } else 
        {
            fprintf(output_file, "    tmp%d ", tuple->second_arg%300);
        }

         if(tuple->target < 300)
        {
           if(tuple->op != 'J' && tuple->op != 'G' && tuple->op != 'L' && tuple->op != 'Z')
	   {
 	     fprintf(output_file, "%7c ",tuple->target);
	   }else 
	   {
             fprintf(output_file, "%7d ", tuple->target%300);
	   }
        } else 
        {
            fprintf(output_file, "    tmp%d ", tuple->target%300);
            
        }
        itm = itm->next;
    }
    address = 0;
    if(output_file != stdout)
    {
	    fclose(output_file);
    }	
}


int main(void)
{
    output_file = stdout;//fopen(path, "w");   
    tlist = createTupleList();
    printf("%2d - Input: ", line_nb++);
    yyparse();
    return 0;
}
