#ifndef STATEMENT_H
#define STATEMENT_H

#include "ast.h"
#include "result_type.h"
#include "block.h"

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
    virtual ~Statement();
    Result_Type statement_exec();

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


class Elsif_Statement
{
public:
private:
    Expression     *_condition;
    Block       *_block;
};

class Elsif_List
{
public:
    Elsif_List();

    void push_back(Elsif_Statement* e);
private:
    std::list<Elsif_Statement*> elsif_list;
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
    While_Statement(string& l, Expression* cond, Block* b)
        : Statement(WHILE_STATEMENT), label(l), condition(cond), block(b)
    {
    }

    virtual ~While_Statement();
    void release();
private:
    string      label;
    Expression* condition;
    Block*      block;
};


class For_Statement : public Statement
{
public:
    For_Statement(string& l, Expression* init, Expression* cond, Expression* post, Block* b)
        : Statement(FOR_STATEMENT), label(l), _init(init), _condition(cond), _post(post), _block(b)
    {
    }

private:
    string      label;
    Expression  *_init;
    Expression  *_condition;
    Expression  *_post;
    Block    *_block;
};

class Return_Statement : public Statement
{
public:
    Return_Statement(Expression* rtn)
        : Statement(RETURN_STATEMENT), _return_value(rtn)
    {
    }

private:
    Expression *_return_value;
} ;

class Break_Statement : public Statement
{
public:
    Break_Statement(std::string& l)
        : Statement(BREAK_STATEMENT), label(l)
    {
    }

private:
    std::string label;
};

class Continue_Statement : public Statement
{
public:
    Continue_Statement(std::string& l)
        : Statement(CONTINUE_STATEMENT), label(l)
    {
    }
private:
    std::string label;
};

typedef struct IdentifierList_tag {
    char        *name;
    struct IdentifierList_tag   *next;
} IdentifierList;

typedef struct {
    IdentifierList      *identifier_list;
} GlobalStatement;

#endif // STATEMENT_H
