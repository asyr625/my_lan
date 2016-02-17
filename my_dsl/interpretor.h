#ifndef INTERPRETOR_H
#define INTERPRETOR_H

#include <list>
#include <stack>

#include "variable.h"
#include "statement.h"
#include "function.h"

class Interpretor
{
public:
    Interpretor();

    void add_function(Function* f);
    void add_variable(Variable* v);
    void add_statement(Statement* s);

    void push_scope(Scope* s);
    void pop_scope();

    void push_back_scope(Scope* s);
    void pop_back_scope();

private:
    bool find_function(std::string& n);
    std::list<Function*> func_list;
    std::list<Variable*> var_list;
    std::list<Statement*> stmt_list;

    std::list<Scope*> scope_list;
    std::stack<Scope*> scope_stack;
};

#endif // INTERPRETOR_H
