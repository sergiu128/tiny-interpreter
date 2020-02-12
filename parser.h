#pragma once

#include "ast.h"
#include "token.h"
#include "lexer.h"

#include <memory>

class Parser
{
public:
    Parser(std::unique_ptr<Lexer> const&);

    std::unique_ptr<Ast> parse();
private:
    void consume(TokenType const&);
    std::unique_ptr<Ast> factor();
    std::unique_ptr<Ast> term();
    std::unique_ptr<Ast> expression();

    std::unique_ptr<Lexer> const& mLexer;
    std::shared_ptr<Token> mToken;
    std::shared_ptr<Token> mCurrentToken;
};
