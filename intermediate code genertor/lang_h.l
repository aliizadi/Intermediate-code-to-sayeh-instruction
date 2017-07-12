%{
#include<stdlib.h>
#include<stdio.h>
#include"y.tab.h"
//void yyerror(char*);
%}

ALPHA [A-Za-z]
DIGIT [0-9]
%%
false	return FALSE;
true	return TRUE;
"int main()"	return MAIN;

int 	return VAR;

default return DEFAULT;
case 	return CASE;
switch 	return SWITCH;
break	return BREAK;
while 			return WHILE;
if                 return IF;
else                 return ELSE;

">"|"<"|">="|"<="|"=="|"!="	{ strcpy(yylval.str.op,yytext);		return REL;}
"="|"+="|"-="|"*="|"/="		{ strcpy(yylval.str.op,yytext);		return ASSIGN;}
"||"			{	return LOGICAL_OR; }
"&&"			{	return LOGICAL_AND;}

{ALPHA}({ALPHA}|{DIGIT})* {	strcpy(yylval.str.addr,yytext);	return ID;}

{DIGIT}+    {strcpy(yylval.str.addr,yytext); return NUM;}

[-+*/@\(\)=\{\};,\|!:\^%~&] 	{return yytext[0];}
[ \t\n] ;

. 	{yyerror("invalid character\n");}
%%
