#include "token.h"

Token::Token(TokenType type, char value) :
    mType(type),
    mValue(value)
{}

TokenType Token::GetType() const
{
    return mType;
}

char Token::GetValue() const
{
    return mValue;
}
