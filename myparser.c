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
* myparser.c
* C source file generated from myparser.y.
* 
* Date: 06/22/18
* Time: 19:54:11
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yypars.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTPARSER

#line 1 ".\\myparser.y"

/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: 2018年6月13日
****************************************************************************/

#include "mylexer.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char file_name[50] = {"C:\\Code\\mysql\\DataBase\\"};
char use_db[50] = {"C:\\Code\\mysql\\DataBase\\"};

FILE *fp,*fp2,*fp3;

struct TableType{
	char *mytype;
	long length;
};		//表的类型结构体

struct insert_type{
	char *now;
	char type[5];
	long length;
	char col_name[100];
	struct insert_type *next_insert;
};		//插入 values结构体

struct Insertstruct{
	char *table;
	struct insert_type *fdef;
};		//插入 values 的表头

struct InsertColumns{
	char column_name[200];
	struct InsertColumns *next_col;
};		//插入 列的结构体

struct Createfieldsdef{
	char *field;
	struct TableType *type;
	struct Createfieldsdef *next_fdef;
};		//创建表的结构体
	
struct Createstruct{
	char *table;
	struct Createfieldsdef *fdef;
};		//创建表结构体的表头

	
//创建数据库
void CreateDB(char *a)
{
	
	FILE *fp,*fp2;
	int status;
	char path[40],db_path[40];
	
	
	strcpy(path,file_name);
	strcpy(db_path,file_name);
	strcat(path,a);
	strcat(db_path,"sys.dat");
	printf("%s\n",path);
	status = mkdir(path);
	if(status==-1)
	{
		printf("Error or database already existed!\n");
		return;
	}
	strcat(path,"\\sys.dat");
	if((fp=fopen(path,"a+"))==NULL)
	{
		printf("\nopen file error");
		fclose(fp2);
		return;
	}
	printf("Successfully create database %s\n",a);
	fclose(fp);
	strcat(a,"\n");
	if((fp2=fopen(db_path,"a+"))==NULL)
	{	
		printf("\nopen file error");
		fclose(fp2);
		return;	
	}
	fputs(a,fp2);
	fclose(fp2);
	return;
}

//使用数据库
void UseDB(char *a)
{
	int status=0,status_r=0;
	char path[40],db_path[40];
	strcpy(path,file_name);
	strcat(path,a);
	status = mkdir(path);
	if(status==-1)
	{
		memset(use_db, 0, sizeof(use_db));
		strcpy(use_db,file_name);
		strcat(use_db,a);
		strcat(use_db,"\\");
		printf("Success!\n");
		return;
	}
	printf("%s\n",path);
	status_r = rmdir(path);
	printf("No such databases!\n"); 
	return;
	
}

//创建表
int CreateTable(struct Createstruct* a)
{
	//FILE *fp, *fp2;
	struct Createfieldsdef * zhizhen = NULL;
	struct Createfieldsdef * zhizhen2 = NULL;
	char b[100] , c[100],lowdre[] = {".txt"};
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	strcpy(b,use_db);
	strcat(b,a->table);
	strcat(b,lowdre);
	printf("%s\n",b);
	strcpy(c,use_db);
	strcat(c,"sys.dat");
	printf("%s\n",c);
	if(_access(b,0)==0)
	{
		printf("file exists!\n");
		return 0;
	}
	if((fp2=fopen(b,"w"))==NULL)
	{
		printf("system error!\n");
		fclose(fp2);
		return 0;
	}
	if((fp=fopen(c,"a+"))==NULL)
	{
		printf("system error!\n");
		fclose(fp);
		return 0;
	}
	
	if(a->fdef!=NULL)
	{
		int num=1;
		zhizhen = a->fdef;
		while(zhizhen!=NULL)
		{	
			fprintf(fp,"%s ",a->table);
			fprintf(fp,"%d ",num);
			fprintf(fp,"%s ",zhizhen->field);
			fprintf(fp,"%s ",zhizhen->type->mytype);
			fprintf(fp,"%d\n",zhizhen->type->length);
			zhizhen2 = zhizhen->next_fdef;
			zhizhen = zhizhen2;
			num++;
		}
		zhizhen = a->fdef;
		a->fdef=NULL;
		while(zhizhen!=NULL)
		{
			zhizhen2 = zhizhen->next_fdef;
			free(zhizhen);
			zhizhen = zhizhen2;
		}
	}
	fclose(fp);
	fclose(fp2);
	return 1;
}

//显示表
void ShowTables()
{
	char goal_path[200] = {""};
	char Temp_tname[200];
	char Temp_cl[200];
	char Temp_ty[200];
	int Temp_num = 0;
	int Temp_length = 0;//结构同下
	strcpy(goal_path,use_db);
	strcat(goal_path,"sys.dat");
	if((fp=fopen(goal_path,"r"))==NULL)
	{
		printf("system error!\n");
		return;
	}
	while(fscanf(fp,"%s%d%s%s%d",&Temp_tname,&Temp_num,&Temp_cl,&Temp_ty,&Temp_length)!=EOF)
	{
		printf("%s %d %s %s %d\n",Temp_tname,Temp_num,Temp_cl,Temp_ty,Temp_length);
	}
	fclose(fp);
	return;
	
}

//插入表
void InsertValues(struct Insertstruct *ins)
{
	char Temp_tname[200];
	char Temp_cl[200];
	char Temp_ty[200];
	int Temp_num = 0;
	int Temp_length = 0;//临时读取创建表格时的type
	int i=0;
	char file_path[200]={""};
	char goal_path[200] = {""};//table路径
	struct insert_type query[150];	//查询type是否对应
	struct insert_type *x = NULL;	//遍历链表所需要指针
	struct insert_type *y = NULL;

	strcpy(file_path,use_db);
	strcat(file_path,ins->table);
	strcat(file_path,".txt");
	//printf("%s\n",file_path);
	printf("Inserting......\n");
	strcpy(goal_path,use_db);
	strcat(goal_path,"sys.dat");
	//printf("%s\n",goal_path);	//查看插入表的type类型
	if((fp3=fopen(goal_path,"r"))==NULL)
	{
		printf("system error!\n");
		fclose(fp3);
		return;
	}
	while(fscanf(fp3,"%s%d%s%s%d",&Temp_tname,&Temp_num,&Temp_cl,&Temp_ty,&Temp_length)!=EOF)
	{
		if(strcmp(Temp_tname,ins->table)==0)
		{
			strcpy(query[Temp_num-1].type,Temp_ty);
			query[Temp_num-1].length = Temp_length;
			if(strcmp(Temp_ty,"int")==0)
			{
				query[Temp_num-1].length = 2147483647;
			}
		}
	}
	fclose(fp3);

	if((fp=fopen(file_path,"a+"))==NULL)
	{
		printf("system error!\n");
		fclose(fp);
		return;
	}
	Temp_num = 0;
	if(ins->fdef!=NULL)
	{
		x = ins->fdef;
		while(x!=NULL)
		{
			if(strcmp(x->type,query[Temp_num].type)!=0)
			{
				printf("Insert data errer!\n");
				return;
			}
			if(query[Temp_num].length < x->length)
			{
				printf("Insert data errer!\n");
				return;
			}
			if((-query[Temp_num].length -1) > x->length)
			{
				printf("Insert data errer!\n");
				return;
			}
			Temp_num++;
			y = x->next_insert;
			x = y;
		}
	}
	
	if(ins->fdef!=NULL)
	{
		x = ins->fdef;
		while(x!=NULL)
		{
			fprintf(fp,"%s ",x->now);
			y = x->next_insert;
			x = y;
		}
		x = ins->fdef;
		ins->fdef=NULL;
		while(x!=NULL)
		{
			y = x->next_insert;
			free(x);
			x = y;
		}
	}
	free(ins);
	fprintf(fp,"\n");
	fclose(fp);
	printf("Insert finished\n");
	return;
}

//插入表第二种方法
void InsertTablesCol(struct InsertColumn * a, struct Insertstruct *ins)
{
	char Temp_tname[200];
	char Temp_cl[200];
	char Temp_ty[200];
	int Temp_num = 0;
	int Temp_length = 0;//临时读取创建表格时的type
	int i=0;
	
	int query_num = 0; //查询列的数目
	int col_num = 0;//列的数目 clo_num	
	int flag=1;		//先找到插入的列是否都存在；flag = 0 存在，flag = 1不存在, flag = 2 重复插入
	int col_index[100];
	int count = 0;	//循环变量
	
	char file_path[200]={""};
	char goal_path[200] = {""};//table路径
	struct insert_type query[150];	//查询type是否对应
	struct insert_type *x = NULL;	//遍历链表所需要指针
	struct insert_type *y = NULL;
	struct InsertColumns *p = NULL;	//遍历链表的列所需要的指针
	struct InsertColumns *q = NULL;	

	strcpy(file_path,use_db);
	strcat(file_path,ins->table);
	strcat(file_path,".txt");
	printf("%s\n",file_path);
	printf("Inserting......\n");
	strcpy(goal_path,use_db);
	strcat(goal_path,"sys.dat");
	//printf("%s\n",goal_path);	//查看插入表的type类型
	if((fp3=fopen(goal_path,"r"))==NULL)
	{
		printf("system error!\n");
		fclose(fp3);
		return;
	}
	while(fscanf(fp3,"%s%d%s%s%d",&Temp_tname,&Temp_num,&Temp_cl,&Temp_ty,&Temp_length)!=EOF)
	{
		if(strcmp(Temp_tname,ins->table)==0)
		{
			strcpy(query[Temp_num-1].type,Temp_ty);
			strcpy(query[Temp_num-1].col_name,Temp_cl);
			query[Temp_num-1].length = Temp_length;
			if(strcmp(Temp_ty,"int")==0)
			{
				query[Temp_num-1].length = 2147483647;
			}
			query_num = Temp_num-1;
			//printf("%s %s %d\n",query[Temp_num-1].col_name,query[Temp_num-1].type,query[Temp_num-1].length);
		}
	}
	fclose(fp3);
	//先找到插入的列是否都存在；flag = 0 存在，flag = 1不存在, flag = 2 重复插入
	//列的数目 clo_num
	for(i=0;i<100;i++)
	{
		col_index[i]=500;
	}
	p = a;
	q = p->next_col;
	p = q;
	col_num = 0;
	while(p!=NULL)
	{
		flag=1;
		//printf("%s %d\n",p->column_name, query_num);
		for(i=0;i<=query_num;i++)
		{
			if(strcmp(p->column_name,query[i].col_name)==0)
			{
				if(col_index[col_num]!=500)
				{	flag=2;	}
				else{
					col_index[col_num]=i;
					flag=0;
				}
				break;
			}
		}
		if(flag==2)
		{
			printf("Error: reinsert a data!\n");
			return;
		}
		if(flag==1)
		{
			printf("Error: column not exist!\n");
			return;
		}
		col_num++;
		q = p->next_col;
		p = q;
	}
	//现在判断column的, 计数循环变量
	if(ins->fdef!=NULL)
	{
		x = ins->fdef;
		while(x!=NULL)
		{
			int index = col_index[count];
			if(strcmp(x->type,query[index].type)!=0)
			{
				printf("Insert data errer!\n");
				return;
			}
			if(query[index].length < x->length)
			{
				printf("Insert data errer!\n");
				return;
			}
			if((-query[index].length -1) > x->length)
			{
				printf("Insert data errer!\n");
				return;
			}
			count++;
			y = x->next_insert;
			x = y;
		}
	}
	
	if((fp=fopen(file_path,"a+"))==NULL)
	{
		printf("system error!\n");
		fclose(fp);
		return;
	}
	//现在插入
	for(i=0;i<col_num;i++)
	{
		int min=600;
		int j=0;
		int j_pos = 0;
		for(j=0;j<col_num;j++)
		{
			if(col_index[j]<min)
			{
				min = col_index[j];
				j_pos = j;
			}
		}
		col_index[j_pos] = 600;
		count=0;
		x = ins->fdef;
		while(x!=NULL)
		{
			if(count==j_pos)
			{
				fprintf(fp,"%s ",x->now);
				break;
			}
			count++;
			y = x->next_insert;
			x = y;
		}
	}
	if(ins->fdef!=NULL)
	{
		x=ins->fdef;
		while(x!=NULL)
		{
			y = x->next_insert;
			free(x);
			x = y;
		}
	}
	fprintf(fp,"\n");
	fclose(fp);
	free(ins);
	printf("Insert successful\n");
	return;
}

void Select1(char *a)
{
	char goal_path[200] = {""};//table路径
	char res[500]={""};
	strcpy(goal_path,use_db);
	strcat(goal_path,a);
	printf("Result:			......\n");
	if((fp=fopen(goal_path,"r"))==NULL)
	{
		printf("system error!\n");
		fclose(fp);
		return;
	}
	while(fget(fp3, res)!=EOF)
	{
		puts(res);
	}
	fclose(fp);
	return;
}


#line 546 "myparser.c"
/* repeated because of possible precompiled header */
#include <yypars.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTPARSER

#include ".\myparser.h"

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/* (state) stack */
#if (YYSTACK_SIZE) != 0
static yystack_t YYNEAR yystack[(YYSTACK_SIZE)];
yystack_t YYFAR *YYNEAR YYDCDECL yysstackptr = yystack;
yystack_t YYFAR *YYNEAR YYDCDECL yystackptr = yystack;
#else
yystack_t YYFAR *YYNEAR YYDCDECL yysstackptr = NULL;
yystack_t YYFAR *YYNEAR YYDCDECL yystackptr = NULL;
#endif

/* attribute stack */
#if (YYSTACK_SIZE) != 0
static YYSTYPE YYNEAR yyattributestack[(YYSTACK_SIZE)];
#ifdef YYPROTOTYPE
void YYFAR *YYNEAR YYDCDECL yysattributestackptr = yyattributestack;
void YYFAR *YYNEAR YYDCDECL yyattributestackptr = yyattributestack;
#else
char YYFAR *YYNEAR YYDCDECL yysattributestackptr = (char YYFAR *) yyattributestack;
char YYFAR *YYNEAR YYDCDECL yyattributestackptr = (char YYFAR *) yyattributestack;
#endif
#else
#ifdef YYPROTOTYPE
void YYFAR *YYNEAR YYDCDECL yysattributestackptr = NULL;
void YYFAR *YYNEAR YYDCDECL yyattributestackptr = NULL;
#else
char YYFAR *YYNEAR YYDCDECL yysattributestackptr = NULL;
char YYFAR *YYNEAR YYDCDECL yyattributestackptr = NULL;
#endif
#endif

int YYNEAR YYDCDECL yysstack_size = (YYSTACK_SIZE);
int YYNEAR YYDCDECL yystack_size = (YYSTACK_SIZE);
int YYNEAR YYDCDECL yystack_max = (YYSTACK_MAX);

/* attributes */
YYSTYPE YYNEAR yyval;
YYSTYPE YYNEAR yylval;
#ifdef YYPROTOTYPE
void YYFAR *YYNEAR YYDCDECL yyvalptr = &yyval;
void YYFAR *YYNEAR YYDCDECL yylvalptr = &yylval;
#else
char YYFAR *YYNEAR YYDCDECL yyvalptr = (char *) &yyval;
char YYFAR *YYNEAR YYDCDECL yylvalptr = (char *) &yylval;
#endif

size_t YYNEAR YYDCDECL yyattribute_size = sizeof(YYSTYPE);

/* yyattribute */
#ifdef YYDEBUG
#ifdef YYPROTOTYPE
static YYSTYPE YYFAR *yyattribute1(int index)
#else
static YYSTYPE YYFAR *yyattribute1(index)
int index;
#endif
{
	YYSTYPE YYFAR *p = &((YYSTYPE YYFAR *) yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR *) yyattributestackptr)[yytop + (index)])
#endif

#ifdef YYDEBUG
#ifdef YYPROTOTYPE
static void yyinitdebug(YYSTYPE YYFAR **p, int count)
#else
static void yyinitdebug(p, count)
YYSTYPE YYFAR **p;
int count;
#endif
{
	int i;
	yyassert(p != NULL);
	yyassert(count >= 1);

	for (i = 0; i < count; i++) {
		p[i] = &((YYSTYPE YYFAR *) yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

#ifdef YYPROTOTYPE
void YYCDECL yyparseraction(int action)
#else
void YYCDECL yyparseraction(action)
int action;
#endif
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 535 ".\\myparser.y"
	printf("Create database successful!\n");	
#line 672 "myparser.c"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 538 ".\\myparser.y"

			int result;
			if(strcmp(file_name,use_db)==0)
			{	
				printf("Error! No use database!\n");
				return;
			}
			else
			{
				result = CreateTable(yyattribute(1 - 1).cs_var);
				if(result == 1){
					printf("Create Table %s Successful!\n",yyattribute(1 - 1).cs_var->table);
				}else{
					printf("Create Table %s Failed!\n",yyattribute(1 - 1).cs_var->table);
				}
			}
		
#line 701 "myparser.c"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 563 ".\\myparser.y"
	printf("%s\n",yyval.yych);CreateDB(yyval.yych);
#line 714 "myparser.c"
			}
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 568 ".\\myparser.y"
	UseDB(yyval.yych);
#line 727 "myparser.c"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[8];
			yyinitdebug(yya, 8);
#endif
			{
#line 572 ".\\myparser.y"

				yyval.cs_var=(struct Createstruct *)malloc(sizeof(struct Createstruct));
				yyval.cs_var->table = yyattribute(3 - 7).yych;
				yyval.cs_var->fdef = yyattribute(5 - 7).cfdef_var;
				printf("识别Key word：Create Table %s!\n",yyval.cs_var->table); 
			
#line 745 "myparser.c"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 581 ".\\myparser.y"

				ShowTables();
			
#line 760 "myparser.c"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[9];
			yyinitdebug(yya, 9);
#endif
			{
#line 587 ".\\myparser.y"

				yyval.yyinsertHead=(struct Createstruct *)malloc(sizeof(struct Createstruct));
				yyval.yyinsertHead->table = yyattribute(3 - 8).yych;
				yyval.yyinsertHead->fdef = yyattribute(6 - 8).yyinsert;
				InsertValues(yyval.yyinsertHead);
			
#line 778 "myparser.c"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[12];
			yyinitdebug(yya, 12);
#endif
			{
#line 594 ".\\myparser.y"

				//struct InsertColumns *z=NULL;
				//z = (struct InsertColumns *)malloc(sizeof(struct InsertColumns));
				//strcpy(z->column_name , $3);
				//z->next_col = $5;
				printf("识别table：%s\n",yyattribute(3 - 11).yych);
				yyval.yyinsertHead=(struct Createstruct *)malloc(sizeof(struct Createstruct));
				yyval.yyinsertHead->table = yyattribute(3 - 11).yych;
				yyval.yyinsertHead->fdef = yyattribute(9 - 11).yyinsert;
				InsertTablesCol(yyattribute(5 - 11).yycolum,yyval.yyinsertHead);
			
#line 801 "myparser.c"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[6];
			yyinitdebug(yya, 6);
#endif
			{
#line 610 ".\\myparser.y"

				Select1(yyattribute(4 - 5).yych);
			
#line 816 "myparser.c"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 627 ".\\myparser.y"

				yyval.yycolum = (struct InsertColumns *)malloc(sizeof(struct InsertColumns));
				strcpy(yyval.yycolum->column_name , yyattribute(1 - 1).yycolum);
				yyval.yycolum->next_col = yyattribute(1 - 1).yycolum;	
			
#line 833 "myparser.c"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 636 ".\\myparser.y"

				struct InsertColumns *x=NULL;
				x = (struct InsertColumns *)malloc(sizeof(struct InsertColumns));
				x = yyattribute(1 - 3).yycolum;
				x->next_col = yyattribute(1 - 3).yycolum->next_col;
				while(x->next_col!=NULL)
				{
					x = x->next_col;
				}
				x->next_col = yyattribute(3 - 3).yycolum;
			
#line 856 "myparser.c"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 650 ".\\myparser.y"
	
				yyval.yycolum = (struct InsertColumns *)malloc(sizeof(struct InsertColumns));
				strcpy(yyval.yycolum->column_name , yyattribute(1 - 1).yych);
				yyval.yycolum->next_col = NULL;
			
#line 873 "myparser.c"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 662 ".\\myparser.y"

				struct insert_type *y=NULL;
				y =(struct insert_type *)malloc(sizeof(struct insert_type));
				y = yyattribute(1 - 3).yyinsert;
				y->next_insert = yyattribute(1 - 3).yyinsert->next_insert;
				while(y->next_insert!=NULL)
				{
					y = y->next_insert;
				}
				y->next_insert = yyattribute(3 - 3).yyinsert;
			
#line 896 "myparser.c"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 675 ".\\myparser.y"

			yyval.yyinsert=(struct insert_type *)malloc(sizeof(struct insert_type));
			yyval.yyinsert->now = yyattribute(1 - 1).yych;
			strcpy(yyval.yyinsert->type,"char");
			yyval.yyinsert->length = strlen(yyattribute(1 - 1).yych);
			printf("识别char：%s\n",yyval.yyinsert->now);
			yyval.yyinsert->next_insert = NULL;
			
#line 916 "myparser.c"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 684 ".\\myparser.y"

			yyval.yyinsert=(struct insert_type *)malloc(sizeof(struct insert_type));
			yyval.yyinsert->now = yyattribute(1 - 1).yych;
			strcpy(yyval.yyinsert->type, "int");
			yyval.yyinsert->length = atoi(yyattribute(1 - 1).yych);
			printf("识别num：%s\n",yyval.yyinsert->now);
			yyval.yyinsert->next_insert = NULL;
			
#line 936 "myparser.c"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 697 ".\\myparser.y"

				struct Createfieldsdef *x=NULL;
				x =(struct Createfieldsdef *)malloc(sizeof(struct Createfieldsdef));
				x = yyattribute(1 - 3).cfdef_var;
				x->next_fdef = yyattribute(1 - 3).cfdef_var->next_fdef;
				while(x->next_fdef!=NULL)
				{
					x = x->next_fdef;
				}
				x->next_fdef = yyattribute(3 - 3).cfdef_var;
			
#line 959 "myparser.c"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[3];
			yyinitdebug(yya, 3);
#endif
			{
#line 711 ".\\myparser.y"

				yyval.cfdef_var=(struct Createfieldsdef *)malloc(sizeof(struct Createfieldsdef));
				yyval.cfdef_var->field = yyattribute(1 - 2).yych;
				yyval.cfdef_var->type = yyattribute(2 - 2).yytabletype;
				yyval.cfdef_var->next_fdef = NULL;
			
#line 977 "myparser.c"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[5];
			yyinitdebug(yya, 5);
#endif
			{
#line 722 ".\\myparser.y"
 
			yyval.yytabletype=(struct TableType *)malloc(sizeof(struct TableType));
			yyval.yytabletype->mytype = "char";
			printf("%s\n",yyattribute(3 - 4).yych);
			yyval.yytabletype->length = atoi(yyattribute(3 - 4).yych);
			printf("识别表中字符列！\n");
#line 995 "myparser.c"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 728 ".\\myparser.y"

			yyval.yytabletype=(struct TableType *)malloc(sizeof(struct TableType));
			yyval.yytabletype->mytype = "int";
			yyval.yytabletype->length = 4;
			printf("识别表中数字列！\n");
#line 1012 "myparser.c"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}
#ifdef YYDEBUG
YYCONST yysymbol_t YYNEARFAR YYBASED_CODE YYDCDECL yysymbol[] = {
	{ "$end", 0 },
	{ "\"(\"", 40 },
	{ "\")\"", 41 },
	{ "\"*\"", 42 },
	{ "\",\"", 44 },
	{ "\";\"", 59 },
	{ "error", 256 },
	{ "CREATE", 257 },
	{ "DATABASE", 258 },
	{ "USE", 259 },
	{ "TABLE", 260 },
	{ "INSERT", 261 },
	{ "INTO", 262 },
	{ "VALUES", 263 },
	{ "SHOW", 264 },
	{ "TABLES", 265 },
	{ "SELECT", 266 },
	{ "FROM", 267 },
	{ "CHAR", 268 },
	{ "INT", 269 },
	{ "NUMBER", 270 },
	{ "ID", 271 },
	{ NULL, 0 }
};

YYCONST char *YYCONST YYNEARFAR YYBASED_CODE YYDCDECL yyrule[] = {
	"$accept: starts",
	"starts: starts start",
	"starts: start",
	"start: crdb",
	"start: usedb",
	"start: create_table",
	"start: showtables",
	"start: insert_values",
	"start: selectact",
	"crdb: CREATE DATABASE crdb_name \";\"",
	"crdb_name: ID",
	"usedb: USE db_name \";\"",
	"db_name: ID",
	"create_table: CREATE TABLE table_name \"(\" tableinfo \")\" \";\"",
	"showtables: SHOW TABLES \";\"",
	"insert_values: INSERT INTO table_name VALUES \"(\" values_info \")\" \";\"",
	"insert_values: INSERT INTO table_name \"(\" scolumns \")\" VALUES \"(\" values_info \")\" \";\"",
	"selectact: SELECT \"*\" FROM table_name \";\"",
	"table_name: ID",
	"scolumns: columns",
	"columns: column",
	"columns: columns \",\" column",
	"column: ID",
	"values_info: pervalue",
	"values_info: values_info \",\" pervalue",
	"pervalue: ID",
	"pervalue: NUMBER",
	"tableinfo: field_type",
	"tableinfo: tableinfo \",\" field_type",
	"field_type: field type",
	"field: ID",
	"type: CHAR \"(\" NUMBER \")\"",
	"type: INT"
};
#endif

YYCONST yyreduction_t YYNEARFAR YYBASED_CODE YYDCDECL yyreduction[] = {
	{ 0, 1, -1 },
	{ 1, 2, -1 },
	{ 1, 1, -1 },
	{ 2, 1, 0 },
	{ 2, 1, -1 },
	{ 2, 1, 1 },
	{ 2, 1, -1 },
	{ 2, 1, -1 },
	{ 2, 1, -1 },
	{ 3, 4, -1 },
	{ 4, 1, 2 },
	{ 5, 3, -1 },
	{ 6, 1, 3 },
	{ 7, 7, 4 },
	{ 8, 3, 5 },
	{ 9, 8, 6 },
	{ 9, 11, 7 },
	{ 10, 5, 8 },
	{ 11, 1, -1 },
	{ 12, 1, 9 },
	{ 13, 1, -1 },
	{ 13, 3, 10 },
	{ 14, 1, 11 },
	{ 15, 1, -1 },
	{ 15, 3, 12 },
	{ 16, 1, 13 },
	{ 16, 1, 14 },
	{ 17, 1, -1 },
	{ 17, 3, 15 },
	{ 18, 2, 16 },
	{ 19, 1, -1 },
	{ 20, 4, 17 },
	{ 20, 1, 18 }
};

int YYNEAR YYDCDECL yytokenaction_size = 267;
YYCONST yytokenaction_t YYNEARFAR YYBASED_CODE YYDCDECL yytokenaction[] = {
	{ 6, YYAT_ACCEPT, 0 },
	{ 27, YYAT_SHIFT, 32 },
	{ 68, YYAT_SHIFT, 69 },
	{ 37, YYAT_SHIFT, 48 },
	{ 69, YYAT_SHIFT, 70 },
	{ 68, YYAT_SHIFT, 62 },
	{ 37, YYAT_SHIFT, 49 },
	{ 1, YYAT_SHIFT, 14 },
	{ 63, YYAT_SHIFT, 67 },
	{ 1, YYAT_SHIFT, 15 },
	{ 64, YYAT_SHIFT, 52 },
	{ 64, YYAT_SHIFT, 53 },
	{ 36, YYAT_SHIFT, 45 },
	{ 36, YYAT_SHIFT, 46 },
	{ 61, YYAT_SHIFT, 65 },
	{ 59, YYAT_SHIFT, 64 },
	{ 56, YYAT_SHIFT, 63 },
	{ 55, YYAT_SHIFT, 61 },
	{ 51, YYAT_SHIFT, 39 },
	{ 50, YYAT_SHIFT, 59 },
	{ 49, YYAT_SHIFT, 35 },
	{ 48, YYAT_SHIFT, 57 },
	{ 45, YYAT_SHIFT, 56 },
	{ 41, YYAT_SHIFT, 51 },
	{ 40, YYAT_SHIFT, 50 },
	{ 34, YYAT_SHIFT, 44 },
	{ 33, YYAT_SHIFT, 43 },
	{ 29, YYAT_SHIFT, 24 },
	{ 25, YYAT_SHIFT, 31 },
	{ 23, YYAT_SHIFT, 30 },
	{ 20, YYAT_SHIFT, 29 },
	{ 19, YYAT_SHIFT, 28 },
	{ 17, YYAT_SHIFT, 26 },
	{ 14, YYAT_SHIFT, 22 },
	{ 5, YYAT_SHIFT, 20 },
	{ 4, YYAT_SHIFT, 19 },
	{ 3, YYAT_SHIFT, 18 },
	{ 2, YYAT_SHIFT, 16 },
	{ 0, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ 27, YYAT_SHIFT, 33 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ 6, YYAT_SHIFT, 1 },
	{ -1, YYAT_ERROR, 0 },
	{ 6, YYAT_SHIFT, 2 },
	{ -1, YYAT_ERROR, 0 },
	{ 6, YYAT_SHIFT, 3 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ 6, YYAT_SHIFT, 4 },
	{ -1, YYAT_ERROR, 0 },
	{ 6, YYAT_SHIFT, 5 }
};

YYCONST yystateaction_t YYNEARFAR YYBASED_CODE YYDCDECL yystateaction[] = {
	{ 38, 1, YYAT_DEFAULT, 6 },
	{ -251, 1, YYAT_ERROR, 0 },
	{ -234, 1, YYAT_ERROR, 0 },
	{ -226, 1, YYAT_ERROR, 0 },
	{ -230, 1, YYAT_ERROR, 0 },
	{ -8, 1, YYAT_ERROR, 0 },
	{ 0, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 8 },
	{ 0, 0, YYAT_REDUCE, 7 },
	{ 0, 0, YYAT_REDUCE, 6 },
	{ 0, 0, YYAT_REDUCE, 5 },
	{ 0, 0, YYAT_REDUCE, 2 },
	{ 0, 0, YYAT_REDUCE, 3 },
	{ 0, 0, YYAT_REDUCE, 4 },
	{ -238, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_DEFAULT, 29 },
	{ 0, 0, YYAT_REDUCE, 12 },
	{ -27, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_DEFAULT, 29 },
	{ -28, 1, YYAT_ERROR, 0 },
	{ -237, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 1 },
	{ 0, 0, YYAT_REDUCE, 10 },
	{ -30, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 18 },
	{ -12, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 11 },
	{ -39, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 14 },
	{ -244, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 9 },
	{ 0, 0, YYAT_DEFAULT, 49 },
	{ 0, 0, YYAT_DEFAULT, 51 },
	{ -14, 1, YYAT_ERROR, 0 },
	{ -34, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 30 },
	{ -256, 1, YYAT_ERROR, 0 },
	{ -38, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 27 },
	{ 0, 0, YYAT_REDUCE, 22 },
	{ -17, 1, YYAT_ERROR, 0 },
	{ -21, 1, YYAT_REDUCE, 19 },
	{ 0, 0, YYAT_REDUCE, 20 },
	{ 0, 0, YYAT_DEFAULT, 64 },
	{ 0, 0, YYAT_REDUCE, 17 },
	{ -18, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 32 },
	{ 0, 0, YYAT_REDUCE, 29 },
	{ -38, 1, YYAT_ERROR, 0 },
	{ -251, 1, YYAT_ERROR, 0 },
	{ -244, 1, YYAT_ERROR, 0 },
	{ -253, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 26 },
	{ 0, 0, YYAT_REDUCE, 25 },
	{ 0, 0, YYAT_REDUCE, 23 },
	{ -24, 1, YYAT_DEFAULT, 68 },
	{ -254, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 13 },
	{ 0, 0, YYAT_REDUCE, 28 },
	{ -25, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 21 },
	{ -45, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_DEFAULT, 64 },
	{ -33, 1, YYAT_ERROR, 0 },
	{ -260, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 15 },
	{ 0, 0, YYAT_REDUCE, 24 },
	{ 0, 0, YYAT_REDUCE, 31 },
	{ -39, 1, YYAT_ERROR, 0 },
	{ -55, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 16 }
};

int YYNEAR YYDCDECL yynontermgoto_size = 27;

YYCONST yynontermgoto_t YYNEARFAR YYBASED_CODE YYDCDECL yynontermgoto[] = {
	{ 6, 21 },
	{ 6, 12 },
	{ 62, 66 },
	{ 6, 13 },
	{ 51, 60 },
	{ 6, 10 },
	{ 6, 9 },
	{ 6, 8 },
	{ 6, 7 },
	{ 32, 40 },
	{ 32, 41 },
	{ 32, 42 },
	{ 64, 68 },
	{ 64, 54 },
	{ 49, 58 },
	{ 49, 36 },
	{ 31, 37 },
	{ 31, 38 },
	{ 0, 6 },
	{ 0, 11 },
	{ 43, 55 },
	{ 36, 47 },
	{ 29, 34 },
	{ 18, 27 },
	{ 15, 25 },
	{ 14, 23 },
	{ 2, 17 }
};

YYCONST yystategoto_t YYNEARFAR YYBASED_CODE YYDCDECL yystategoto[] = {
	{ 17, 6 },
	{ 0, -1 },
	{ 20, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ -2, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 21, -1 },
	{ 13, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 12, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 11, -1 },
	{ 0, -1 },
	{ -1, 49 },
	{ -3, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 1, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 5, 64 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ -4, -1 },
	{ 0, -1 },
	{ -10, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ -14, -1 },
	{ 0, -1 },
	{ -3, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 }
};

YYCONST yydestructor_t YYNEARFAR *YYNEAR YYDCDECL yydestructorptr = NULL;

YYCONST yytokendest_t YYNEARFAR *YYNEAR YYDCDECL yytokendestptr = NULL;
int YYNEAR YYDCDECL yytokendest_size = 0;

YYCONST yytokendestbase_t YYNEARFAR *YYNEAR YYDCDECL yytokendestbaseptr = NULL;
int YYNEAR YYDCDECL yytokendestbase_size = 0;
#line 739 ".\\myparser.y"

int main(void)
{
	while(1)
	{
		yyparse();
	}
	return 0;
}
