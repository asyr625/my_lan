#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <iostream>
#include "ast.h"

class Expression : public Ast
{
public:
    enum Expression_Type
    {
        BOOLEAN_EXPRESSION = 1,
        INT_EXPRESSION,
        DOUBLE_EXPRESSION,
        STRING_EXPRESSION,
        IDENTIFIER_EXPRESSION,
        ASSIGN_EXPRESSION,
        ADD_EXPRESSION,
        SUB_EXPRESSION,
        MUL_EXPRESSION,
        DIV_EXPRESSION,
        MOD_EXPRESSION,
        EQ_EXPRESSION,
        NE_EXPRESSION,
        GT_EXPRESSION,
        GE_EXPRESSION,
        LT_EXPRESSION,
        LE_EXPRESSION,
        LOGICAL_AND_EXPRESSION,
        LOGICAL_OR_EXPRESSION,
        MINUS_EXPRESSION,
        FUNCTION_CALL_EXPRESSION,
        NULL_EXPRESSION,
        EXPRESSION_TYPE_COUNT_PLUS_1
    };
    Expression();
    Expression(Expression_Type type);
    virtual ~Expression();

    virtual Value eval_exp();

    Expression_Type type() const;
private:
    Expression_Type     _exp_type;
};

class Bool_Expression : public Expression
{
public:
    Bool_Expression();
    Bool_Expression(bool& val);
    ~Bool_Expression();

private:
    bool     _val;
};


class Int_Expression : public Expression
{
public:
    Int_Expression();
    Int_Expression(int& val);
    ~Int_Expression();

private:
    int     _val;
};


class Double_Expression : public Expression
{
public:
    Double_Expression();
    Double_Expression(double* val);
    ~Double_Expression();

private:
    double     _val;
};

class String_Expression : public Expression
{
public:
    String_Expression();
    String_Expression(std::string& val);
    ~String_Expression();

private:
    std::string     _val;
};

class Identifier_Expression : public Expression
{
public:
private:
    std::string     _name;
};

class Assign_Expression : public Expression
{
public:

private:
    char        *_variable;
    Expression     *_operand;
};

class Binary_Expression : public Expression
{
public:

private:
    Expression  *left;
    Expression  *right;
};


class Argument_List : public Expression
{
public:

private:
    Expression *_exp_ast;
    struct Argument_List *next;
};

class Function_Call_Expression : public Expression
{
public:
private:
    char *_identifier;
    Argument_List        *argument;
};

#endif // EXPRESSION_H
