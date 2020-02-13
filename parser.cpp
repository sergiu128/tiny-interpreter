#include "parser.h"

#include <stdexcept>
#include <cstdlib>

Parser::Parser(Lexer& lexer) :
    mLexer(lexer),
    mCurrentToken(nullptr)
{}

std::unique_ptr<Tree> Parser::parse()
{
    if (mLexer.HasMoreTokens())
        mCurrentToken = mLexer.NextToken();
    else throw std::runtime_error("Invalid input.");

    return evalWeakExpr();
}

std::unique_ptr<Tree> Parser::evalToken()
{
    if (mCurrentToken == nullptr)
        return nullptr;

    std::unique_ptr<Tree> node = nullptr;
    if (mCurrentToken->GetType() == TokenType::DIGIT)
    {
        auto value = consume(TokenType::DIGIT);
        node = std::unique_ptr<Tree>(new Digit(value - '0'));
    }
    else if (mCurrentToken->GetType() == TokenType::LPAREN)
    {
        consume(TokenType::LPAREN);
        node = evalWeakExpr();
        // expecting a right parenthesis - if not, throw.
        consume(TokenType::RPAREN);
    }

    return node;
}

std::unique_ptr<Tree> Parser::evalStrongExpr()
{
    auto tree = evalToken();

    while (mCurrentToken != nullptr
            && (mCurrentToken->GetType() == TokenType::MULTIPLY
                || mCurrentToken->GetType() == TokenType::DIVIDE))
    {
        char value;
        if (mCurrentToken->GetType() == TokenType::MULTIPLY)
            value = consume(TokenType::MULTIPLY);
        else value = consume(TokenType::DIVIDE);

        tree = std::unique_ptr<Tree>(
                new BinOpTree(
                    std::move(tree),
                    value,
                    std::move(evalToken())));
    }

    return tree;
}

std::unique_ptr<Tree> Parser::evalWeakExpr()
{
    auto tree = evalStrongExpr();

    while (mCurrentToken != nullptr
            && (mCurrentToken->GetType() == TokenType::PLUS
                || mCurrentToken->GetType() == TokenType::MINUS))
    {
        char value;
        if (mCurrentToken->GetType() == TokenType::PLUS)
            value = consume(TokenType::PLUS);
        else value = consume(TokenType::MINUS);

        tree = std::unique_ptr<Tree>(
                new BinOpTree(
                    std::move(tree),
                    value,
                    std::move(evalStrongExpr())));
    }

    return tree;
}

char Parser::consume(TokenType type)
{
    if (mCurrentToken->GetType() != type)
    {
        throw std::runtime_error("Invalid syntax.");
    }
    else
    {
        auto value = mCurrentToken->GetValue();
        mCurrentToken = mLexer.NextToken();

        return value;
    }
}
