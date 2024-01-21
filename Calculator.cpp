#include "Interpreter.hpp"

class Calculator
{
private:
    std::string expression;

public:
    Calculator() : expression("") {}
    Calculator(std::string inputExpression) : expression(inputExpression) {}
    double calculate()
    {
        Interpreter intre(this->expression);
        return intre.execute();
    }
    double evaluate()
    {
        Interpreter intre(this->expression);
        return intre.execute();
    }
    ~Calculator()
    {
    }
};
