#ifndef STATEMENT_VISIT_H
#define STATEMENT_VISIT_H

#include "result_type.h"

class Statement;
class If_Statement;
class While_Statement;
class For_Statement;
class Return_Statement;
class Break_Statement;
class Continue_Statement;


class Statement_Visit
{
public:
    virtual visit_statement(Statement* stmt, );
};

#endif // STATEMENT_VISIT_H
