#include "lexer.h"

#include <iostream>
#include <string>


int main()
{
    std::string inputExpression;
    getline(std::cin, inputExpression);

    auto lexer = std::unique_ptr<Lexer>(new Lexer(inputExpression));

    while (lexer->HasMoreTokens())
    {
        auto token = lexer->GetNextToken();
        std::cout << token->GetValue() << std::endl;
    }

    return 0;
}
