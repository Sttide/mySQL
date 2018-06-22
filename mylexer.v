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
# mylexer.v
# Lex verbose file generated from mylexer.l.
# 
# Date: 06/22/18
# Time: 19:54:11
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  [ ]+

    2  CREATE

    3  DATABASE

    4  USE

    5  TABLE

    6  INSERT

    7  INTO

    8  VALUES

    9  SHOW

   10  TABLES

   11  SELECT

   12  FROM

   13  CHAR

   14  INT

   15  Exit

   16  [A-Za-z][A-Za-z0-9_]*

   17  [0-9]+("."[0-9]+)?(E[+-]?[0-9]+)?

   18  ","

   19  "("

   20  ")"

   21  "*"

   22  ";"


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x20               goto 3
	0x28               goto 4
	0x29               goto 5
	0x2a               goto 6
	0x2c               goto 7
	0x30 - 0x39 (10)   goto 8
	0x3b               goto 9
	0x41 - 0x42 (2)    goto 10
	0x43               goto 11
	0x44               goto 12
	0x45               goto 13
	0x46               goto 14
	0x47 - 0x48 (2)    goto 10
	0x49               goto 15
	0x4a - 0x52 (9)    goto 10
	0x53               goto 16
	0x54               goto 17
	0x55               goto 18
	0x56               goto 19
	0x57 - 0x5a (4)    goto 10
	0x61 - 0x62 (2)    goto 10
	0x63               goto 11
	0x64               goto 12
	0x65               goto 13
	0x66               goto 14
	0x67 - 0x68 (2)    goto 10
	0x69               goto 15
	0x6a - 0x72 (9)    goto 10
	0x73               goto 16
	0x74               goto 17
	0x75               goto 18
	0x76               goto 19
	0x77 - 0x7a (4)    goto 10


state 2
	^INITIAL

	0x20               goto 3
	0x28               goto 4
	0x29               goto 5
	0x2a               goto 6
	0x2c               goto 7
	0x30 - 0x39 (10)   goto 8
	0x3b               goto 9
	0x41 - 0x42 (2)    goto 10
	0x43               goto 11
	0x44               goto 12
	0x45               goto 13
	0x46               goto 14
	0x47 - 0x48 (2)    goto 10
	0x49               goto 15
	0x4a - 0x52 (9)    goto 10
	0x53               goto 16
	0x54               goto 17
	0x55               goto 18
	0x56               goto 19
	0x57 - 0x5a (4)    goto 10
	0x61 - 0x62 (2)    goto 10
	0x63               goto 11
	0x64               goto 12
	0x65               goto 13
	0x66               goto 14
	0x67 - 0x68 (2)    goto 10
	0x69               goto 15
	0x6a - 0x72 (9)    goto 10
	0x73               goto 16
	0x74               goto 17
	0x75               goto 18
	0x76               goto 19
	0x77 - 0x7a (4)    goto 10


state 3
	0x20               goto 3

	match 1


state 4
	match 19


state 5
	match 20


state 6
	match 21


state 7
	match 18


state 8
	0x2e               goto 20
	0x30 - 0x39 (10)   goto 8
	0x45               goto 21
	0x65               goto 21

	match 17


state 9
	match 22


state 10
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x5a (26)   goto 10
	0x5f               goto 10
	0x61 - 0x7a (26)   goto 10

	match 16


state 11
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x47 (7)    goto 10
	0x48               goto 22
	0x49 - 0x51 (9)    goto 10
	0x52               goto 23
	0x53 - 0x5a (8)    goto 10
	0x5f               goto 10
	0x61 - 0x67 (7)    goto 10
	0x68               goto 22
	0x69 - 0x71 (9)    goto 10
	0x72               goto 23
	0x73 - 0x7a (8)    goto 10

	match 16


state 12
	0x30 - 0x39 (10)   goto 10
	0x41               goto 24
	0x42 - 0x5a (25)   goto 10
	0x5f               goto 10
	0x61               goto 24
	0x62 - 0x7a (25)   goto 10

	match 16


state 13
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x57 (23)   goto 10
	0x58               goto 25
	0x59 - 0x5a (2)    goto 10
	0x5f               goto 10
	0x61 - 0x77 (23)   goto 10
	0x78               goto 25
	0x79 - 0x7a (2)    goto 10

	match 16


state 14
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x51 (17)   goto 10
	0x52               goto 26
	0x53 - 0x5a (8)    goto 10
	0x5f               goto 10
	0x61 - 0x71 (17)   goto 10
	0x72               goto 26
	0x73 - 0x7a (8)    goto 10

	match 16


state 15
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x4d (13)   goto 10
	0x4e               goto 27
	0x4f - 0x5a (12)   goto 10
	0x5f               goto 10
	0x61 - 0x6d (13)   goto 10
	0x6e               goto 27
	0x6f - 0x7a (12)   goto 10

	match 16


state 16
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x44 (4)    goto 10
	0x45               goto 28
	0x46 - 0x47 (2)    goto 10
	0x48               goto 29
	0x49 - 0x5a (18)   goto 10
	0x5f               goto 10
	0x61 - 0x64 (4)    goto 10
	0x65               goto 28
	0x66 - 0x67 (2)    goto 10
	0x68               goto 29
	0x69 - 0x7a (18)   goto 10

	match 16


state 17
	0x30 - 0x39 (10)   goto 10
	0x41               goto 30
	0x42 - 0x5a (25)   goto 10
	0x5f               goto 10
	0x61               goto 30
	0x62 - 0x7a (25)   goto 10

	match 16


state 18
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x52 (18)   goto 10
	0x53               goto 31
	0x54 - 0x5a (7)    goto 10
	0x5f               goto 10
	0x61 - 0x72 (18)   goto 10
	0x73               goto 31
	0x74 - 0x7a (7)    goto 10

	match 16


state 19
	0x30 - 0x39 (10)   goto 10
	0x41               goto 32
	0x42 - 0x5a (25)   goto 10
	0x5f               goto 10
	0x61               goto 32
	0x62 - 0x7a (25)   goto 10

	match 16


state 20
	0x30 - 0x39 (10)   goto 33


state 21
	0x2b               goto 34
	0x2d               goto 34
	0x30 - 0x39 (10)   goto 35


state 22
	0x30 - 0x39 (10)   goto 10
	0x41               goto 36
	0x42 - 0x5a (25)   goto 10
	0x5f               goto 10
	0x61               goto 36
	0x62 - 0x7a (25)   goto 10

	match 16


state 23
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x44 (4)    goto 10
	0x45               goto 37
	0x46 - 0x5a (21)   goto 10
	0x5f               goto 10
	0x61 - 0x64 (4)    goto 10
	0x65               goto 37
	0x66 - 0x7a (21)   goto 10

	match 16


state 24
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x53 (19)   goto 10
	0x54               goto 38
	0x55 - 0x5a (6)    goto 10
	0x5f               goto 10
	0x61 - 0x73 (19)   goto 10
	0x74               goto 38
	0x75 - 0x7a (6)    goto 10

	match 16


state 25
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x48 (8)    goto 10
	0x49               goto 39
	0x4a - 0x5a (17)   goto 10
	0x5f               goto 10
	0x61 - 0x68 (8)    goto 10
	0x69               goto 39
	0x6a - 0x7a (17)   goto 10

	match 16


state 26
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x4e (14)   goto 10
	0x4f               goto 40
	0x50 - 0x5a (11)   goto 10
	0x5f               goto 10
	0x61 - 0x6e (14)   goto 10
	0x6f               goto 40
	0x70 - 0x7a (11)   goto 10

	match 16


state 27
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x52 (18)   goto 10
	0x53               goto 41
	0x54               goto 42
	0x55 - 0x5a (6)    goto 10
	0x5f               goto 10
	0x61 - 0x72 (18)   goto 10
	0x73               goto 41
	0x74               goto 42
	0x75 - 0x7a (6)    goto 10

	match 16


state 28
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x4b (11)   goto 10
	0x4c               goto 43
	0x4d - 0x5a (14)   goto 10
	0x5f               goto 10
	0x61 - 0x6b (11)   goto 10
	0x6c               goto 43
	0x6d - 0x7a (14)   goto 10

	match 16


state 29
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x4e (14)   goto 10
	0x4f               goto 44
	0x50 - 0x5a (11)   goto 10
	0x5f               goto 10
	0x61 - 0x6e (14)   goto 10
	0x6f               goto 44
	0x70 - 0x7a (11)   goto 10

	match 16


state 30
	0x30 - 0x39 (10)   goto 10
	0x41               goto 10
	0x42               goto 45
	0x43 - 0x5a (24)   goto 10
	0x5f               goto 10
	0x61               goto 10
	0x62               goto 45
	0x63 - 0x7a (24)   goto 10

	match 16


state 31
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x44 (4)    goto 10
	0x45               goto 46
	0x46 - 0x5a (21)   goto 10
	0x5f               goto 10
	0x61 - 0x64 (4)    goto 10
	0x65               goto 46
	0x66 - 0x7a (21)   goto 10

	match 16


state 32
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x4b (11)   goto 10
	0x4c               goto 47
	0x4d - 0x5a (14)   goto 10
	0x5f               goto 10
	0x61 - 0x6b (11)   goto 10
	0x6c               goto 47
	0x6d - 0x7a (14)   goto 10

	match 16


state 33
	0x30 - 0x39 (10)   goto 33
	0x45               goto 21
	0x65               goto 21

	match 17


state 34
	0x30 - 0x39 (10)   goto 35


state 35
	0x30 - 0x39 (10)   goto 35

	match 17


state 36
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x51 (17)   goto 10
	0x52               goto 48
	0x53 - 0x5a (8)    goto 10
	0x5f               goto 10
	0x61 - 0x71 (17)   goto 10
	0x72               goto 48
	0x73 - 0x7a (8)    goto 10

	match 16


state 37
	0x30 - 0x39 (10)   goto 10
	0x41               goto 49
	0x42 - 0x5a (25)   goto 10
	0x5f               goto 10
	0x61               goto 49
	0x62 - 0x7a (25)   goto 10

	match 16


state 38
	0x30 - 0x39 (10)   goto 10
	0x41               goto 50
	0x42 - 0x5a (25)   goto 10
	0x5f               goto 10
	0x61               goto 50
	0x62 - 0x7a (25)   goto 10

	match 16


state 39
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x53 (19)   goto 10
	0x54               goto 51
	0x55 - 0x5a (6)    goto 10
	0x5f               goto 10
	0x61 - 0x73 (19)   goto 10
	0x74               goto 51
	0x75 - 0x7a (6)    goto 10

	match 16


state 40
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x4c (12)   goto 10
	0x4d               goto 52
	0x4e - 0x5a (13)   goto 10
	0x5f               goto 10
	0x61 - 0x6c (12)   goto 10
	0x6d               goto 52
	0x6e - 0x7a (13)   goto 10

	match 16


state 41
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x44 (4)    goto 10
	0x45               goto 53
	0x46 - 0x5a (21)   goto 10
	0x5f               goto 10
	0x61 - 0x64 (4)    goto 10
	0x65               goto 53
	0x66 - 0x7a (21)   goto 10

	match 16


state 42
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x4e (14)   goto 10
	0x4f               goto 54
	0x50 - 0x5a (11)   goto 10
	0x5f               goto 10
	0x61 - 0x6e (14)   goto 10
	0x6f               goto 54
	0x70 - 0x7a (11)   goto 10

	match 14


state 43
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x44 (4)    goto 10
	0x45               goto 55
	0x46 - 0x5a (21)   goto 10
	0x5f               goto 10
	0x61 - 0x64 (4)    goto 10
	0x65               goto 55
	0x66 - 0x7a (21)   goto 10

	match 16


state 44
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x56 (22)   goto 10
	0x57               goto 56
	0x58 - 0x5a (3)    goto 10
	0x5f               goto 10
	0x61 - 0x76 (22)   goto 10
	0x77               goto 56
	0x78 - 0x7a (3)    goto 10

	match 16


state 45
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x4b (11)   goto 10
	0x4c               goto 57
	0x4d - 0x5a (14)   goto 10
	0x5f               goto 10
	0x61 - 0x6b (11)   goto 10
	0x6c               goto 57
	0x6d - 0x7a (14)   goto 10

	match 16


state 46
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x5a (26)   goto 10
	0x5f               goto 10
	0x61 - 0x7a (26)   goto 10

	match 4


state 47
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x54 (20)   goto 10
	0x55               goto 58
	0x56 - 0x5a (5)    goto 10
	0x5f               goto 10
	0x61 - 0x74 (20)   goto 10
	0x75               goto 58
	0x76 - 0x7a (5)    goto 10

	match 16


state 48
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x5a (26)   goto 10
	0x5f               goto 10
	0x61 - 0x7a (26)   goto 10

	match 13


state 49
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x53 (19)   goto 10
	0x54               goto 59
	0x55 - 0x5a (6)    goto 10
	0x5f               goto 10
	0x61 - 0x73 (19)   goto 10
	0x74               goto 59
	0x75 - 0x7a (6)    goto 10

	match 16


state 50
	0x30 - 0x39 (10)   goto 10
	0x41               goto 10
	0x42               goto 60
	0x43 - 0x5a (24)   goto 10
	0x5f               goto 10
	0x61               goto 10
	0x62               goto 60
	0x63 - 0x7a (24)   goto 10

	match 16


state 51
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x5a (26)   goto 10
	0x5f               goto 10
	0x61 - 0x7a (26)   goto 10

	match 15


state 52
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x5a (26)   goto 10
	0x5f               goto 10
	0x61 - 0x7a (26)   goto 10

	match 12


state 53
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x51 (17)   goto 10
	0x52               goto 61
	0x53 - 0x5a (8)    goto 10
	0x5f               goto 10
	0x61 - 0x71 (17)   goto 10
	0x72               goto 61
	0x73 - 0x7a (8)    goto 10

	match 16


state 54
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x5a (26)   goto 10
	0x5f               goto 10
	0x61 - 0x7a (26)   goto 10

	match 7


state 55
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x42 (2)    goto 10
	0x43               goto 62
	0x44 - 0x5a (23)   goto 10
	0x5f               goto 10
	0x61 - 0x62 (2)    goto 10
	0x63               goto 62
	0x64 - 0x7a (23)   goto 10

	match 16


state 56
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x5a (26)   goto 10
	0x5f               goto 10
	0x61 - 0x7a (26)   goto 10

	match 9


state 57
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x44 (4)    goto 10
	0x45               goto 63
	0x46 - 0x5a (21)   goto 10
	0x5f               goto 10
	0x61 - 0x64 (4)    goto 10
	0x65               goto 63
	0x66 - 0x7a (21)   goto 10

	match 16


state 58
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x44 (4)    goto 10
	0x45               goto 64
	0x46 - 0x5a (21)   goto 10
	0x5f               goto 10
	0x61 - 0x64 (4)    goto 10
	0x65               goto 64
	0x66 - 0x7a (21)   goto 10

	match 16


state 59
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x44 (4)    goto 10
	0x45               goto 65
	0x46 - 0x5a (21)   goto 10
	0x5f               goto 10
	0x61 - 0x64 (4)    goto 10
	0x65               goto 65
	0x66 - 0x7a (21)   goto 10

	match 16


state 60
	0x30 - 0x39 (10)   goto 10
	0x41               goto 66
	0x42 - 0x5a (25)   goto 10
	0x5f               goto 10
	0x61               goto 66
	0x62 - 0x7a (25)   goto 10

	match 16


state 61
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x53 (19)   goto 10
	0x54               goto 67
	0x55 - 0x5a (6)    goto 10
	0x5f               goto 10
	0x61 - 0x73 (19)   goto 10
	0x74               goto 67
	0x75 - 0x7a (6)    goto 10

	match 16


state 62
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x53 (19)   goto 10
	0x54               goto 68
	0x55 - 0x5a (6)    goto 10
	0x5f               goto 10
	0x61 - 0x73 (19)   goto 10
	0x74               goto 68
	0x75 - 0x7a (6)    goto 10

	match 16


state 63
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x52 (18)   goto 10
	0x53               goto 69
	0x54 - 0x5a (7)    goto 10
	0x5f               goto 10
	0x61 - 0x72 (18)   goto 10
	0x73               goto 69
	0x74 - 0x7a (7)    goto 10

	match 5


state 64
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x52 (18)   goto 10
	0x53               goto 70
	0x54 - 0x5a (7)    goto 10
	0x5f               goto 10
	0x61 - 0x72 (18)   goto 10
	0x73               goto 70
	0x74 - 0x7a (7)    goto 10

	match 16


state 65
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x5a (26)   goto 10
	0x5f               goto 10
	0x61 - 0x7a (26)   goto 10

	match 2


state 66
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x52 (18)   goto 10
	0x53               goto 71
	0x54 - 0x5a (7)    goto 10
	0x5f               goto 10
	0x61 - 0x72 (18)   goto 10
	0x73               goto 71
	0x74 - 0x7a (7)    goto 10

	match 16


state 67
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x5a (26)   goto 10
	0x5f               goto 10
	0x61 - 0x7a (26)   goto 10

	match 6


state 68
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x5a (26)   goto 10
	0x5f               goto 10
	0x61 - 0x7a (26)   goto 10

	match 11


state 69
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x5a (26)   goto 10
	0x5f               goto 10
	0x61 - 0x7a (26)   goto 10

	match 10


state 70
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x5a (26)   goto 10
	0x5f               goto 10
	0x61 - 0x7a (26)   goto 10

	match 8


state 71
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x44 (4)    goto 10
	0x45               goto 72
	0x46 - 0x5a (21)   goto 10
	0x5f               goto 10
	0x61 - 0x64 (4)    goto 10
	0x65               goto 72
	0x66 - 0x7a (21)   goto 10

	match 16


state 72
	0x30 - 0x39 (10)   goto 10
	0x41 - 0x5a (26)   goto 10
	0x5f               goto 10
	0x61 - 0x7a (26)   goto 10

	match 3


#############################################################################
# Summary
#############################################################################

1 start state(s)
22 expression(s), 72 state(s)


#############################################################################
# End of File
#############################################################################
