%option nounput noyywrap reentrant bison-bridge

O   [0-7]
D   [0-9]
NZ  [1-9]
L   [a-zA-Z_]
A   [a-zA-Z_0-9]
H   [a-fA-F0-9]
HP  (0[xX])
E   ([Ee][+-]?{D}+)
P   ([Pp][+-]?{D}+)
FS  (f|F|l|L)
IS  (((u|U)(l|L|ll|LL)?)|((l|L|ll|LL)(u|U)?))
CP  (u|U|L)
SP  (u8|u|U|L)
ES  (\\(['"\?\\abfnrtv]|[0-7]{1,3}|x[a-fA-F0-9]+))
WS  [ \t\v\f\r\n]+


%{
//%x
#include "my_defines.h"
#include "my_dsl_yacc.h"
%}


%%
"if"           return IF;
"else"         return ELSE;
"elsif"        return ELSIF;
"while"        return WHILE;
"for"          return FOR;
"foreach"      return FOREACH;
"return"       return RETURN_T;
"break"        return BREAK;
"continue"     return CONTINUE;
"true"         return TRUE_T;
"false"        return FALSE_T;
"try"          return TRY;
"catch"        return CATCH;
"finally"      return FINALLY;
"throw"        return THROW;
"boolean"      return BOOLEAN_T;
"int"          return INT_T;
"double"       return DOUBLE_T;
"string"       return STRING_T;
"("            return LP;
")"            return RP;
"{"            return LC;
"}"            return RC;
";"            return SEMICOLON;
":"            return COLON;
","            return COMMA;
"&&"           return LOGICAL_AND;
"||"           return LOGICAL_OR;
"="            return ASSIGN_T;
"=="           return EQ;
"!="           return NE;
">"            return GT;
">="           return GE;
"<"            return LT;
"<="           return LE;
"+"            return ADD;
"-"            return SUB;
"*"            return MUL;
"/"            return DIV;
"%"            return MOD;
"+="           return ADD_ASSIGN_T;
"-="           return SUB_ASSIGN_T;
"*="           return MUL_ASSIGN_T;
"/="           return DIV_ASSIGN_T;
"%="           return MOD_ASSIGN_T;
"++"           return INCREMENT;
"--"           return DECREMENT;
"!"            return EXCLAMATION;
"."            return DOT;

%%

int my_dsl_do_parse(const char *buf, int len, Interpretor *param)
{
    int rc = 0;
    yyscan_t scanner;

    if ( my_dsllex_init(&scanner) )
        exit(1);

    YY_BUFFER_STATE state = my_dsl_scan_bytes(buf, len, scanner);
    my_dsl_switch_to_buffer(state, scanner);
    rc = my_dslparse(scanner, param);

    my_dsl_delete_buffer(state, scanner);
    my_dsllex_destroy(scanner);

    return rc;
}
