#pragma once

#include "ast.h"
#include "token.h"

class BinaryOperator : public Ast
{
public:
    BinaryOperator(Ast const&, Token const&, Ast const&);
private:
    Ast const& mLeft;
    Token const& mOperator;
    Ast const& mRight;
};
