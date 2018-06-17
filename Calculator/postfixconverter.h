#ifndef POSTFIXCONVERTER_H
#define POSTFIXCONVERTER_H

/* Implementation of the classic Shunting-Yard algorithm.
 * Converts a list of mathematical tokens into postfix
 * notation for further processing.
 */

#include <QString>
#include <QMap>
#include <QStringList>
#include "operator.h"

class PostfixConverter
{
public:
    QStringList convertToPostfix(const QStringList& input);

private:
    QStringList output;

    bool isNumber(QString token);
    bool isOperator(QString token){ return operators.count(token) == 1; }
    void popOperator(QStack<QString>& operatorStack);
};


#endif // POSTFIXCONVERTER_H
