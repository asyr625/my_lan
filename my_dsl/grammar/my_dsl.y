%define api.pure full
%define parse.error verbose

%lex-param      { yyscan_t scanner }
%parse-param    { yyscan_t scanner }
%parse-param    { Interpretor* interpretor }

%{
#include "my_defines.h"
%}


%right '='
%left '+' '-'
%left '*' '/'
%nonassoc '|' UMINUS

%token <expression>     INT_LITERAL
%token <expression>     DOUBLE_LITERAL
%token <expression>     STRING_LITERAL
%token <expression>     REGEXP_LITERAL
%token <identifier>     IDENTIFIER
%token IF ELSE ELSIF WHILE FOR FOREACH RETURN_T BREAK CONTINUE
        LP RP LC RC SEMICOLON COLON COMMA ASSIGN_T LOGICAL_AND LOGICAL_OR
        EQ NE GT GE LT LE ADD SUB MUL DIV MOD TRUE_T FALSE_T EXCLAMATION DOT
        ADD_ASSIGN_T SUB_ASSIGN_T MUL_ASSIGN_T DIV_ASSIGN_T MOD_ASSIGN_T
        INCREMENT DECREMENT TRY CATCH FINALLY THROW
        BOOLEAN_T INT_T DOUBLE_T STRING_T

%type   <parameter_list> parameter_list
%type   <argument_list> argument_list
%type   <expression> expression expression_opt
        assignment_expression logical_and_expression logical_or_expression
        equality_expression relational_expression
        additive_expression multiplicative_expression
        unary_expression postfix_expression primary_expression
%type   <statement> statement
        if_statement while_statement for_statement foreach_statement
        return_statement break_statement continue_statement try_statement
        throw_statement declaration_statement
%type   <statement_list> statement_list
%type   <block> block
%type   <elsif> elsif elsif_list
%type   <assignment_operator> assignment_operator
%type   <identifier> identifier_opt label_opt
%type   <type_specifier> type_specifier

%start translation_unit
%%

translation_unit
    : definition_or_statement
    | translation_unit definition_or_statement
    ;
definition_or_statement
    : function_definition
    | statement
    {
        interpretor->add_statement($1);
    }
    ;
type_specifier
    : BOOLEAN_T
    {
        $$ = DVM_BOOLEAN_TYPE;
    }
    | INT_T
    {
        $$ = DVM_INT_TYPE;
    }
    | DOUBLE_T
    {
        $$ = DVM_DOUBLE_TYPE;
    }
    | STRING_T
    {
        $$ = DVM_STRING_TYPE;
    }
    ;
function_definition
    : type_specifier IDENTIFIER LP parameter_list RP block
    {
        Function *f = new Interprator_Function($1, $2, $4, $6);
        interpretor->add_function(f);
    }
    | type_specifier IDENTIFIER LP RP block
    {
        Function *f = new Interprator_Function($1, $2, NULL, $5);
        interpretor->add_function(f);
    }
    | type_specifier IDENTIFIER LP parameter_list RP SEMICOLON
    {
        Function *f = new Interprator_Function($1, $2, $4, NULL);
        interpretor->add_function(f);
    }
    | type_specifier IDENTIFIER LP RP SEMICOLON
    {
        Function *f = new Interprator_Function($1, $2, NULL, NULL);
        interpretor->add_function(f);
    }
    ;//
parameter_list
    : type_specifier IDENTIFIER
    {
        $$ = dkc_create_parameter($1, $2);
    }
    | parameter_list COMMA type_specifier IDENTIFIER
    {
        $$ = dkc_chain_parameter($1, $3, $4);
    }
    ;//
argument_list
    : assignment_expression
    {
        $$ = dkc_create_argument_list($1);
    }
    | argument_list COMMA assignment_expression
    {
        $$ = dkc_chain_argument_list($1, $3);
    }
    ;//
statement_list
    : statement
    {
        $$ = dkc_create_statement_list($1);
    }
    | statement_list statement
    {
        $$ = dkc_chain_statement_list($1, $2);
    }
    ;

expression
        : assignment_expression
        | expression COMMA assignment_expression
        {
            $$ = new Comma_Expression($1, $3);
        }
        ;
assignment_expression
        : logical_or_expression
        | postfix_expression assignment_operator assignment_expression
        {
            $$ = new Assign_Expression($2, $1, $3);
        }
        ;
assignment_operator
        : ASSIGN_T
        {
            $$ = NORMAL_ASSIGN;
        }
        | ADD_ASSIGN_T
        {
            $$ = ADD_ASSIGN;
        }
        | SUB_ASSIGN_T
        {
            $$ = SUB_ASSIGN;
        }
        | MUL_ASSIGN_T
        {
            $$ = MUL_ASSIGN;
        }
        | DIV_ASSIGN_T
        {
            $$ = DIV_ASSIGN;
        }
        | MOD_ASSIGN_T
        {
            $$ = MOD_ASSIGN;
        }
        ;
logical_or_expression
        : logical_and_expression
        | logical_or_expression LOGICAL_OR logical_and_expression
        {
            $$ = new Binary_Expression(LOGICAL_OR_EXPRESSION, $1, $3);
        }
        ;
logical_and_expression
        : equality_expression
        | logical_and_expression LOGICAL_AND equality_expression
        {
            $$ = new Binary_Expression(LOGICAL_AND_EXPRESSION, $1, $3);
        }
        ;
equality_expression
        : relational_expression
        | equality_expression EQ relational_expression
        {
            $$ = new Binary_Expression(EQ_EXPRESSION, $1, $3);
        }
        | equality_expression NE relational_expression
        {
            $$ = new Binary_Expression(NE_EXPRESSION, $1, $3);
        }
        ;
relational_expression
        : additive_expression
        | relational_expression GT additive_expression
        {
            $$ = new Binary_Expression(GT_EXPRESSION, $1, $3);
        }
        | relational_expression GE additive_expression
        {
            $$ = new Binary_Expression(GE_EXPRESSION, $1, $3);
        }
        | relational_expression LT additive_expression
        {
            $$ = new Binary_Expression(LT_EXPRESSION, $1, $3);
        }
        | relational_expression LE additive_expression
        {
            $$ = new Binary_Expression(LE_EXPRESSION, $1, $3);
        }
        ;
additive_expression
        : multiplicative_expression
        | additive_expression ADD multiplicative_expression
        {
            $$ = new Binary_Expression(ADD_EXPRESSION, $1, $3);
        }
        | additive_expression SUB multiplicative_expression
        {
            $$ = new Binary_Expression(SUB_EXPRESSION, $1, $3);
        }
        ;
multiplicative_expression
        : unary_expression
        | multiplicative_expression MUL unary_expression
        {
            $$ = new Binary_Expression(MUL_EXPRESSION, $1, $3);
        }
        | multiplicative_expression DIV unary_expression
        {
            $$ = new Binary_Expression(DIV_EXPRESSION, $1, $3);
        }
        | multiplicative_expression MOD unary_expression
        {
            $$ = new Binary_Expression(MOD_EXPRESSION, $1, $3);
        }
        ;
unary_expression
        : postfix_expression
        | SUB unary_expression
        {
            $$ = new Minus_Expression($2);
        }
        | EXCLAMATION unary_expression
        {
            $$ = new Logical_Not_Expression($2);
        }
        ;//
postfix_expression
        : primary_expression
        | postfix_expression LP argument_list RP
        {
            $$ = new Function_Call_Expression($1, $3);
        }
        | postfix_expression LP RP
        {
            $$ = new Function_Call_Expression($1, NULL);
        }
        | postfix_expression INCREMENT
        {
            $$ = new IncrementOrDecrement_Expression($1, INCREMENT_EXPRESSION);
        }
        | postfix_expression DECREMENT
        {
            $$ = new IncrementOrDecrement_Expression($1, DECREMENT_EXPRESSION);
        }
        ;//
primary_expression
        : LP expression RP
        {
            $$ = $2;
        }
        | IDENTIFIER
        {
            $$ = dkc_create_identifier_expression($1);
        }
        | INT_LITERAL
        | DOUBLE_LITERAL
        | STRING_LITERAL
        | REGEXP_LITERAL
        | TRUE_T
        {
            $$ = new Bool_Expression(DVM_TRUE);
        }
        | FALSE_T
        {
            $$ = new Bool_Expression(DVM_FALSE);
        }
        ;
%%

void my_dslerror(yyscan_t , Telnet_Handler *, const char *s)
{
fflush(stdout);
fprintf(stderr, "*** %s\n", s);
}
