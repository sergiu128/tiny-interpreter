#include "parser.h"

Parser::Parser(std::unique_ptr<Lexer> lexer) :
    mLexer(std::move(lexer)),
    mCurrentToken(nullptr)
{}

std::unique_ptr<Tree> Parser::parse()
{
    return nullptr;
}

std::unique_ptr<Tree> Parser::evalToken()
{
    return nullptr;
}

std::unique_ptr<Tree> Parser::evalStrongExpr()
{
    return nullptr;
}

std::unique_ptr<Tree> Parser::evalWeakExpr()
{
    return nullptr;
}
