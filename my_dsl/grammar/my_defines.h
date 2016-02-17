#ifndef CONF_DEFINES_H
#define CONF_DEFINES_H

#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdio>


struct MY_DSL_Type{

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
void my_dslerror(yyscan_t, Telnet_Handler *, const char *);  /* prints grammar violation message */
int my_dslparse(yyscan_t, Telnet_Handler *);
int my_dsl_do_parse(const char *, int, Telnet_Handler *);

#endif // CONF_DEFINES_H
