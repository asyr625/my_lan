#ifndef AST_H
#define AST_H

class Value;
class Code_Gen_Context;
class Cpu;
class Ast
{
public:
    enum Ast_Type
    {
        EXPRESSION,
        STATEMENT
    };

    Ast();
    Ast(Ast_Type type = EXPRESSION);
    virtual ~Ast();

    Ast_Type type() const;

    virtual bool is_exe_first() const;
    virtual void exe_first(Cpu&){}
    virtual Value* exe_second(Cpu&);
    virtual Value* code_gen(Code_Gen_Context& context);
    virtual Ast* clone() = 0;

private:
    Ast_Type    _type;
};

#endif // AST_H



