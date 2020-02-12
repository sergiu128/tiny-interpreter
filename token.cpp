#include "token.h"
#include <iostream>

Token::Token(TokenType type, char value) :
    mType(type),
    mValue(value)
{}

Token::Token(Token&& token) :
    mType(std::move(token.mType)),
    mValue(std::move(token.mValue))
{}

void Token::_debug()
{
    std::cout << mType << " "  << mValue << std::endl;
}

TokenType Token::GetType() 
{
    return mType;
}

char Token::GetValue()
{
    return mValue;
}
