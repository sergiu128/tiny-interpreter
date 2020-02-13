#pragma once

#include "parser.h"

class Interpreter
{
public:
    Interpreter(Parser&);

    int Interpret();
private:
    int visit(std::unique_ptr<Tree> const&);

    Parser& mParser;
};
