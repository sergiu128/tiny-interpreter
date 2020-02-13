#include "lexer.h"

#include <cctype>
#include <iostream>

Lexer::Lexer(std::string const& expression) : 
    mExpression(expression),
    mIndex(0)
{
    if (expression.length() == 0)
        throw "Invalid input: cannot accept zero length strings.";
}

std::unique_ptr<Token> Lexer::NextToken()
{
    if (!HasMoreTokens())
        return nullptr;

    std::unique_ptr<Token> token;

    if (isspace(mExpression[mIndex]))
        SkipWhitespace();

    auto currentChar = mExpression[mIndex];
    if (isdigit(currentChar))
        token = std::unique_ptr<Token>(new Token(TokenType::DIGIT, currentChar));
    else if (currentChar == '+')
        token = std::unique_ptr<Token>(new Token(TokenType::PLUS, currentChar));
    else if (currentChar == '-')
        token = std::unique_ptr<Token>(new Token(TokenType::MINUS, currentChar));
    else if (currentChar == '*')
        token = std::unique_ptr<Token>(new Token(TokenType::MULTIPLY, currentChar));
    else if (currentChar == '/')
        token = std::unique_ptr<Token>(new Token(TokenType::DIVIDE, currentChar));
    else if (currentChar == '(')
        token = std::unique_ptr<Token>(new Token(TokenType::LPAREN, currentChar));
    else if (currentChar == ')')
        token = std::unique_ptr<Token>(new Token(TokenType::RPAREN, currentChar));
    else throw "Invalid input.";

    mIndex += 1;

    return token;
}

bool Lexer::HasMoreTokens() const
{
    if (mIndex >= mExpression.length()) 
        return false;
    return true;
}

void Lexer::SkipWhitespace()
{
    while (mIndex < mExpression.length() && isspace(mExpression[mIndex])) 
        mIndex += 1;
}
