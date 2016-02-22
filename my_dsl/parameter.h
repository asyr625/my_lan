#ifndef PARAMETER_H
#define PARAMETER_H

#include <list>

#include "value.h"

class Parameter
{
public:
    Parameter(std::string& n, Value_Type t, int l);

    Parameter& operator = (Parameter& rh);

    std::string& get_name();
    Value_Type   get_type();
    int get_line_number();
private:
    std::string name;
    Value_Type  type;
    int         line_number;
};


class Parameter_List
{
public:
    Parameter_List();
    ~Parameter_List();
    void push_back(Parameter*p);

private:
    std::list<Parameter*> param_list;
    int param_number;
};

#endif // PARAMETER_H
