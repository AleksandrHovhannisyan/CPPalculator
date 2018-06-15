#ifndef OPERATOR_H
#define OPERATOR_H

#include <QMap>
#include <QString>

enum Associativity
{
    Left,
    Right
};

struct Operator
{
    Associativity associativity;
    int precedence;
    Operator(Associativity a,int p) : associativity(a), precedence(p) {}
    Operator() : Operator(Left, 1) {}
};

extern QMap<QString, Operator> operators;

#endif // OPERATOR_H
