#pragma once

#include "common.h"

class Token
{
public:
    Token(TokenType, char);

    Token(Token&&);

    TokenType GetType();

    char GetValue();

    void _debug();
private:
    TokenType mType;
    char mValue;
};
