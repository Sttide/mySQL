%{
/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2018年6月13日
****************************************************************************/

#include "myparser.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
%}

digit	[0-9]
digits	{digit}+
optional_fraction	("."{digits})?
optional_exponent	(E[+-]?{digits})?

// place any declarations here

%%

/////////////////////////////////////////////////////////////////////////////
// rules section
//词法规则正规式
[ ]+ ;
CREATE {return CREATE;}
DATABASE {return DATABASE;}
USE {return USE;}
TABLE {return TABLE;}
INSERT {return INSERT;}
INTO {return INTO;}
VALUES {return VALUES;}
SHOW {return SHOW;}
TABLES {return TABLES;}
SELECT {return SELECT;}
FROM {return FROM;}
CHAR {return CHAR;}
INT {return INT;}
Exit {exit(0);}

[A-Za-z][A-Za-z0-9_]* {
	yylval.yych = (char*) malloc(strlen(yytext)+1);
	strcpy(yylval.yych,yytext);
	return ID;}

{digits}{optional_fraction}{optional_exponent}	{	yylval.yych=(char *)malloc(strlen(yytext)+1);
										strcpy(yylval.yych,yytext);
										return NUMBER;}
"," { return ','; }
"(" { return '('; }
")" { return ')'; }
"*" { return '*'; }
";" { return ';'; }


%%

/////////////////////////////////////////////////////////////////////////////
// programs section


