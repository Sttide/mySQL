%{
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

%}

//mysql数据结构
%union
{	
	int yyint;
	char * yych;
	struct Createfieldsdef *cfdef_var;
	struct Createstruct *cs_var;
	struct TableType *yytabletype;
	struct insert_type *yyinsert;
	struct Insertstruct *yyinsertHead;
	struct InsertColumns *yycolum;
}
%term CREATE DATABASE USE TABLE INSERT INTO VALUES SHOW TABLES SELECT FROM CHAR INT  //无优先级和结合性
%term <yych> NUMBER ID 
%nonterm <yytabletype> type  //type 创建表；	
%nonterm <yych> crdb  table_name db_name crdb_name field showtables	selectact//字符类型、创建表
%nonterm <yyinsert> values_info pervalue	//插入
%nonterm <yyinsertHead> insert_values		//插入
%nonterm <yycolum>	columns	scolumns column	//插入
%nonterm <cfdef_var> tableinfo field_type	//创建表
%nonterm <cs_var> create_table				//创建表


%%

starts: starts start | start;
	
start : crdb  //创建数据库
		{	printf("Create database successful!\n");	}
	  | usedb  //use 数据库
	  | create_table  //create table
		{
			int result;
			if(strcmp(file_name,use_db)==0)
			{	
				printf("Error! No use database!\n");
				return;
			}
			else
			{
				result = CreateTable($1);
				if(result == 1){
					printf("Create Table %s Successful!\n",$1->table);
				}else{
					printf("Create Table %s Failed!\n",$1->table);
				}
			}
		}
	   |	showtables
	   |	insert_values
	   |	selectact
	  ;
//创建数据库
crdb: CREATE DATABASE crdb_name ";"
	;

crdb_name:ID{	printf("%s\n",$$);CreateDB($$);};

//use 数据库
usedb : USE db_name ";";

db_name : ID{	UseDB($$);};	
	
	
create_table: CREATE TABLE table_name "(" tableinfo ")" ";" 
			{
				$$=(struct Createstruct *)malloc(sizeof(struct Createstruct));
				$$->table = $3;
				$$->fdef = $5;
				printf("识别Key word：Create Table %s!\n",$$->table); 
			}
		;

showtables:	SHOW TABLES ";"
			{
				ShowTables();
			}
		;
////////////////
insert_values:	INSERT INTO table_name VALUES "(" values_info ")" ";"
			{
				$$=(struct Createstruct *)malloc(sizeof(struct Createstruct));
				$$->table = $3;
				$$->fdef = $6;
				InsertValues($$);
			}
			|	INSERT INTO table_name "(" scolumns ")" VALUES "(" values_info ")"  ";"
			{
				//struct InsertColumns *z=NULL;
				//z = (struct InsertColumns *)malloc(sizeof(struct InsertColumns));
				//strcpy(z->column_name , $3);
				//z->next_col = $5;
				printf("识别table：%s\n",$3);
				$$=(struct Createstruct *)malloc(sizeof(struct Createstruct));
				$$->table = $3;
				$$->fdef = $9;
				InsertTablesCol($5,$$);
			}
			;
////////////////

//选择开始了
selectact	:SELECT "*" FROM table_name ";"
			{
				Select1($4);
			}
		;
			








////////////////
table_name:ID
		;
scolumns:	columns
			{
				$$ = (struct InsertColumns *)malloc(sizeof(struct InsertColumns));
				strcpy($$->column_name , $1);
				$$->next_col = $1;	
			}
		;

columns :	column
		|	columns "," column
			{
				struct InsertColumns *x=NULL;
				x = (struct InsertColumns *)malloc(sizeof(struct InsertColumns));
				x = $1;
				x->next_col = $1->next_col;
				while(x->next_col!=NULL)
				{
					x = x->next_col;
				}
				x->next_col = $3;
			}
		;
		
column	:	ID
			{	
				$$ = (struct InsertColumns *)malloc(sizeof(struct InsertColumns));
				strcpy($$->column_name , $1);
				$$->next_col = NULL;
			}
		;
////////////////////



values_info: pervalue
			|values_info "," pervalue
			{
				struct insert_type *y=NULL;
				y =(struct insert_type *)malloc(sizeof(struct insert_type));
				y = $1;
				y->next_insert = $1->next_insert;
				while(y->next_insert!=NULL)
				{
					y = y->next_insert;
				}
				y->next_insert = $3;
			}
			;
pervalue: ID
		  {
			$$=(struct insert_type *)malloc(sizeof(struct insert_type));
			$$->now = $1;
			strcpy($$->type,"char");
			$$->length = strlen($1);
			printf("识别char：%s\n",$$->now);
			$$->next_insert = NULL;
			}
		| NUMBER
		  {
			$$=(struct insert_type *)malloc(sizeof(struct insert_type));
			$$->now = $1;
			strcpy($$->type, "int");
			$$->length = atoi($1);
			printf("识别num：%s\n",$$->now);
			$$->next_insert = NULL;
			}
		;
////////////////////		

tableinfo : field_type
		  | tableinfo "," field_type
			{
				struct Createfieldsdef *x=NULL;
				x =(struct Createfieldsdef *)malloc(sizeof(struct Createfieldsdef));
				x = $1;
				x->next_fdef = $1->next_fdef;
				while(x->next_fdef!=NULL)
				{
					x = x->next_fdef;
				}
				x->next_fdef = $3;
			}
		  ;
		  
field_type: field type
			{
				$$=(struct Createfieldsdef *)malloc(sizeof(struct Createfieldsdef));
				$$->field = $1;
				$$->type = $2;
				$$->next_fdef = NULL;
			}
		  ;
		  
field : ID
	  ;
	  
type  : CHAR "(" NUMBER ")"{ 
			$$=(struct TableType *)malloc(sizeof(struct TableType));
			$$->mytype = "char";
			printf("%s\n",$3);
			$$->length = atoi($3);
			printf("识别表中字符列！\n");}
	  | INT{
			$$=(struct TableType *)malloc(sizeof(struct TableType));
			$$->mytype = "int";
			$$->length = 4;
			printf("识别表中数字列！\n");} 
	  ;



//CREATE TABLE Stu (sname CHAR (100)) ;

%%
int main(void)
{
	while(1)
	{
		yyparse();
	}
	return 0;
}