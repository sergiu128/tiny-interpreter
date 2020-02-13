#include "tree.h"

BinOpTree::BinOpTree(
        std::unique_ptr<Tree> left,
        Operator op,
        std::unique_ptr<Tree> right) :
    mLeft(std::move(left)),
    mOperator(op),
    mRight(std::move(right))
{}

Digit::Digit(int value) :
    mValue(value)
{}
