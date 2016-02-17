#include <algorithm>

#include "interpretor.h"

Interpretor::Interpretor()
{
}

bool Interpretor::find_function(std::string& n)
{
    bool rtn = false;
    std::for_each(func_list.begin(), func_list.end(), [n, &rtn](Function* f){
        if( f->get_name() == n )
            rtn = true;
    });
    return rtn;
}

void Interpretor::add_function(Function* f)
{
    if( !find_function(f->get_name()) )
        func_list.push_back(f);
}

void Interpretor::add_variable(Variable* v)
{
    var_list.push_back(v);
}

void Interpretor::add_statement(Statement* s)
{
    stmt_list.push_back(s);
}

void Interpretor::push_scope(Scope* s)
{
    scope_stack.push(s);
}

void Interpretor::pop_scope()
{
    scope_stack.pop();
}

void Interpretor::push_back_scope(Scope* s)
{
    scope_list.push_back(s);
}

void Interpretor::pop_back_scope()
{
    scope_list.pop_back();
}
