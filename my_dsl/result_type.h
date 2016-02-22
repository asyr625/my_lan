#ifndef RESULT_TYPE_H
#define RESULT_TYPE_H

#include "value.h"

enum Result_Desc
{
    UNDEFINED_RESULT = 1,
    FUNCTION_RESULT,
    WHILE_STATEMENT_RESULT,
    FOR_STATEMENT_RESULT,
    CONTINUE_RESULT
};

class Result_Type
{
public:
    Result_Type(Result_Desc t, Value* v);

    Result_Desc get_type();
    Value* get_value();

    void set_value(Value* v);
    //
    Result_Type& operator= (Result_Type& rh);

private:
    Result_Desc type;
    Value*      value;
};

#endif // RESULT_TYPE_H
