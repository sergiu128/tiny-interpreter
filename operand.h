#pragma once

#include "ast.h"
#include "token.h"

#include <memory>

class Operand : public Ast
{
public:
    Operand(Token const&);
private:
    Token const& mToken;
};
