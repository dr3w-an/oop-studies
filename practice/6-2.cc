#include <iostream>
#include <iomanip>
#include <math.h>


class Expression {
    public:
        virtual ~Expression() {}
        virtual void print() = 0;
        virtual double calculate(double variable) = 0;
        virtual Expression *derivative() = 0;
        virtual Expression *copy() = 0;
};

class Constant: public Expression {
    private:
        double value;

    public:
        Constant(double v): value(v) {}

        void print() {
            if (value >= 0)
                std::cout << value;
            else
                std::cout << '(' << value << ')';
        }
        double calculate(double variable) { return value; }
        Expression *derivative() { return new Constant(0); }
        Expression *copy() { return new Constant(value); }
};

class Variable: public Expression {
    private:
        char symbol;

    public:
        Variable(char s): symbol(s) {}

        void print() { std::cout << symbol; }
        double calculate(double variable) { return variable; }
        Expression *derivative() { return new Constant(1); }
        Expression *copy() { return new Variable(symbol); }
};

class Sum: public Expression {
    private:
        Expression *addendum_1, *addendum_2;

    public:
        Sum(Expression *a1, Expression *a2): addendum_1(a1), addendum_2(a2) {}

        void print() {
            std::cout << '(';
            addendum_1->print();
            std::cout << '+';
            addendum_2->print();
            std::cout << ')';
        }
        double calculate(double variable) {
            return addendum_1->calculate(variable) + addendum_2->calculate(variable);
        }
        Expression *derivative() {
            return new Sum(addendum_1->derivative(), addendum_2->derivative());
        }
        Expression *copy() {
            return new Sum(addendum_1, addendum_2);
        }
};

class Difference: public Expression {
    private:
        Expression *miniuend, *subtrahend;

    public:
        Difference(Expression *m, Expression *s): miniuend(m), subtrahend(s) {}

        void print() {
            std::cout << '(';
            miniuend->print(); std::cout << '-'; subtrahend->print();
            std::cout << ')';
        }
        double calculate(double variable) {
            return miniuend->calculate(variable) - subtrahend->calculate(variable);
        }
        Expression *derivative() {
            return new Difference(miniuend->derivative(), subtrahend->derivative());
        }
        Expression *copy() {
            return new Difference(miniuend, subtrahend);
        }
};

class Product: public Expression {
    private:
        Expression *factor_1, *factor_2;

    public:
        Product(Expression *f1, Expression *f2): factor_1(f1), factor_2(f2) {}

        void print() {
            std::cout << '(';
            factor_1->print(); std::cout << '*'; factor_2->print();
            std::cout << ')';
        }
        double calculate(double variable) {
            return factor_1->calculate(variable) * factor_2->calculate(variable);
        }
        Expression *derivative() {
            auto *addendum_1 = new Product(factor_1->derivative(), factor_2);
            auto *addendum_2 = new Product(factor_1, factor_2->derivative());
            return new Sum(addendum_1, addendum_2);
        }
        Expression *copy() {
            return new Product(factor_1, factor_2);
        }
};

class Quotient: public Expression {
    private:
        Expression *dividend, *divider;

    public:
        Quotient(Expression *d1, Expression *d2): dividend(d1), divider(d2) {}

        void print() {
            std::cout << '(';
            dividend->print(); std::cout << '/'; divider->print();
            std::cout << ')';
        }
        double calculate(double variable) {
            return dividend->calculate(variable) / divider->calculate(variable);
        }
        Expression *derivative() {
            auto miniuend = new Product(dividend->derivative(), divider);
            auto subtrahend = new Product(dividend, divider->derivative());
            auto numerator = new Difference(miniuend, subtrahend);
            auto denominator = new Product(divider, divider);
            return new Quotient(numerator, denominator);
        }
        Expression *copy() {
            return new Quotient(dividend, divider);
        }
};

class Sin: public Expression {
    private:
        Variable *var;

    public:
        Sin(Variable *v): var(v) {}

        void print() { std::cout << "sin("; var->print(); std::cout << ')'; }
        double calculate(double variable) { return sin(var->calculate(variable)); }
        Expression *derivative();
        Expression *copy() { return new Sin(var); }
};

class Cos: public Expression {
    private:
        Variable *var;

    public:
        Cos(Variable *v): var(v) {}

        void print() { std::cout << "cos("; var->print(); std::cout << ')'; }
        double calculate(double variable) { return cos(var->calculate(variable)); }
        Expression *derivative();
        Expression *copy() { return new Cos(var); }
};

Expression *Sin::derivative() {
    return new Cos(var);
}

Expression *Cos::derivative() {
    auto sign = new Constant(-1);
    auto factor = new Sin(var);
    return new Product(sign, factor);
}

class Exp: public Expression {
    private:
        Variable *exponent;

    public:
        Exp(Variable *v): exponent(v) {}

        void print() { std::cout << "e^"; exponent->print(); }
        double calculate(double variable) { return exp(exponent->calculate(variable)); }
        Expression *derivative() { return new Exp(exponent); }
        Expression *copy() { return new Exp(exponent); }
};

class Ln: public Expression {
    private:
        Variable *var;

    public:
        Ln(Variable *v): var(v) {}

        void print() { std::cout << "ln("; var->print(); std::cout << ')'; }
        double calculate(double variable) { return log(var->calculate(variable)); }
        Expression *derivative() {
            auto numerator = new Constant(1);
            return new Quotient(numerator, var);
        }
        Expression *copy() { return new Ln(var); }
};


int main() {
    // Тестирование функций вычисления выражений для операций
    Constant three_and_a_half(3.5);
    Constant two(2);

    auto *sum = new Sum(&three_and_a_half, &two);
    auto *difference = new Difference(&three_and_a_half, &two);
    auto *product = new Product(&three_and_a_half, &two);
    auto *quotient = new Quotient(&three_and_a_half, &two);

    Expression *operation_expressions[] = {sum, difference, product, quotient};
    for (int i = 0; i < 4; i++) {
        auto expression = operation_expressions[i];
        expression->print();
        std::cout << '=' << expression->calculate(0) << std::endl;
        delete expression;
    }
    std::cout << '\n';

    // Тестирование функций вычисления выражений для функций
    const double angle = 3.1415926 * 0.75;

    Variable x('x');
    x.print();
    std::cout << '=' << x.calculate(angle) << std::endl;

    auto *sinus = new Sin(&x);
    auto *cosinus = new Cos(&x);
    auto *exponent = new Exp(&x);
    auto *logarithm = new Ln(&x);

    Expression *function_expressions[] = {sinus, cosinus, exponent, logarithm};
    for (int i = 0; i < 4; i++) {
        auto expression = function_expressions[i];
        expression->print();
        std::cout << '=' << expression->calculate(angle) << std::endl;
    }
    std::cout << '\n';

    // Тестирование функций возвращения производных выражений для функций
    for (int i = 0; i < 4; i++) {
        auto expression = function_expressions[i];
        std::cout << '(';
        expression->print();
        std::cout << ")'=";
        expression->derivative()->print();
        std::cout << std::endl;
        delete expression;
    }

    return 0;
}
