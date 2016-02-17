#ifndef VARIABLE_H
#define VARIABLE_H

#include <list>
#include <string>
#include "value.h"

class Variable
{
public:
    Variable(std::string& n);
    Variable(std::string& n, Value& v);

    std::string& get_name();
    Value& get_value();

    void set_value(Value& v);
private:
    std::string name;
    Value  value;
};

class Scope
{
public:
    Scope();
    Scope(Scope* parent);

    void add_variable(Variable* v);
    Variable* get_variable(std::string &str);
    void set_variable(std::string & str, Value& v);
private:
    Scope* parent_scope;
    std::list<Variable*> var_list;
};

#endif // VARIABLE_H
