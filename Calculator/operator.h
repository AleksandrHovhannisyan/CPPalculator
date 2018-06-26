#ifndef OPERATOR_H
#define OPERATOR_H

#include <QMap>
#include <QString>

// Operator symbols we'll need to reuse throughout program
const static QString MULT = QString::QString(0x00d7);
const static QString DIV = QString::QString(0x00f7);
const static QString ADD = "+";
const static QString SUB = "-";
const static QString EXP = "^";
const static QString ROOT = "rt";

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
