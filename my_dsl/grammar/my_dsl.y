%define api.pure full
%define parse.error verbose

%lex-param      { yyscan_t scanner }
%parse-param    { yyscan_t scanner }
%parse-param    { Telnet_Handler* handler }

%{
#include "my_defines.h"
%}


%right '='
%left '+' '-'
%left '*' '/'
%nonassoc '|' UMINUS

%token<str>  NAME STRING_LITERAL IP_ADDR STRING_STR
%token<ival> INUM
%token<dval> DNUM
%token EOL C_CALL
%token RPC BEGIN_INPUT END_INPUT QUIT
%token RETURN PRINT SCOPE SHOW
%token DOUBLE INT VOID STRING

%type<rpc_node> rpc_node
%type<value> type_specifier const_var
%type<ast> declaration exp stmt function_declaration rpc call_func c_call_func print_value
%type<list_ast> argument_declaration function_body explist param_list

%type<ast>

%start translation_unit
%%


control_stmt
    : if_statement
    | while_statement
    | for_statement
    | foreach_statement
    //| return_statement
    | break_statement
    | continue_statement
    | try_statement
    | throw_statement
    ;

if_statement
        : IF LP expression RP block
        {
            $$ = new If_Ast($3, $2, $4, $5, NULL);
        }
        | IF LP expression RP block ELSE block
        {
            $$ = new If_Ast($3, $2, $4, $5, NULL, $7);
        }
        | IF LP expression RP block elsif_list
        {
            $$ = new If_Ast($3, $2, $4, $5, $6, NULL);
        }
        | IF LP expression RP block elsif_list ELSE block
        {
            $$ = new If_Ast($3, $2, $4, $5, $6, $8);
        }
        ;
elsif_list
        : elsif
        | elsif_list elsif
        {
            $$ = new Elsif_Ast($1, $2);
        }
        ;
elsif
        : ELSIF LP expression RP block
        {
            $$ = new Elsif_Ast($3, $2, $4, $5);
        }
        ;
%%

void my_dslerror(yyscan_t , Telnet_Handler *, const char *s)
{
    fflush(stdout);
    fprintf(stderr, "*** %s\n", s);
}
