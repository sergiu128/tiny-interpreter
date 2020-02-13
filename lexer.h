#pragma once

#include "token.h"

#include <string>
#include <memory>

/**
 * A lexer tokenizes the given input string.
 * The token are to be requested one by one
 * through the GetNextToken() API call, while
 * there are still tokens present in the input.
 */
class Lexer
{
public:
    Lexer(std::string const&);

    std::unique_ptr<Token> GetNextToken();

    bool HasMoreTokens();

private:
    void SkipWhitespace();

    std::string const& mExpression;
    int mIndex;
};
