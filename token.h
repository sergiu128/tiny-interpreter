#pragma once

#include "common.h"

class Token
{
public:
    Token(TokenType, char);

    void _debug();
private:
    TokenType mType;
    char mValue;
};
