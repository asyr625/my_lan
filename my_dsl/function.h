#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include <list>

#include "value.h"
#include "block.h"
#include "parameter.h"

enum Function_Type
{
    Interprat_Function,
    Native_Function
};

class Function
{
public:
    Function(Function_Type t, Value_Type rt, std::string& n);
    virtual ~Function();

    std::string& get_name();
private:
    Function_Type type;
    Value_Type return_type;
    std::string name;
};


class Interprator_Function : public Function
{
public:
    Interprator_Function(Value_Type rt, std::string& n, std::list<Parameter*>* paraml, Block* b );
private:
    std::list<Parameter>* param_list;
    Block* block;
};

class Native_Function : public Function
{
public:

private:
};

#endif // FUNCTION_H
