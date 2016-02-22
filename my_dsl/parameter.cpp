#include "parameter.h"

Parameter::Parameter(std::string& n, Value_Type t, int l)
    : name(n), type(t), line_number(l)
{
}

Parameter& Parameter::operator = (Parameter& rh)
{
    this->name = rh.name;
    this->type = rh.type;
    this->line_number = rh.line_number;
    return *this;
}


std::string& Parameter::get_name()
{
    return name;
}

Value_Type Parameter::get_type()
{
    return type;
}

int Parameter::get_line_number()
{
    return line_number;
}
