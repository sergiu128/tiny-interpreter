#include "operand.h"

Operand::Operand(Token const& token) :
    mToken(std::move(token))
{}
