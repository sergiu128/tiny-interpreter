#include "tree.h"

BinOpTree::BinOpTree(
        std::unique_ptr<Tree> left,
        char op,
        std::unique_ptr<Tree> right) :
    mLeft(std::move(left)),
    mOperator(op),
    mRight(std::move(right))
{}

char BinOpTree::GetValue() const
{
    return mOperator;
}

Digit::Digit(int value) :
    mValue(value)
{}

char Digit::GetValue() const
{
    return mValue + '0';
}
