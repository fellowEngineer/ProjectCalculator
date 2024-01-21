#pragma once

#include "LexicalAnalyser.hpp"
#include "SyntacticalAnalyser.hpp"

class Interpreter
{
private:
    std::string expression;

public:
    Interpreter() : expression("") {}
    Interpreter(std::string inputExpression) : expression(inputExpression) {}

    double execute()
    {
        try
        {
            Tokenizer tokenizer(this->expression);
            auto tokens = tokenizer.Tokenize();
            Parser parser(tokens);

            return parser.Parse();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

        return 0;
    }

    ~Interpreter()
    {
    }
};
