#pragma once

#include <memory>

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
public:
    virtual char GetValue() const = 0;

    virtual ~Tree() {}
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
            char,
            std::unique_ptr<Tree>);

    std::unique_ptr<Tree> mLeft;
    std::unique_ptr<Tree> mRight;

    char GetValue() const;
private:
    char mOperator;
};


/**
 * A digit is a single node of the abstract syntax tree,
 * and is always a leaf.
 */
class Digit : public Tree
{
public:
    Digit(int);

    char GetValue() const;

private:
    int mValue;
};
