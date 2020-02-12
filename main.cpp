#include "lexer.h"

#include <iostream>
#include <string>


int main()
{
    std::string inputExpression;
    std::cin >> inputExpression;

    Lexer lexer(inputExpression);
    auto token = lexer.GetNextToken();
    token->_debug();

    return 0;
}
