#include "utilityFunctions.h"
#include "operator.h"

bool tokenIsNegation(QChar c, QString context, int i)
{
    QString prev = context[i-1];
    return (c == '-' &&
                (i == 0 || prev == "×" || prev == "÷" || prev == "^" || prev == "("));
}

bool isOperator(QString token)
{
    return operators.count(token);
}

bool isNumber(QString token)
{
    // Negative numbers
    if(token.at(0) == '-' && token.length() > 1) { return true; }

    // All others
    for(int i = 0; i < token.length(); i++)
    {
        QChar currentCharacter = token.at(i);
        if(!currentCharacter.isDigit() && currentCharacter != '.') { return false; }
    }

    return true;
}
