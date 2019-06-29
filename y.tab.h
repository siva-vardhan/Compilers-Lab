/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM = 258,
    ID = 259,
    BEG = 260,
    END = 261,
    READ = 262,
    WRITE = 263,
    IF = 264,
    THEN = 265,
    ELSE = 266,
    ENDIF = 267,
    WHILE = 268,
    DO = 269,
    ENDWHILE = 270,
    L = 271,
    G = 272,
    LE = 273,
    GE = 274,
    NE = 275,
    EE = 276,
    REPEAT = 277,
    UNTIL = 278,
    BREAK = 279,
    CONTINUE = 280,
    DECL = 281,
    ENDDECL = 282,
    INT = 283,
    STR = 284,
    STRVAL = 285,
    MAIN = 286,
    RETURN = 287,
    TYPE = 288,
    ENDTYPE = 289,
    NUL = 290,
    ALLOC = 291,
    DEALLOC = 292,
    BOOLEAN = 293,
    VOID = 294,
    INIT = 295,
    CLASS = 296,
    ENDCLASS = 297,
    SELF = 298,
    NEW = 299,
    DELETE = 300,
    EXTENDS = 301
  };
#endif
/* Tokens.  */
#define NUM 258
#define ID 259
#define BEG 260
#define END 261
#define READ 262
#define WRITE 263
#define IF 264
#define THEN 265
#define ELSE 266
#define ENDIF 267
#define WHILE 268
#define DO 269
#define ENDWHILE 270
#define L 271
#define G 272
#define LE 273
#define GE 274
#define NE 275
#define EE 276
#define REPEAT 277
#define UNTIL 278
#define BREAK 279
#define CONTINUE 280
#define DECL 281
#define ENDDECL 282
#define INT 283
#define STR 284
#define STRVAL 285
#define MAIN 286
#define RETURN 287
#define TYPE 288
#define ENDTYPE 289
#define NUL 290
#define ALLOC 291
#define DEALLOC 292
#define BOOLEAN 293
#define VOID 294
#define INIT 295
#define CLASS 296
#define ENDCLASS 297
#define SELF 298
#define NEW 299
#define DELETE 300
#define EXTENDS 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
