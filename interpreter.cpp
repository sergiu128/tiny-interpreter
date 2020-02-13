#include "interpreter.h"

#include <cctype>

Interpreter::Interpreter(Parser& parser) :
    mParser(parser)
{}

int Interpreter::Interpret()
{
    auto tree = mParser.parse();
    return visit(tree);
}

int Interpreter::visit(std::unique_ptr<Tree> const& node)
{
    if (node == nullptr)
        return 0;
    else
    {
        if (isdigit(node->GetValue()))
            return node->GetValue() - '0';
        else
        {
            switch(node->GetValue())
            {
                case '+':
                    return visit(static_cast<BinOpTree*>(node.get())->mLeft) 
                        + visit(static_cast<BinOpTree*>(node.get())->mRight);
                    break;
                case '-':
                    return visit(static_cast<BinOpTree*>(node.get())->mLeft) 
                        - visit(static_cast<BinOpTree*>(node.get())->mRight);
                    break;
                case '/':
                    return visit(static_cast<BinOpTree*>(node.get())->mLeft) 
                        / visit(static_cast<BinOpTree*>(node.get())->mRight);
                    break;
                case '*':
                    return visit(static_cast<BinOpTree*>(node.get())->mLeft) 
                        * visit(static_cast<BinOpTree*>(node.get())->mRight);
                    break;
            }
        }

        return 0;
    }
}
