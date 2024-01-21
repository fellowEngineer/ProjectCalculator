#pragma once

// #include <iostream>
// #include <string>
// #include <vector>
#include <stdexcept>

#include "Token.hpp"

class Tokenizer
{
private:
    std::string expression;
    size_t currentPosition;

protected:
    void error()
    {
        throw std::runtime_error("Invalid Token Type\n");
    }

public:
    Tokenizer() : expression(""), currentPosition(0){};
    Tokenizer(std::string inputExpression) : expression(inputExpression), currentPosition(0){};

    std::vector<Token> Tokenize()
    {
        /*
        if (currentPosition > this->expression.size()-1)
        {
            return {Token::Type::NONE, "no expression"};
        }
        */

        std::vector<Token> Tokens;

        while (this->currentPosition < this->expression.size())
        {
            /// if the chrrent character is a white space
            if (this->expression[this->currentPosition] == ' ')
            {
                this->currentPosition++;
                continue;
            }

            /// if the current character is equal to Addition
            else if (this->expression[this->currentPosition] == '+')
            {
                Tokens.push_back({Token::Type::ADDITION, "+"});
                this->currentPosition++;
            }

            /// if the current character is equal to SUBTRACTION
            else if (this->expression[this->currentPosition] == '-')
            {
                Tokens.push_back({Token::Type::SUBTRACTION, "-"});
                this->currentPosition++;
            }

            /// if the current character is equal to MULTIPLICATION
            else if (this->expression[this->currentPosition] == '*')
            {
                Tokens.push_back({Token::Type::MULTIPLICATION, "x"});
                this->currentPosition++;
            }

            /// if the current character is equal to DIVISION
            else if (this->expression[this->currentPosition] == '/')
            {
                Tokens.push_back({Token::Type::DIVISION, "/"});
                this->currentPosition++;
            }
            /// if the current character is equal to any number
            else if (isdigit(this->expression[this->currentPosition]))
            {
                std::string currentToken = "";
                currentToken += this->expression[this->currentPosition];
                this->currentPosition++;

                /// if the number has multiple digit or a decimal point
                while (isdigit(this->expression[this->currentPosition]) or this->expression[this->currentPosition] == '.')
                    currentToken = currentToken + this->expression[this->currentPosition++];

                Tokens.push_back({Token::Type::INTEGER, currentToken});
            }
            else
            {
                // lets assume that only +, number are the valid tokens in input
                Tokens.push_back({Token::Type::NONE, "'No more Tokens'"});
                error();
            }
        }
        return Tokens;
    }

    ~Tokenizer()
    {
    }
};