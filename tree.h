#pragma once

#include <memory>

/**
 * The operators are the abstract syntax tree's 
 * internal nodes.
 */
enum class Operator { PLUS, MINUS, MULTIPLY, DIVIDE };

/**
 * A (abstract syntax) tree contains operators
 * (+,-,/,*) as internal nodes and digits ([0-9])
 * as leaves. Given a valid input, a tree
 * will always have at least 3 nodes: 2 digits as 
 * leaves and 1 operator as root.
 *
 * A tree is composed of a combination of BinOpTrees.
 */
class Tree
{
};


/**
 * A BinOpTree has the operator as a root and two 
 * Trees as leaves.
 */
class BinOpTree : public Tree
{
public:
    BinOpTree(
            std::unique_ptr<Tree>,
            Operator,
            std::unique_ptr<Tree>);

private:
    std::unique_ptr<Tree> mLeft;
    Operator mOperator;
    std::unique_ptr<Tree> mRight;
};


/**
 * A digit is a single node of the abstract syntax tree,
 * and is always a leaf.
 */
class Digit : public Tree
{
public:
    Digit(int);
private:
    int mValue;
};
