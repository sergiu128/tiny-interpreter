#include "parser.h"

#include <iostream>
#include <string>


int main()
{
    std::string inputExpression;
    getline(std::cin, inputExpression);

    Lexer lexer(inputExpression);
    Parser parser(lexer);
    auto tree = parser.parse();

    return 0;
}
