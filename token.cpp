#include "token.h"
#include <iostream>

Token::Token(TokenType type, char value) :
    mType(type),
    mValue(value) {}

void Token::_debug()
{
    std::cout << mType << " "  << mValue << std::endl;
}

