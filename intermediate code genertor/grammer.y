%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count=1; //count for number of temporary variables
char* code[1000];
int next_inst=1;
char fill_label[10];
char* case_inst[20][2];  // used in switch case 
int no_of_cases=0;       // no of cases in switch case
int no_of_defaults=0;       // no of defaults in switch case , error if more than 1
char* identifiers[100];
int no_of_identifiers=0;

struct list
{
	int inst_no;
	struct list *next;
};


struct list * makelist(int next_inst);
struct list * merge(struct list * l1,struct list * l2);
void backpatch(struct list* l,int target_inst);
char* new_temp();
void print_code();
void declare(char* id);
int isdeclared(char* id);

%}

%union
{
	union 
	{
	
		int inst;
		char* addr;
		struct list* nextlist;	
		struct
		{
			struct list* truelist;
			struct list* falselist;
		};
	}
	info;
}

%start start
%left ','
%left MUL_ASSIGN DIV_ASSIGN
%left PLUS_ASSIGN MINUS_ASSIGN
%left '=' 
%left LOGICAL_OR
%left LOGICAL_AND
%left '|'
%left '^'
%left '&'
%left EQUAL NOT_EQUAL
%left '>' GREATER_OR_EQUAL
%left '<' LESS_OR_EQUAL
%left '+' '-'
%left '*' '/' '%'
%right '!' '~'
%nonassoc UMINUS
%right '@'
%left '(' ')'
%nonassoc IDENTIFER

%type <info> start expr assignment B S M N L cases list
%token <info> INTEGER IDENTIFIER WHILE IF ELSE TRUE FALSE MAIN PLUS_ASSIGN MINUS_ASSIGN MUL_ASSIGN DIV_ASSIGN SWITCH CASE DEFAULT BREAK INT LOGICAL_OR LOGICAL_AND EQUAL LESS_OR_EQUAL GREATER_OR_EQUAL NOT_EQUAL

%%
start		:	MAIN S M
			{
				backpatch($2.nextlist,$3.inst);
				print_code();
			}
		;


S		:	IF '(' B ')' M S
			{
				backpatch($3.truelist,$5.inst);
				$$.nextlist=merge($3.falselist,$6.nextlist);
			}
			
		|	IF '(' B ')' M S ELSE N M S
			{
				backpatch($3.truelist,$5.inst);
				backpatch($3.falselist,$9.inst);
				struct list * temp = merge($8.nextlist,$10.nextlist);
				$$.nextlist=merge(temp,$6.nextlist);
			}
		
		
		|	WHILE M '(' B ')' M S
			{
				backpatch($7.nextlist,$2.inst);
				backpatch($4.truelist,$6.inst);
				
				$$.nextlist=$4.falselist;
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s","goto ");
	
				sprintf(fill_label,"%d",$2.inst);
				strcat(code[next_inst],fill_label);
				
				next_inst++;
			}
		
		
		|	SWITCH '(' expr ')' N '{' cases '}' M
			{
			
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s","goto ");
				next_inst++;
			
				backpatch($5.nextlist,next_inst);
			
			
				int i;
				for(i=1;i<=no_of_cases;i++)
				{
					code[next_inst]=(char*)malloc(50);
					if(i!=no_of_cases||case_inst[i][0]!=NULL)
					sprintf(code[next_inst],"%s%s%s%s%s%s","if ",$3.addr,"==",case_inst[i][0]," goto ",case_inst[i][1]);
					
					else
					sprintf(code[next_inst],"%s%s","goto ",case_inst[i][1]);
					
					next_inst++;
				}
				
				backpatch($7.nextlist,next_inst);
	
				sprintf(fill_label,"%d",next_inst);
				strcat(code[$9.inst],fill_label);
				no_of_cases=0;
				no_of_defaults=0;
				$$.nextlist=NULL;
			}
		
		
		|	'{' L '}'
			{
				$$.nextlist=$2.nextlist;
			}
			
		|	'{'  '}'
			{
				$$.nextlist=NULL;
			}	
			
		|	assignment
			{
				$$.nextlist=NULL;
			}		
		
		|	BREAK ';'
			{
				$$.nextlist=makelist(next_inst);
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s","goto ");
				next_inst++;
			}
		
		|	INT list ';' 
			{
				$$.nextlist=NULL;
			}
		
		
		;	


list		:	list ',' IDENTIFIER 
			{
			declare($3.addr);
			}	
		
		|	IDENTIFIER	
			{
			declare($1.addr);
			}
		
		
		|	list ',' IDENTIFIER '=' expr
			{
			declare($3.addr);
			}	
		
		|	IDENTIFIER '=' expr	
		{
			declare($1.addr);
		}

cases		:	cases CASE expr ':' M S
			{
				no_of_cases++;
				case_inst[no_of_cases][0]=$3.addr;
				sprintf(fill_label,"%d",$5.inst);
				case_inst[no_of_cases][1]=(char*)malloc(5);
				strcpy(case_inst[no_of_cases][1],fill_label);
				$$.nextlist=merge($1.nextlist,$6.nextlist);
	
			}
			
		|	cases DEFAULT ':' M S
			{
				no_of_cases++;
				no_of_defaults++;
				
				if(no_of_defaults==2)
				{
					printf("\nerror more than 1 defaults \n");
					exit(1);
				}
				
				case_inst[no_of_cases][0]=NULL;
				sprintf(fill_label,"%d",$4.inst);
				case_inst[no_of_cases][1]=(char*)malloc(5);
				strcpy(case_inst[no_of_cases][1],fill_label);
				$$.nextlist=merge($1.nextlist,$5.nextlist);
			}
			
		|	CASE expr ':' M S
			{
				no_of_cases++;
				case_inst[no_of_cases][0]=$2.addr;
				sprintf(fill_label,"%d",$4.inst);
				case_inst[no_of_cases][1]=(char*)malloc(5);
				strcpy(case_inst[no_of_cases][1],fill_label);
				$$.nextlist=$5.nextlist;
			}	

		
L		:	L M S
			{	
				backpatch($1.nextlist,$2.inst);
				$$.nextlist=$3.nextlist;
				
			}
		
		|	S
			{	
				$$.nextlist=$1.nextlist;
				
			}

		;
		
B		:	B LOGICAL_OR M B
			{
				backpatch($1.falselist,$3.inst);
				$$.truelist=merge($1.truelist,$4.truelist);
				$$.falselist=$4.falselist;
			}
		
		|	B LOGICAL_AND M B
			{
				backpatch($1.truelist,$3.inst);
				$$.falselist=merge($1.falselist,$4.falselist);
				$$.truelist=$4.truelist;
			}
		
		|	'!' B
			{
				$$.truelist = $2.falselist;
				$$.falselist = $2.truelist;
			}
			
		|	'(' B ')'
			{
				$$.truelist = $2.truelist;
				$$.falselist = $2.falselist;
			}
			
		|	expr EQUAL expr
			{
				$$.truelist=makelist(next_inst);
				$$.falselist=makelist(next_inst+1);
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%s%s%s%s","if ",$1.addr,"==",$3.addr," goto ");
				next_inst++;	
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s","goto ");
				next_inst++;					
			}
			
			
		|	expr NOT_EQUAL expr
			{
				$$.truelist=makelist(next_inst);
				$$.falselist=makelist(next_inst+1);
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%s%s%s%s","if ",$1.addr,"!=",$3.addr," goto ");
				next_inst++;	
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s","goto ");
				next_inst++;					
			}
			
			
			
			
		|	expr GREATER_OR_EQUAL expr
			{
				$$.truelist=makelist(next_inst);
				$$.falselist=makelist(next_inst+1);
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%s%s%s%s","if ",$1.addr,">=",$3.addr," goto ");
				next_inst++;	
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s","goto ");
				next_inst++;					
			}
			
			
			
			
		|	expr LESS_OR_EQUAL expr
			{
				$$.truelist=makelist(next_inst);
				$$.falselist=makelist(next_inst+1);
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%s%s%s%s","if ",$1.addr,"<=",$3.addr," goto ");
				next_inst++;	
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s","goto ");
				next_inst++;					
			}

		|	expr '<' expr
			{
				$$.truelist=makelist(next_inst);
				$$.falselist=makelist(next_inst+1);
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%s%s%s%s","if ",$1.addr,"<",$3.addr," goto ");
				next_inst++;	
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s","goto ");
				next_inst++;					
			}


		|	expr '>' expr
			{
				$$.truelist=makelist(next_inst);
				$$.falselist=makelist(next_inst+1);
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%s%s%s%s","if ",$1.addr,">",$3.addr," goto ");
				next_inst++;	
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s","goto ");
				next_inst++;					
			}



		|	TRUE
			{	
				$$.truelist=makelist(next_inst);
				code[next_inst]=(char*)malloc(50);
				

				sprintf(code[next_inst],"%s","goto ");
				next_inst++;
			}
			
		|	FALSE
			{	
				$$.falselist=makelist(next_inst);
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s","goto ");
				next_inst++;
			}
		
		;
		
M		:	
			{
				$$.inst=next_inst;
			}
		;
		
N		:	
			{
				$$.nextlist=makelist(next_inst);
				code[next_inst]=(char*)malloc(50);
				

				sprintf(code[next_inst],"%s","goto ");
				next_inst++;
			}
		;

assignment	:	IDENTIFIER '=' expr ';' 
			{
				if(!isdeclared($1.addr))
				{
					printf("\n%s not declared\n",$1.addr);
				}
				
				code[next_inst]=(char*)malloc(50);				

				sprintf(code[next_inst],"%s%c%s",$1.addr,'=',$3.addr);
				next_inst++;
			}
			
		|	IDENTIFIER PLUS_ASSIGN expr ';'		
			{
				if(!isdeclared($1.addr))
				{
					printf("\n%s not declared\n",$1.addr);
				}
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",$1.addr,'=',$1.addr,'+',$3.addr);
				next_inst++;
			}
			
		|	IDENTIFIER MINUS_ASSIGN expr ';'		
			{
				if(!isdeclared($1.addr))
				{
					printf("\n%s not declared\n",$1.addr);
				}
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",$1.addr,'=',$1.addr,'-',$3.addr);
				next_inst++;
			}
			
		|	IDENTIFIER MUL_ASSIGN expr ';'		
			{
				if(!isdeclared($1.addr))
				{
					printf("\n%s not declared\n",$1.addr);
				}
				
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",$1.addr,'=',$1.addr,'*',$3.addr);
				next_inst++;
			}
			
		|	IDENTIFIER DIV_ASSIGN expr ';'		
			{
				if(!isdeclared($1.addr))
				{
					printf("\n%s not declared\n",$1.addr);
				}
				
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",$1.addr,'=',$1.addr,'/',$3.addr);
				next_inst++;
			}
			
		;


expr		:	expr '+' expr		
			{
				$$.addr=malloc(5);
				strcpy($$.addr,new_temp());

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",$$.addr,'=',$1.addr,'+',$3.addr);
				next_inst++;
			}
		|	expr '-' expr		
			{
				$$.addr=malloc(5);
				strcpy($$.addr,new_temp());

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",$$.addr,'=',$1.addr,'-',$3.addr);
				next_inst++;
			}
		|	expr '*' expr		
			{
				$$.addr=malloc(5);
				strcpy($$.addr,new_temp());

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",$$.addr,'=',$1.addr,'*',$3.addr);
				next_inst++;
			}
		|	expr '/' expr		
			{
				$$.addr=malloc(5);
				strcpy($$.addr,new_temp());

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",$$.addr,'=',$1.addr,'/',$3.addr);
				next_inst++;
			}
			
		|	expr '%' expr		
			{
				$$.addr=malloc(5);
				strcpy($$.addr,new_temp());

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",$$.addr,'=',$1.addr,'%',$3.addr);
				next_inst++;
			}
			
			
		|	expr '@' expr		
			{
				$$.addr=malloc(5);
				strcpy($$.addr,new_temp());
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",$$.addr,'=',$1.addr,'@',$3.addr);
				next_inst++;
			}
			
		|	expr '&' expr		
			{
				$$.addr=malloc(5);
				strcpy($$.addr,new_temp());

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",$$.addr,'=',$1.addr,'&',$3.addr);
				next_inst++;
			}
			
		|	expr '^' expr		
			{
				$$.addr=malloc(5);
				strcpy($$.addr,new_temp());

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",$$.addr,'=',$1.addr,'^',$3.addr);
				next_inst++;
			}		
		
		|	expr '|' expr		
			{
				$$.addr=malloc(5);
				strcpy($$.addr,new_temp());
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",$$.addr,'=',$1.addr,'|',$3.addr);
				next_inst++;
			}
			
			
		|	'(' expr ')'		
			{
				$$.addr=malloc(5);
				strcpy($$.addr,$2.addr);
			}
		
		|	'~' expr	
			{
				$$.addr=malloc(5);
				strcpy($$.addr,new_temp());
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%c%s",$$.addr,'=','~',$2.addr);
				next_inst++;
			}
			
		|	'-' expr %prec UMINUS
			{
				$$.addr=malloc(5);
				strcpy($$.addr,new_temp());
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%c%s",$$.addr,'=','-',$2.addr);
				next_inst++;
			}
			
		|	INTEGER			
			{
				$$.addr=malloc(5);
				strcpy($$.addr,$1.addr);
			}
		|	IDENTIFIER		
			{
				if(!isdeclared($1.addr))
				{
					printf("\n%s not declared\n",$1.addr);
				}
				
				$$.addr=malloc(5);
				strcpy($$.addr,$1.addr);
			}
		;

%%
#include "lex.yy.c"

int main(int argc,char** argv)
{
	if(argc==2)
	yyin=fopen(argv[1],"r");

	else
	yyin=fopen("input.cpp","r");
	
	yyparse();
	
}

struct list * makelist(int next_inst)
{
	struct list * new=malloc(sizeof(struct list));
	new->inst_no=next_inst;
	new->next=NULL;
	return new;
}

struct list * merge(struct list * l1,struct list * l2)
{
	if(l1!=NULL)
	{
		struct list * new=l1;
		while(l1->next!=NULL)
		l1=l1->next;
		l1->next=l2;
		return new;
	}
	
	else return l2; 

}

void backpatch(struct list* l,int target_inst)
{
	while(l!=NULL)
	{
		sprintf(fill_label,"%d",target_inst);
		strcat(code[l->inst_no],fill_label);
		l=l->next;
	}
}

char* new_temp()
{
	char *temp;
	temp=malloc(5);
	sprintf(temp,"%c%d",'t',count++);
	return temp;
}


void print_code()
{
	printf("\nFinal intermediate code is --- \n");
	int i;
	for(i=1;i<next_inst;i++)
	{
		if(i<100) printf(" ");
		if(i<10) printf(" ");
		printf("%d : %s\n",i,code[i]);
	}
}


void declare(char* id)
{
	identifiers[no_of_identifiers++]=id;
}

int isdeclared(char* id)
{
	int i;
	
	for(i=0;i<no_of_identifiers;i++)
	if(strcmp(identifiers[i],id)==0)
	return 1;
	
	return 0;
	
}
