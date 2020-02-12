#include "operand.h"
#include "binary_operator.h"
#include "parser.h"
#include "common.h"

Parser::Parser(std::unique_ptr<Lexer> const& lexer) :
    mLexer(std::move(lexer))
{
    mCurrentToken = mLexer->GetNextToken();
}

void Parser::consume(TokenType const& tokenType)
{
    if (mCurrentToken->GetType() == tokenType)
        mCurrentToken = mLexer->GetNextToken();
    else throw "Invalid syntax.";
}

/**
 * INTEGER | LPAREN expr RPAREN
 */
std::unique_ptr<Ast> Parser::factor()
{
    std::unique_ptr<Ast> node;

    mToken = mCurrentToken;
    if (mToken->GetType() == DIGIT)
    {
        consume(DIGIT);
        node = std::unique_ptr<Ast>(new Operand(*mToken));
    }
    else if (mToken->GetType() == LPAREN)
    {
        consume(LPAREN);
        node = expression();
        consume(RPAREN);
    }

    return node;
}

/**
 * term: factor (MULTIPLY | DIVIDE) factor
 */
std::unique_ptr<Ast> Parser::term()
{
    auto node = factor();

    while (mCurrentToken->GetType() == MULTIPLY || mCurrentToken->GetType() == DIVIDE)
    {
        mToken = mCurrentToken;
        if (mToken->GetType() == MULITPLY)
            consume(MULIPLY);
        else if (mToken->GetType() == DIVIDE)
            consume(DIVIDE);

        node = std::unique_ptr<Ast>(new BinaryOperator(*node, *mToken, *factor()));
    }

    return node;
}

/**
 * expression: term (PLUS | MINUS) term
 */
std::unique_ptr<Ast> Parser::expression()
{
    auto node = term();

    while (mCurrentToken->GetType() == PLUS || mCurrentToken->GetType() == MINUS)
    {
        mToken = mCurrentToken;
        if (mToken->GetType() == PLUS)
            consume(PLUS);
        else if (mToken->GetType() == MINUS)
            consume(MINUS);

        node = std::unique_ptr<Ast>(new BinaryOperator(*node, *mToken, *term()));
    }

    return node;
}

std::unique_ptr<Ast> Parser::parse()
{
    return expression();
}
