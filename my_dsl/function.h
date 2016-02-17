#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include <list>

enum Function_Type
{
    Interprat_Function,
    Native_Function
};

class Function
{
public:
    Function(Function_Type t, std::string& n);
    virtual ~Function();

    std::string& get_name();
private:
    std::string name;
    Function_Type type;
};


class Interprator_Function : public Function
{

private:

};

class Native_Function : public Function
{
public:

private:
};

#endif // FUNCTION_H
