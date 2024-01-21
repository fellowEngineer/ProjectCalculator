#pragma once;

#include "LexicalAnalyser.hpp"


class Parser
{
public:
    Parser() : Tokens({}) {}
    Parser(std::vector<Token>& inputTokens) : Tokens(inputTokens) {}

    double Parse()
    {
        unsigned int index = 0;
        double result = 0;
        Token::Type operation = Token::Type::NONE;

        while (index < this->Tokens.size())
        {
            /// Taking the current token from list of tokens.
            auto currentToken = this->Tokens.at(index);

            Token::Type currentTokenType = currentToken.getTokenType();
            std::string currentTokenValue = currentToken.getTokenValue();

            
            if (currentTokenType == Token::Type::INTEGER)
            {
                double value = stod(currentTokenValue);
                if (operation == Token::Type::NONE)
                    result = value;
                else if (operation == Token::Type::ADDITION)
                    result += value;
                else if (operation == Token::Type::SUBTRACTION)
                    result -= value;
                else if (operation == Token::Type::MULTIPLICATION)
                    result *= value;
                else if (operation == Token::Type::DIVISION)
                    result /= value;

                else
                    error();
                
            }
            else
            {
                operation = currentTokenType;
            }

            index++;
        }
        return result;
    }

protected:
    void error()
    {
        throw std::runtime_error("Parsing Error\n");
    }

private:
    std::vector<Token> Tokens;
};

