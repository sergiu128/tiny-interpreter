#include "binary_operator.h"

BinaryOperator::BinaryOperator(Ast const& left, Token const& op, Ast const& right) :
    mLeft(left),
    mOperator(op),
    mRight(right)
{}
