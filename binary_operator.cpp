#include "binary_operator.h"

#include <iostream>

BinaryOperator::BinaryOperator(Ast const& left, Token const& op, Ast const& right) :
    mLeft(left),
    mOperator(op),
    mRight(right)
{}

void BinaryOperator::_debug() const
{
    mLeft._debug();
    mOperator._debug();
    mRight._debug();
}
