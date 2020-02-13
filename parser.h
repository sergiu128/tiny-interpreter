#pragma once

#include "lexer.h"
#include "tree.h"

/**
 * Given a stream of tokens from the lexer, the parser 
 * constructs an abstract syntax tree of the input, 
 * respecting operator precedence.
 */
class Parser
{
public:
    Parser(std::unique_ptr<Lexer>);

    std::unique_ptr<Tree> parse();

private:
    /**
     * The taxonomy an input expression is broken down in:
     *
     * weakExpr:    strongExpr ((PLUS | MINUS) strongExpr)*
     * strongExpr:  token ((MULTIPLY | DIVIDE) token)*
     * token:       INTEGER | LPAREN weakExpr RPAREN
     *
     * A weak expression first deals with strong expressions
     * and then applies the +/- operator. A strong expression
     * deals with parsing a single token (integer) or a weak
     * expression in between parenthesis, then applies the
     * + / / operator. It follows that operator precedence is
     * respected.
     */
    std::unique_ptr<Tree> evalWeakExpr();
    std::unique_ptr<Tree> evalStrongExpr();
    std::unique_ptr<Tree> evalToken();

    std::unique_ptr<Lexer> mLexer;
    std::unique_ptr<Token> mCurrentToken;
};
