/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 66 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* mylexer.c
* C source file generated from mylexer.l.
* 
* Date: 06/22/18
* Time: 19:54:11
* 
* ALex Version: 2.07
****************************************************************************/

#include <yylex.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTLEXER

#line 1 ".\\mylexer.l"

/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2018Äê6ÔÂ13ÈÕ
****************************************************************************/

#include "myparser.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#line 54 "mylexer.c"
/* repeated because of possible precompiled header */
#include <yylex.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTLEXER

#include ".\mylexer.h"

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/* yytext */
static char YYNEAR yysatext[(YYTEXT_SIZE) + 1];		/* extra char for \0 */
char YYFAR *YYNEAR YYDCDECL yystext = yysatext;
char YYFAR *YYNEAR YYDCDECL yytext = yysatext;
int YYNEAR YYDCDECL yystext_size = (YYTEXT_SIZE);
int YYNEAR YYDCDECL yytext_size = (YYTEXT_SIZE);
int YYNEAR YYDCDECL yytext_max = (YYTEXT_MAX);

/* yystatebuf */
#if (YYTEXT_SIZE) != 0
static int YYNEAR yysastatebuf[(YYTEXT_SIZE)];
int YYFAR *YYNEAR YYDCDECL yysstatebuf = yysastatebuf;
int YYFAR *YYNEAR YYDCDECL yystatebuf = yysastatebuf;
#else
int YYFAR *YYNEAR YYDCDECL yysstatebuf = NULL;
int YYFAR *YYNEAR YYDCDECL yystatebuf = NULL;
#endif

/* yyunputbuf */
#if (YYUNPUT_SIZE) != 0
static int YYNEAR yysaunputbuf[(YYUNPUT_SIZE)];
int YYFAR *YYNEAR YYDCDECL yysunputbufptr = yysaunputbuf;
int YYFAR *YYNEAR YYDCDECL yyunputbufptr = yysaunputbuf;
#else
int YYFAR *YYNEAR YYDCDECL yysunputbufptr = NULL;
int YYFAR *YYNEAR YYDCDECL yyunputbufptr = NULL;
#endif
int YYNEAR YYDCDECL yysunput_size = (YYUNPUT_SIZE);
int YYNEAR YYDCDECL yyunput_size = (YYUNPUT_SIZE);
int YYNEAR YYDCDECL yyunput_max = (YYUNPUT_MAX);

/* backwards compatability with lex */
#ifdef input
#ifdef YYPROTOTYPE
int YYCDECL yyinput(void)
#else
int YYCDECL yyinput()
#endif
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
#ifdef YYPROTOTYPE
void YYCDECL yyoutput(int ch)
#else
void YYCDECL yyoutput(ch)
int ch;
#endif
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
#ifdef YYPROTOTYPE
void YYCDECL yyunput(int ch)
#else
void YYCDECL yyunput(ch)
int ch;
#endif
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		/* <warning: unreachable code> off */
#endif
#endif

#ifdef YYPROTOTYPE
int YYCDECL yylexeraction(int action)
#else
int YYCDECL yylexeraction(action)
int action;
#endif
{
	yyreturnflg = YYTRUE;
	switch (action) {
	case 1:
		{
#line 27 ".\\mylexer.l"
;
#line 175 "mylexer.c"
		}
		break;
	case 2:
		{
#line 28 ".\\mylexer.l"
return CREATE;
#line 182 "mylexer.c"
		}
		break;
	case 3:
		{
#line 29 ".\\mylexer.l"
return DATABASE;
#line 189 "mylexer.c"
		}
		break;
	case 4:
		{
#line 30 ".\\mylexer.l"
return USE;
#line 196 "mylexer.c"
		}
		break;
	case 5:
		{
#line 31 ".\\mylexer.l"
return TABLE;
#line 203 "mylexer.c"
		}
		break;
	case 6:
		{
#line 32 ".\\mylexer.l"
return INSERT;
#line 210 "mylexer.c"
		}
		break;
	case 7:
		{
#line 33 ".\\mylexer.l"
return INTO;
#line 217 "mylexer.c"
		}
		break;
	case 8:
		{
#line 34 ".\\mylexer.l"
return VALUES;
#line 224 "mylexer.c"
		}
		break;
	case 9:
		{
#line 35 ".\\mylexer.l"
return SHOW;
#line 231 "mylexer.c"
		}
		break;
	case 10:
		{
#line 36 ".\\mylexer.l"
return TABLES;
#line 238 "mylexer.c"
		}
		break;
	case 11:
		{
#line 37 ".\\mylexer.l"
return SELECT;
#line 245 "mylexer.c"
		}
		break;
	case 12:
		{
#line 38 ".\\mylexer.l"
return FROM;
#line 252 "mylexer.c"
		}
		break;
	case 13:
		{
#line 39 ".\\mylexer.l"
return CHAR;
#line 259 "mylexer.c"
		}
		break;
	case 14:
		{
#line 40 ".\\mylexer.l"
return INT;
#line 266 "mylexer.c"
		}
		break;
	case 15:
		{
#line 41 ".\\mylexer.l"
exit(0);
#line 273 "mylexer.c"
		}
		break;
	case 16:
		{
#line 43 ".\\mylexer.l"

	yylval.yych = (char*) malloc(strlen(yytext)+1);
	strcpy(yylval.yych,yytext);
	return ID;
#line 283 "mylexer.c"
		}
		break;
	case 17:
		{
#line 48 ".\\mylexer.l"
	yylval.yych=(char *)malloc(strlen(yytext)+1);
										strcpy(yylval.yych,yytext);
										return NUMBER;
#line 292 "mylexer.c"
		}
		break;
	case 18:
		{
#line 51 ".\\mylexer.l"
 return ','; 
#line 299 "mylexer.c"
		}
		break;
	case 19:
		{
#line 52 ".\\mylexer.l"
 return '('; 
#line 306 "mylexer.c"
		}
		break;
	case 20:
		{
#line 53 ".\\mylexer.l"
 return ')'; 
#line 313 "mylexer.c"
		}
		break;
	case 21:
		{
#line 54 ".\\mylexer.l"
 return '*'; 
#line 320 "mylexer.c"
		}
		break;
	case 22:
		{
#line 55 ".\\mylexer.l"
 return ';'; 
#line 327 "mylexer.c"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = YYFALSE;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		/* <warning: unreachable code> to the old state */
#endif
#endif
YYCONST yymatch_t YYNEARFAR YYBASED_CODE YYDCDECL yymatch[] = {
	0
};

int YYNEAR YYDCDECL yytransitionmax = 253;
YYCONST yytransition_t YYNEARFAR YYBASED_CODE YYDCDECL yytransition[] = {
	{ 0, 0 },
	{ 3, 1 },
	{ 22, 11 },
	{ 24, 12 },
	{ 34, 21 },
	{ 3, 3 },
	{ 34, 21 },
	{ 0, 0 },
	{ 30, 17 },
	{ 4, 1 },
	{ 5, 1 },
	{ 6, 1 },
	{ 23, 11 },
	{ 7, 1 },
	{ 41, 27 },
	{ 42, 27 },
	{ 31, 18 },
	{ 8, 1 },
	{ 8, 1 },
	{ 8, 1 },
	{ 8, 1 },
	{ 8, 1 },
	{ 8, 1 },
	{ 8, 1 },
	{ 8, 1 },
	{ 8, 1 },
	{ 8, 1 },
	{ 28, 16 },
	{ 9, 1 },
	{ 32, 19 },
	{ 29, 16 },
	{ 0, 20 },
	{ 0, 0 },
	{ 36, 22 },
	{ 22, 11 },
	{ 24, 12 },
	{ 11, 1 },
	{ 12, 1 },
	{ 13, 1 },
	{ 14, 1 },
	{ 30, 17 },
	{ 37, 23 },
	{ 15, 1 },
	{ 38, 24 },
	{ 23, 11 },
	{ 39, 25 },
	{ 41, 27 },
	{ 42, 27 },
	{ 31, 18 },
	{ 40, 26 },
	{ 25, 13 },
	{ 43, 28 },
	{ 16, 1 },
	{ 17, 1 },
	{ 18, 1 },
	{ 19, 1 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 28, 16 },
	{ 0, 0 },
	{ 32, 19 },
	{ 29, 16 },
	{ 0, 20 },
	{ 0, 1 },
	{ 36, 22 },
	{ 44, 29 },
	{ 45, 30 },
	{ 11, 1 },
	{ 12, 1 },
	{ 13, 1 },
	{ 14, 1 },
	{ 46, 31 },
	{ 37, 23 },
	{ 15, 1 },
	{ 38, 24 },
	{ 0, 0 },
	{ 39, 25 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 40, 26 },
	{ 25, 13 },
	{ 43, 28 },
	{ 16, 1 },
	{ 17, 1 },
	{ 18, 1 },
	{ 19, 1 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 44, 29 },
	{ 45, 30 },
	{ 47, 32 },
	{ 26, 14 },
	{ 48, 36 },
	{ 0, 0 },
	{ 46, 31 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 0, 0 },
	{ 47, 32 },
	{ 26, 14 },
	{ 48, 36 },
	{ 10, 72 },
	{ 0, 0 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 10, 72 },
	{ 33, 33 },
	{ 33, 33 },
	{ 33, 33 },
	{ 33, 33 },
	{ 33, 33 },
	{ 33, 33 },
	{ 33, 33 },
	{ 33, 33 },
	{ 33, 33 },
	{ 33, 33 },
	{ 49, 37 },
	{ 50, 38 },
	{ 51, 39 },
	{ 52, 40 },
	{ 53, 41 },
	{ 54, 42 },
	{ 55, 43 },
	{ 56, 44 },
	{ 57, 45 },
	{ 58, 47 },
	{ 59, 49 },
	{ 21, 33 },
	{ 60, 50 },
	{ 61, 53 },
	{ 62, 55 },
	{ 63, 57 },
	{ 64, 58 },
	{ 65, 59 },
	{ 66, 60 },
	{ 67, 61 },
	{ 68, 62 },
	{ 69, 63 },
	{ 70, 64 },
	{ 71, 66 },
	{ 72, 71 },
	{ 27, 15 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 49, 37 },
	{ 50, 38 },
	{ 51, 39 },
	{ 52, 40 },
	{ 53, 41 },
	{ 54, 42 },
	{ 55, 43 },
	{ 56, 44 },
	{ 57, 45 },
	{ 58, 47 },
	{ 59, 49 },
	{ 21, 33 },
	{ 60, 50 },
	{ 61, 53 },
	{ 62, 55 },
	{ 63, 57 },
	{ 64, 58 },
	{ 65, 59 },
	{ 66, 60 },
	{ 67, 61 },
	{ 68, 62 },
	{ 69, 63 },
	{ 70, 64 },
	{ 71, 66 },
	{ 72, 71 },
	{ 27, 15 },
	{ 20, 8 },
	{ 0, 0 },
	{ 8, 8 },
	{ 8, 8 },
	{ 8, 8 },
	{ 8, 8 },
	{ 8, 8 },
	{ 8, 8 },
	{ 8, 8 },
	{ 8, 8 },
	{ 8, 8 },
	{ 8, 8 },
	{ 35, 35 },
	{ 35, 35 },
	{ 35, 35 },
	{ 35, 35 },
	{ 35, 35 },
	{ 35, 35 },
	{ 35, 35 },
	{ 35, 35 },
	{ 35, 35 },
	{ 35, 35 }
};

YYCONST yystate_t YYNEARFAR YYBASED_CODE YYDCDECL yystate[] = {
	{ 0, 0, 0 },
	{ 72, -31, 0 },
	{ 1, 0, 0 },
	{ 0, -27, 1 },
	{ 0, 0, 19 },
	{ 0, 0, 20 },
	{ 0, 0, 21 },
	{ 0, 0, 18 },
	{ 33, 185, 17 },
	{ 0, 0, 22 },
	{ 72, 0, 16 },
	{ 72, -70, 16 },
	{ 72, -62, 16 },
	{ 72, -38, 16 },
	{ 72, 19, 16 },
	{ 72, 120, 16 },
	{ 72, -42, 16 },
	{ 72, -57, 16 },
	{ 72, -67, 16 },
	{ 72, -36, 16 },
	{ 33, -38, 0 },
	{ 35, -39, 0 },
	{ 72, -32, 16 },
	{ 72, -28, 16 },
	{ 72, -41, 16 },
	{ 72, -28, 16 },
	{ 72, -30, 16 },
	{ 72, -69, 16 },
	{ 72, -25, 16 },
	{ 72, -13, 16 },
	{ 72, 1, 16 },
	{ 72, 3, 16 },
	{ 72, 24, 16 },
	{ 0, 115, 17 },
	{ 35, 0, 0 },
	{ 0, 195, 17 },
	{ 72, 20, 16 },
	{ 72, 108, 16 },
	{ 72, 109, 16 },
	{ 72, 91, 16 },
	{ 72, 99, 16 },
	{ 72, 108, 16 },
	{ 72, 99, 14 },
	{ 72, 110, 16 },
	{ 72, 93, 16 },
	{ 72, 105, 16 },
	{ 72, 0, 4 },
	{ 72, 97, 16 },
	{ 72, 0, 13 },
	{ 72, 99, 16 },
	{ 72, 119, 16 },
	{ 72, 0, 15 },
	{ 72, 0, 12 },
	{ 72, 104, 16 },
	{ 72, 0, 7 },
	{ 72, 120, 16 },
	{ 72, 0, 9 },
	{ 72, 119, 16 },
	{ 72, 120, 16 },
	{ 72, 121, 16 },
	{ 72, 126, 16 },
	{ 72, 108, 16 },
	{ 72, 109, 16 },
	{ 72, 111, 5 },
	{ 72, 112, 16 },
	{ 72, 0, 2 },
	{ 72, 113, 16 },
	{ 72, 0, 6 },
	{ 72, 0, 11 },
	{ 72, 0, 10 },
	{ 72, 0, 8 },
	{ 72, 128, 16 },
	{ 0, 40, 3 }
};

YYCONST yybackup_t YYNEARFAR YYBASED_CODE YYDCDECL yybackup[] = {
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0
};

#line 58 ".\\mylexer.l"


/////////////////////////////////////////////////////////////////////////////
// programs section



