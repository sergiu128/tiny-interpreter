#pragma once

#include "token.h"
#include "common.h"

#include <string>
#include <memory>

class Lexer
{
public:
    Lexer(std::string const&);

    void Advance();

    void SkipWhitespace();

    std::unique_ptr<Token> GetNextToken();

private:
    std::string const& mExpression;
    int mIndex;
    char mCurrentChar;
};
