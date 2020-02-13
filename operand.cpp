#include "operand.h"

#include <iostream>

Operand::Operand(Token const& token) :
    mToken(token)
{}

void Operand::_debug() const
{
    mToken._debug();
}
