%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int v_count=1;
int nextinstrno=1;
char label_[10];
char var [20];
struct list
{
	int instno;
	struct list *next;
};


char all_insts[500][50];
char all_declared_ids[50][10];
struct list * makelist(int nextinst);
struct list * merge(struct list * l1,struct list * l2);
void backpatch(struct list* l,int targetinst);
int already_added(char* id);
void add_in_symbol_table(char*);
void emit (char* );
char* newtemp();
void print_all_ins();
int nids=0;
char label_to_fill[10];
int  ncases,ndefaults;
char* case_instruc[20][2];
%}

%union
{
	struct
	{

		int instr;
		char addr[20];
		char lexeme[20];
		struct list* nextlist;
		struct list* truelist;
		struct list* falselist;
		char op[5];
	}str;
}



%right ASSIGN
%right '='

%left 	LOGICAL_OR
%left 	LOGICAL_AND
%left	'|'
%left	'^'
%left	'&'
%left	REL

%left '+' '-'
%left '*' '/' '%'
%right '@'
%right '!'  '~'
%type <str> stmt E assign B M L N start id_list all_cases
%token <str> NUM ID IF ELSE REL TRUE FALSE  WHILE LOGICAL_AND  LOGICAL_OR MAIN ASSIGN BREAK VAR  SWITCH DEFAULT CASE
%start start
%%

start :	 MAIN   stmt M  { backpatch ( $2.nextlist,$3.instr );
			print_all_ins();
		}
;

stmt	:	IF '(' B ')' M stmt  ELSE  N M stmt {	backpatch ( $3.truelist,$5.instr);
							backpatch ( $3.falselist,$9.instr);
							struct list* temp=merge ($6.nextlist,$8.nextlist);
							$$.nextlist = merge (temp,$10.nextlist);

						}

		|IF '(' B ')' M stmt
			{
				backpatch($3.truelist,$5.instr);
				$$.nextlist=merge($3.falselist,$6.nextlist);
			}


	 	| WHILE  M  '('  B  ')'  M  stmt  {
							backpatch ($7.nextlist, $2.instr);
							backpatch ($4.truelist, $6.instr);
							$$.nextlist = $4.falselist;
							char temp [30];
							sprintf(temp, "GOTO %d",$2.instr);
							emit(temp);
						}
		| SWITCH '(' E ')' N '{' all_cases '}' M
			{
				char temp[30];
				sprintf(temp,"%s","goto ");
				emit(temp);

				backpatch($5.nextlist,nextinstrno);


				int i;
				for(i=1;i<=ncases;i++)	{
					if(i!=ncases||case_instruc[i][0]!=NULL)
						sprintf(temp,"if %s == %s  GOTO %s ",$3.addr,case_instruc[i][0],case_instruc[i][1]);
					else
					sprintf(temp,"GOTO %s ",case_instruc[i][1]);
					emit (temp);
				}

				backpatch($7.nextlist,nextinstrno);

				sprintf(label_to_fill,"%d",nextinstrno);
				strcat(all_insts[$9.instr],label_to_fill);
				ncases=0;
				ndefaults=0;
				$$.nextlist=NULL;
			}


		| 	'{' L '}'  { $$.nextlist= $2.nextlist ;}


		|	assign   { $$.nextlist = NULL;}

		|	BREAK ';'	{
						$$.nextlist=makelist(nextinstrno);
						char temp [30];
						sprintf(temp,"%s","goto ");
						emit(temp);
					}

		|	VAR id_list ';'  {	$$.nextlist= NULL; }

		|	'{'  '}' {
					$$.nextlist=NULL;
				}

;


all_cases		:	all_cases CASE E ':' M stmt
			{
				ncases++;
				case_instruc[ncases][0]=(char*)malloc(5);
				strcpy(case_instruc[ncases][0],$3.addr);
				sprintf(label_to_fill,"%d",$5.instr);
				strcpy(case_instruc[ncases][1],label_to_fill);
				$$.nextlist=merge($1.nextlist,$6.nextlist);

			}

		|	all_cases DEFAULT ':' M stmt
			{
				ncases++;
				ndefaults++;

				if(ndefaults==2)
				{
					printf("\nerror more than 1 defaults \n");
					exit(1);
				}

				case_instruc[ncases][0]=NULL;
				sprintf(label_to_fill,"%d",$4.instr);
				case_instruc[ncases][1]=(char*)malloc(5);
				strcpy(case_instruc[ncases][1],label_to_fill);
				$$.nextlist=merge($1.nextlist,$5.nextlist);
			}

		|	CASE E ':' M stmt
			{
				ncases++;
				case_instruc[ncases][0]=$2.addr;
				sprintf(label_to_fill,"%d",$4.instr);
				case_instruc[ncases][1]=(char*)malloc(5);
				strcpy(case_instruc[ncases][1],label_to_fill);
				$$.nextlist=$5.nextlist;
			}

;

id_list		:	id_list ',' ID	{ add_in_symbol_table ($3.addr); }

		|	ID		{ add_in_symbol_table ($1.addr); }


		|	id_list ',' ID ASSIGN E	{ add_in_symbol_table ($3.addr);}

		|	ID '=' E	{add_in_symbol_table ($1.addr);}
;



B 		: 	B 	LOGICAL_OR  M  B  { 	backpatch ($1.falselist, $3.instr );
							$$.truelist = merge( $1.truelist,$4.truelist );
							$$.falselist = $4.falselist;
						}
		|

			B 	LOGICAL_AND  M  B  { 	backpatch ($1.truelist, $3.instr );
							$$.truelist = $4.truelist;
							$$.falselist = merge( $1.falselist,$4.falselist );
						}

		|	'!' B 	{ $$.truelist = $2.falselist;
				  $$.falselist= $2.truelist;
				}

		| 	'(' B ')'	 {
					   $$.truelist = $2.truelist;
					   $$.falselist= $2.falselist;
					}

		|	E REL E  { 	$$.truelist =makelist (nextinstrno);
						$$.falselist = makelist (nextinstrno + 1 );
						char temp[30];
					sprintf(temp ,"IF %s %s %s GOTO ",$1.addr,$2.op,$3.addr);
						emit (temp);
						strcpy (temp,"GOTO ");
						emit (temp);
				}
		| 	TRUE  {		$$.truelist=makelist(nextinstrno);
						char temp [30];
						sprintf(temp,"GOTO ");
						emit ( temp);
				}
		|	FALSE {		$$.falselist = makelist ( nextinstrno);
						char temp[30];
						sprintf(temp,"GOTO ");
						emit ( temp);

				}

;


assign	:	ID ASSIGN E ';' {	if(!already_added($1.addr)) {
						printf("error: %s undeclared (first used without declaration)\n",$1.addr);
						exit(0);
					}
					char temp[30];
					sprintf(temp,"%s %s %s\n",$1.addr,$2.op,$3.addr);
					emit (temp);
			}
;

L 	: 	L  M  stmt  {	backpatch ($1.nextlist,$2.instr);
				$1.nextlist = $3.nextlist;
			}

	|	stmt	{ 	$$.nextlist= $1.nextlist;
			}
;

E	:	 E '+' E 	{	strcpy($$.addr, newtemp());
					char temp[30];
					sprintf(temp,"%s = %s + %s\n",$$.addr,$1.addr,$3.addr);
					emit (temp);
				}

	|	E '-' E 	{	strcpy($$.addr, newtemp());
					char temp[30];
					sprintf(temp,"%s = %s - %s\n",$$.addr,$1.addr,$3.addr);
					emit (temp);
				}
	|	E '*' E 	{	strcpy($$.addr, newtemp());
					char temp[30];
					sprintf(temp,"%s = %s * %s\n",$$.addr,$1.addr,$3.addr);
					emit (temp);
				}
	|	E '/' E 	{	strcpy($$.addr, newtemp());
					char temp[30];
					sprintf(temp,"%s = %s / %s\n",$$.addr,$1.addr,$3.addr);
					emit (temp);
				}
	|	E '%' E 	{	strcpy($$.addr, newtemp());
					char temp[30];
					sprintf(temp,"%s = %s %% %s\n",$$.addr,$1.addr,$3.addr);
					emit (temp);
				}
	|	E '@' E 	{	strcpy($$.addr, newtemp());
					char temp[30];
					sprintf(temp,"%s = %s - %s\n",$$.addr,$1.addr,$3.addr);
					emit (temp);
				}
	|	E '|' E 	{	strcpy($$.addr, newtemp());
					char temp[30];
					sprintf(temp,"%s = %s - %s\n",$$.addr,$1.addr,$3.addr);
					emit (temp);
				}
	|	E '&' E 	{	strcpy($$.addr, newtemp());
					char temp[30];
					sprintf(temp,"%s = %s & %s\n",$$.addr,$1.addr,$3.addr);
					emit (temp);
				}
	|	E '^' E 	{	strcpy($$.addr, newtemp());
					char temp[30];
					sprintf(temp,"%s = %s - %s\n",$$.addr,$1.addr,$3.addr);
					emit (temp);
				}
	|	'(' E ')'	{	strcpy ($$.addr,$2.addr);
				}

	|	'-' E      	{
					strcpy($$.addr,newtemp());
					char temp[30];
					sprintf( temp, "%s = MINUS %s ",$$.addr,$$.addr);
					emit(temp);
				}
	|	'~' E      	{
					strcpy($$.addr,newtemp());
					char temp[30];
					sprintf( temp, "%s = ~ %s ",$$.addr,$$.addr);
					emit(temp);
				}


	|	ID 	{ 	if(!already_added($1.addr)){
					printf("error: %s undeclared (first used without declaration)\n",$1.addr);
					exit(0);
				}
				strcpy($$.addr,$1.addr);


			}

	|	NUM 	{strcpy($$.addr,$1.addr);}


;


M 		: 		{	$$.instr=nextinstrno; }
;

N 		: 		{	$$.nextlist = makelist(nextinstrno);
					char temp[30];
					sprintf(temp,"GOTO ");
					emit(temp);
				 }

;
%%
#include "lex.yy.c"

int main()
{
	yyin=fopen("input.in","r");
	printf("Enter program:\n");
	yyparse();

}

struct list * makelist(int instno)
{
	struct list * newlist=malloc(sizeof(struct list));
	newlist->instno=instno;
	newlist->next=NULL;
	return newlist;
}

struct list* merge(struct list* l1,struct list* l2)
{
	if(l1!=NULL)
	{
		struct list * newlist=l1;
		while(l1->next!=NULL)
			l1=l1->next;
		l1->next=l2;
		return newlist;
	}

	else return l2;
}

void backpatch(struct list* l,int targetinst)
{
	while(l!=NULL)
	{
		sprintf(label_,"%d",targetinst);
		strcat(all_insts[l->instno],label_);
		l=l->next;
	}
}

char* newtemp()
{
	sprintf(var,"%s%d","temp",v_count++);
	return var;
}



void emit (char* one_inst) {
	strcpy( all_insts[nextinstrno++],one_inst);
}

void print_all_ins()
{
	printf("\nEquivalent 3 address code:\n");
	int i;
	for(i=1;i<nextinstrno;i++)
	{
		printf("%d : %s\n",i,all_insts[i]);
	}
}

void add_in_symbol_table (char* id) {
	strcpy(all_declared_ids[nids++],id);
}

int already_added(char* id){
	//printf("called\n");
	int i;
	for(i=0;i<nids;i++){
		if(strcmp(all_declared_ids[i],id)==0)
			return 1;
	}
	return 0;

}
