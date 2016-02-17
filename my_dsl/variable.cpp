#include "variable.h"


Variable::Variable(std::string& n)
    : name(n),value()
{
}

Variable::Variable(std::string& n, Value& v)
    : name(n), value(v)
{
}

std::string& Variable::get_name()
{
    return name;
}

Value& Variable::get_value()
{
    return value;
}

void Variable::set_value(Value& v)
{
    value = v;
}
