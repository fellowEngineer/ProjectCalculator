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


int main()
{

    std::string inputExpression = "2+2";
    while (!inputExpression.empty())
    {
        std::cout << "calc> ";
        std::getline(std::cin, inputExpression);

        try
        {
            Calculator calculator(inputExpression);
            std::cout << "Result is : " << calculator.calculate();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

        std::cout << std::endl;
    }

    return 0;
}