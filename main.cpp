#include "interpreter.h"

#include <iostream>
#include <string>


int main()
{
    std::string inputExpression;
    getline(std::cin, inputExpression);

    Lexer lexer(inputExpression);
    Parser parser(lexer);
    Interpreter interpreter(parser);
    int ret = interpreter.Interpret();
    std::cout << ret << std::endl;

    return 0;
}
