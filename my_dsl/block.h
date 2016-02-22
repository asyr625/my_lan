#ifndef BLOCK_H
#define BLOCK_H

#include <list>

enum Block_Type
{
    UNDEFINED_BLOCK = 1,
    FUNCTION_BLOCK,
    WHILE_STATEMENT_BLOCK,
    FOR_STATEMENT_BLOCK
};

class Function;
class Statement;
class Declaration;

class Block
{
public:
    Block(Block_Type bt, Block* b, std::list<Statement*>* stmt_list, std::list<Declaration*>* dl);
    virtual ~Block();

    void push_back_stmt(Statement* s);
private:
    Block_Type  block_type;
    Block       *outer_block;
    std::list<Statement*> *statement_list;
    std::list<Declaration*> *declaration_list;
};


class Function_Block : public Block
{
public:
    Function_Block(Block* b, std::list<Statement*>* stmt_list, std::list<Declaration*>* dl, Function* f, int end_lab);
private:
    Function* parent_function;
    int       end_label;
};

class Statement_Block : public Block
{
public:
    Statement_Block(Block* b, std::list<Statement*>* stmt_list, std::list<Declaration*>* dl, Statement* s, int cont_lab, int break_lab);
private:
    Statement   *parent_statement;
    int         continue_label;
    int         break_label;
};

#endif // BLOCK_H
