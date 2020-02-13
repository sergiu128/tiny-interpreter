#pragma once

enum class TokenType 
{
    DIGIT,
    LPAREN,
    RPAREN,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE
};

class Token
{
public:
    Token(TokenType, char);

    TokenType GetType() const;

    char GetValue() const;
private:
    TokenType mType;
    char mValue;
};
