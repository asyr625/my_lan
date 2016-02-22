#include "function.h"


Function::Function(Function_Type t, Value_Type rt, std::string& n)
    : type(t), return_type(rt), name(n)
{
}


Interprator_Function::Interprator_Function(Value_Type rt, std::string& n, std::list<Parameter*>* paraml, Block* b )
    : Function(Interprat_Function, rt, n), param_list(paraml), block(b)
{

}
