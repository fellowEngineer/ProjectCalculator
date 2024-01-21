#pragma once

#include <iostream>
#include <string>
#include <vector>

class Token
{
public:
    enum class Type : int
    {
        INTEGER,
        ADDITION,
        SUBTRACTION,
        MULTIPLICATION,
        DIVISION,
        NONE
    };

    Token() : TokenType(Token::Type::NONE), TokenValue("") {}

    Token(Token::Type inputTokenType, std::string inputTokenValue) : TokenType(inputTokenType), TokenValue(inputTokenValue) {}

    Token::Type getTokenType() const
    {
        return this->TokenType;
    }

    std::string getTokenValue() const
    {
        return this->TokenValue;
    }

    friend std::ostream &operator<<(std::ostream &ost, Token token)
    {
        ost << "Token::Type : " << token.getTypeStr() << ", Token::Value : " << token.getTokenValue() << std::endl;
        return ost;
    }

    ~Token()
    {
        // std::cout << "Object Destroid\n";
    }

protected:
    static std::vector<std::string> typeStr;
    std::string getTypeStr()
    {
        return Token::typeStr[(int)this->TokenType];
    }

private:
    Token::Type TokenType;
    std::string TokenValue;
};

// defination of static variable
std::vector<std::string> Token::typeStr = {"INTEGER", "ADDITION", "SUBTRACTION", "MULTIPLICATION", "DIVISION", "NONE"};
