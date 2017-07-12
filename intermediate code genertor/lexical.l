%{
#include "y.tab.h"
%}
digit		[0-9]
letter		[a-zA-Z]
identifier	{letter}({digit}|{letter})*
integer		{digit}+	

%%	
"int main()"		return MAIN;

while			{
				return WHILE;
			}
			
if			{
				return IF;
			}
			
else			{
				return ELSE;
			}

switch			{
				return SWITCH;
			}
			
case			{
				return CASE;
			}

int			{
				return INT;
			} 	

default			{
				return DEFAULT;
			}

break			{
				return BREAK;
			}

true			{
				return TRUE;
			}
			
false			{
				return FALSE;
			}		


[ \t\n]			{
			}
			
"/*"(.*[\n]*)*"*/" 	{
			}

[/][/].* ;		{
			}	

{identifier}		{
				yylval.info.addr=malloc(5);
				strcpy(yylval.info.addr,yytext);
				return IDENTIFIER;
			}
			
{integer}		{
				yylval.info.addr=malloc(5);
				strcpy(yylval.info.addr,yytext);
				return INTEGER;
			}
		
		
"+="			{return PLUS_ASSIGN;}
"-="			{return MINUS_ASSIGN;}
"*="			{return MUL_ASSIGN;}
"/="			{return DIV_ASSIGN;}
"=="			{return EQUAL;}	
"!="			{return NOT_EQUAL;}
">="			{return GREATER_OR_EQUAL;}
"<="			{return LESS_OR_EQUAL;}
"&&"			{return LOGICAL_AND;}
"||"			{return LOGICAL_OR;}	
		
		
			
[-!+*/\(\)=;\{\}&\|\^~@%:,><]	{
					return yytext[0];
				}
			
			
.			{
				ECHO;
				yyerror ("unexpected character");
			}
%%
