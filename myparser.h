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
* myparser.h
* C header file generated from myparser.y.
* 
* Date: 06/22/18
* Time: 19:54:11
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _MYPARSER_H
#define _MYPARSER_H

#include <yypars.h>

#ifndef YYSTYPE
union tagYYSTYPE {
#line 509 ".\\myparser.y"
	
	int yyint;
	char * yych;
	struct Createfieldsdef *cfdef_var;
	struct Createstruct *cs_var;
	struct TableType *yytabletype;
	struct insert_type *yyinsert;
	struct Insertstruct *yyinsertHead;
	struct InsertColumns *yycolum;

#line 46 "myparser.h"
};

#define YYSTYPE union tagYYSTYPE
#endif

extern YYSTYPE YYNEAR yylval;

#define CREATE 257
#define DATABASE 258
#define USE 259
#define TABLE 260
#define INSERT 261
#define INTO 262
#define VALUES 263
#define SHOW 264
#define TABLES 265
#define SELECT 266
#define FROM 267
#define CHAR 268
#define INT 269
#define NUMBER 270
#define ID 271
#endif
