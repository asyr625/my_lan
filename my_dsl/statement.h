#ifndef STATEMENT_H
#define STATEMENT_H

#include "ast.h"
#include "result_type.h"

class Expression;
class Statement : public Ast
{
public:
    enum Statement_Type
    {
        EXPRESSION_STATEMENT = 1,
        GLOBAL_STATEMENT,
        IF_STATEMENT,
        WHILE_STATEMENT,
        FOR_STATEMENT,
        FOREACH_STATEMENT,
        RETURN_STATEMENT,
        BREAK_STATEMENT,
        CONTINUE_STATEMENT,
        TRY_STATEMENT,
        THROW_STATEMENT,
        STATEMENT_TYPE_COUNT_PLUS_1
    };
    Statement();
    Result_Type statement_exec();
    virtual ~Statement();

    Statement_Type type() const;
private:
    Statement_Type _type;
};


class Statement_List
{
public:
private:
    Statement*   _stmt_ast;
    Statement_List*  _next;
};


class Block
{
public:
private:
    Statement_List*  _stmt_list;
};

class Elsif_Statement
{
public:
private:
    Expression     *_condition;
    Block       *_block;
    Elsif_Statement  *_next;
};

class If_Statement : public Statement
{
public:
private:
    Expression*    _condition;
    Block*      _then_block;
    Elsif_Statement* _elsif_list;
    Block*      _else_block;
};

class While_Statement : public Statement
{
public:
    While_Statement();

    virtual ~While_Statement();

private:
    void release();
    Expression*    _condition;
    Block*      _block;
};


class For_Statement : public Statement
{
public:
private:
    Expression  *_init;
    Expression  *_condition;
    Expression  *_post;
    Block    *_block;
};

class Return_Statement : public Statement
{
public:
private:
    Expression *_return_value;
} ;

class Break_Statement : public Statement
{
public:
private:
    char        *label;
};

class Continue_Statement : public Statement
{
public:
private:
    char        *label;
};

typedef struct IdentifierList_tag {
    char        *name;
    struct IdentifierList_tag   *next;
} IdentifierList;

typedef struct {
    IdentifierList      *identifier_list;
} GlobalStatement;

#endif // STATEMENT_H
