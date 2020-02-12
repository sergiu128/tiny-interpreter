#include "lexer.h"

#include <cctype>

Lexer::Lexer(std::string const& expression) : 
    mExpression(expression),
    mIndex(0)
{
    if (expression.length() == 0)
        throw "Zero length input invalid";
    
    mCurrentChar = mExpression[mIndex];
}

void Lexer::Advance()
{
    mIndex += 1;
    if (mIndex > mExpression.length())
        mCurrentChar = 0;
    else mCurrentChar = mExpression[mIndex];
}

void Lexer::SkipWhitespace()
{
    while (mCurrentChar != 0 && isspace(mCurrentChar)) 
        Advance();
}

std::unique_ptr<Token> Lexer::GetNextToken()
{
    while (mCurrentChar != 0)
    {
        if (isspace(mCurrentChar)) 
        {
            SkipWhitespace();
            continue;
        }

        if (isdigit(mCurrentChar))
        {
            return std::unique_ptr<Token>(new Token(DIGIT, mCurrentChar));
        }

        switch (mCurrentChar)
        {
            case '+':
                return std::unique_ptr<Token>(new Token(PLUS, mCurrentChar));
                break;
            case '-':
                return std::unique_ptr<Token>(new Token(MINUS, mCurrentChar));
                break;
            case '*':
                return std::unique_ptr<Token>(new Token(MULTIPLY, mCurrentChar));
                break;
            case '/':
                return std::unique_ptr<Token>(new Token(DIVIDE, mCurrentChar));
                break;
            case '(':
                return std::unique_ptr<Token>(new Token(LPAREN, mCurrentChar));
                break;
            case ')':
                return std::unique_ptr<Token>(new Token(RPAREN, mCurrentChar));
                break;

            throw "Invalid character.";
        }
    }
}
