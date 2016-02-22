#ifndef EXPRESSION_VISIT_H
#define EXPRESSION_VISIT_H

class Value;

class Expression;
class Bool_Expression;
class Int_Expression;
class Double_Expression;
class String_Expression;
class Identifier_Expression;
class Assign_Expression;
class Comma_Expression;
class Binary_Expression;
class Minus_Expression;
class Logical_Not_Expression;
class Function_Call_Expression;
class IncrementOrDecrement_Expression;


typedef Value Result_Value;

class Expression_Visit
{
public:
    virtual void visit_expression(Expression* ast, Result_Value* rv) = 0;
    virtual void visit_bool_expression(Expression* ast, Result_Value* rv) = 0;
    virtual void visit_int_expression(Expression* ast, Result_Value* rv) = 0;
    virtual void visit_double_expression(Expression* ast, Result_Value* rv) = 0;
    virtual void visit_string_expression(Expression* ast, Result_Value* rv) = 0;
    virtual void visit_identifier_expression(Expression* ast, Result_Value* rv) = 0;
    virtual void visit_assign_expression(Expression* ast, Result_Value* rv) = 0;
    virtual void visit_comma_expression(Expression* ast, Result_Value* rv) = 0;
    virtual void visit_binary_expression(Expression* ast, Result_Value* rv) = 0;
    virtual void visit_minus_expression(Expression* ast, Result_Value* rv) = 0;
    virtual void visit_logical_not_expression(Expression* ast, Result_Value* rv) = 0;
    virtual void visit_function_call_expression(Expression* ast, Result_Value* rv) = 0;
    virtual void visit_incre_or_decre_expression(Expression* ast, Result_Value* rv) = 0;
};

#endif // EXPRESSION_VISIT_H
