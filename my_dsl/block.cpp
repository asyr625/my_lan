#include "block.h"

Block::Block(Block_Type bt, Block* b, std::list<Statement*>* stmt_list, std::list<Declaration*>* dl)
    : block_type(bt), outer_block(b), statement_list(stmt_list), declaration_list(dl)
{

}
