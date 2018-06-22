#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 66 of your 30 day trial period.
# 
# This file was produced by an UNREGISTERED COPY of Parser Generator. It is
# for evaluation purposes only. If you continue to use Parser Generator 30
# days after installation then you are required to purchase a license. For
# more information see the online help or go to the Bumble-Bee Software
# homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# myparser.v
# YACC verbose file generated from myparser.y.
# 
# Date: 06/22/18
# Time: 19:54:11
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : starts $end

    1  starts : starts start
    2         | start

    3  start : crdb
    4        | usedb
    5        | create_table
    6        | showtables
    7        | insert_values
    8        | selectact

    9  crdb : CREATE DATABASE crdb_name ";"

   10  crdb_name : ID

   11  usedb : USE db_name ";"

   12  db_name : ID

   13  create_table : CREATE TABLE table_name "(" tableinfo ")" ";"

   14  showtables : SHOW TABLES ";"

   15  insert_values : INSERT INTO table_name VALUES "(" values_info ")" ";"
   16                | INSERT INTO table_name "(" scolumns ")" VALUES "(" values_info ")" ";"

   17  selectact : SELECT "*" FROM table_name ";"

   18  table_name : ID

   19  scolumns : columns

   20  columns : column
   21          | columns "," column

   22  column : ID

   23  values_info : pervalue
   24              | values_info "," pervalue

   25  pervalue : ID
   26           | NUMBER

   27  tableinfo : field_type
   28            | tableinfo "," field_type

   29  field_type : field type

   30  field : ID

   31  type : CHAR "(" NUMBER ")"
   32       | INT


##############################################################################
# States
##############################################################################

state 0
	$accept : . starts $end

	CREATE  shift 1
	USE  shift 2
	INSERT  shift 3
	SHOW  shift 4
	SELECT  shift 5

	starts  goto 6
	selectact  goto 7
	insert_values  goto 8
	showtables  goto 9
	create_table  goto 10
	start  goto 11
	crdb  goto 12
	usedb  goto 13


state 1
	crdb : CREATE . DATABASE crdb_name ";"
	create_table : CREATE . TABLE table_name "(" tableinfo ")" ";"

	DATABASE  shift 14
	TABLE  shift 15


state 2
	usedb : USE . db_name ";"

	ID  shift 16

	db_name  goto 17


state 3
	insert_values : INSERT . INTO table_name VALUES "(" values_info ")" ";"
	insert_values : INSERT . INTO table_name "(" scolumns ")" VALUES "(" values_info ")" ";"

	INTO  shift 18


state 4
	showtables : SHOW . TABLES ";"

	TABLES  shift 19


state 5
	selectact : SELECT . "*" FROM table_name ";"

	"*"  shift 20


state 6
	$accept : starts . $end  (0)
	starts : starts . start

	$end  accept
	CREATE  shift 1
	USE  shift 2
	INSERT  shift 3
	SHOW  shift 4
	SELECT  shift 5

	selectact  goto 7
	insert_values  goto 8
	showtables  goto 9
	create_table  goto 10
	start  goto 21
	crdb  goto 12
	usedb  goto 13


state 7
	start : selectact .  (8)

	.  reduce 8


state 8
	start : insert_values .  (7)

	.  reduce 7


state 9
	start : showtables .  (6)

	.  reduce 6


state 10
	start : create_table .  (5)

	.  reduce 5


state 11
	starts : start .  (2)

	.  reduce 2


state 12
	start : crdb .  (3)

	.  reduce 3


state 13
	start : usedb .  (4)

	.  reduce 4


state 14
	crdb : CREATE DATABASE . crdb_name ";"

	ID  shift 22

	crdb_name  goto 23


state 15
	create_table : CREATE TABLE . table_name "(" tableinfo ")" ";"

	ID  shift 24

	table_name  goto 25


state 16
	db_name : ID .  (12)

	.  reduce 12


state 17
	usedb : USE db_name . ";"

	";"  shift 26


state 18
	insert_values : INSERT INTO . table_name VALUES "(" values_info ")" ";"
	insert_values : INSERT INTO . table_name "(" scolumns ")" VALUES "(" values_info ")" ";"

	ID  shift 24

	table_name  goto 27


state 19
	showtables : SHOW TABLES . ";"

	";"  shift 28


state 20
	selectact : SELECT "*" . FROM table_name ";"

	FROM  shift 29


state 21
	starts : starts start .  (1)

	.  reduce 1


state 22
	crdb_name : ID .  (10)

	.  reduce 10


state 23
	crdb : CREATE DATABASE crdb_name . ";"

	";"  shift 30


state 24
	table_name : ID .  (18)

	.  reduce 18


state 25
	create_table : CREATE TABLE table_name . "(" tableinfo ")" ";"

	"("  shift 31


state 26
	usedb : USE db_name ";" .  (11)

	.  reduce 11


state 27
	insert_values : INSERT INTO table_name . VALUES "(" values_info ")" ";"
	insert_values : INSERT INTO table_name . "(" scolumns ")" VALUES "(" values_info ")" ";"

	"("  shift 32
	VALUES  shift 33


state 28
	showtables : SHOW TABLES ";" .  (14)

	.  reduce 14


state 29
	selectact : SELECT "*" FROM . table_name ";"

	ID  shift 24

	table_name  goto 34


state 30
	crdb : CREATE DATABASE crdb_name ";" .  (9)

	.  reduce 9


state 31
	create_table : CREATE TABLE table_name "(" . tableinfo ")" ";"

	ID  shift 35

	field  goto 36
	tableinfo  goto 37
	field_type  goto 38


state 32
	insert_values : INSERT INTO table_name "(" . scolumns ")" VALUES "(" values_info ")" ";"

	ID  shift 39

	scolumns  goto 40
	columns  goto 41
	column  goto 42


state 33
	insert_values : INSERT INTO table_name VALUES . "(" values_info ")" ";"

	"("  shift 43


state 34
	selectact : SELECT "*" FROM table_name . ";"

	";"  shift 44


state 35
	field : ID .  (30)

	.  reduce 30


state 36
	field_type : field . type

	CHAR  shift 45
	INT  shift 46

	type  goto 47


state 37
	create_table : CREATE TABLE table_name "(" tableinfo . ")" ";"
	tableinfo : tableinfo . "," field_type

	")"  shift 48
	","  shift 49


state 38
	tableinfo : field_type .  (27)

	.  reduce 27


state 39
	column : ID .  (22)

	.  reduce 22


state 40
	insert_values : INSERT INTO table_name "(" scolumns . ")" VALUES "(" values_info ")" ";"

	")"  shift 50


state 41
	scolumns : columns .  (19)
	columns : columns . "," column

	","  shift 51
	.  reduce 19


state 42
	columns : column .  (20)

	.  reduce 20


state 43
	insert_values : INSERT INTO table_name VALUES "(" . values_info ")" ";"

	NUMBER  shift 52
	ID  shift 53

	pervalue  goto 54
	values_info  goto 55


state 44
	selectact : SELECT "*" FROM table_name ";" .  (17)

	.  reduce 17


state 45
	type : CHAR . "(" NUMBER ")"

	"("  shift 56


state 46
	type : INT .  (32)

	.  reduce 32


state 47
	field_type : field type .  (29)

	.  reduce 29


state 48
	create_table : CREATE TABLE table_name "(" tableinfo ")" . ";"

	";"  shift 57


state 49
	tableinfo : tableinfo "," . field_type

	ID  shift 35

	field  goto 36
	field_type  goto 58


state 50
	insert_values : INSERT INTO table_name "(" scolumns ")" . VALUES "(" values_info ")" ";"

	VALUES  shift 59


state 51
	columns : columns "," . column

	ID  shift 39

	column  goto 60


state 52
	pervalue : NUMBER .  (26)

	.  reduce 26


state 53
	pervalue : ID .  (25)

	.  reduce 25


state 54
	values_info : pervalue .  (23)

	.  reduce 23


state 55
	insert_values : INSERT INTO table_name VALUES "(" values_info . ")" ";"
	values_info : values_info . "," pervalue

	")"  shift 61
	","  shift 62


state 56
	type : CHAR "(" . NUMBER ")"

	NUMBER  shift 63


state 57
	create_table : CREATE TABLE table_name "(" tableinfo ")" ";" .  (13)

	.  reduce 13


state 58
	tableinfo : tableinfo "," field_type .  (28)

	.  reduce 28


state 59
	insert_values : INSERT INTO table_name "(" scolumns ")" VALUES . "(" values_info ")" ";"

	"("  shift 64


state 60
	columns : columns "," column .  (21)

	.  reduce 21


state 61
	insert_values : INSERT INTO table_name VALUES "(" values_info ")" . ";"

	";"  shift 65


state 62
	values_info : values_info "," . pervalue

	NUMBER  shift 52
	ID  shift 53

	pervalue  goto 66


state 63
	type : CHAR "(" NUMBER . ")"

	")"  shift 67


state 64
	insert_values : INSERT INTO table_name "(" scolumns ")" VALUES "(" . values_info ")" ";"

	NUMBER  shift 52
	ID  shift 53

	pervalue  goto 54
	values_info  goto 68


state 65
	insert_values : INSERT INTO table_name VALUES "(" values_info ")" ";" .  (15)

	.  reduce 15


state 66
	values_info : values_info "," pervalue .  (24)

	.  reduce 24


state 67
	type : CHAR "(" NUMBER ")" .  (31)

	.  reduce 31


state 68
	insert_values : INSERT INTO table_name "(" scolumns ")" VALUES "(" values_info . ")" ";"
	values_info : values_info . "," pervalue

	")"  shift 69
	","  shift 62


state 69
	insert_values : INSERT INTO table_name "(" scolumns ")" VALUES "(" values_info ")" . ";"

	";"  shift 70


state 70
	insert_values : INSERT INTO table_name "(" scolumns ")" VALUES "(" values_info ")" ";" .  (16)

	.  reduce 16


##############################################################################
# Summary
##############################################################################

22 token(s), 21 nonterminal(s)
33 grammar rule(s), 71 state(s)


##############################################################################
# End of File
##############################################################################
