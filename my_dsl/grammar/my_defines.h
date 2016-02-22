#ifndef CONF_DEFINES_H
#define CONF_DEFINES_H

#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdio>

#include "interpretor.h"
#include "expression.h"

struct MY_DSL_Type
{
    string               identifier;
    ParameterList       *parameter_list;
    ArgumentList        *argument_list;
    Expression          *expression;
    Statement           *statement;
    StatementList       *statement_list;
    Block               *block;
    Elsif               *elsif;
    Assignment_Operator  assignment_operator;
    Value_Type         type_specifier;
};

#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void *yyscan_t;
#endif

#ifdef YYTOKENTYPE
#undef YYTOKENTYPE
#endif

#define YYSTYPE MY_DSL_Type

extern int my_dsllineno;

int my_dsllex(YYSTYPE*, yyscan_t);
void my_dslerror(yyscan_t, Interpretor *, const char *);  /* prints grammar violation message */
int my_dslparse(yyscan_t, Interpretor *);
int my_dsl_do_parse(const char *, int, Interpretor *);

#endif // CONF_DEFINES_H
