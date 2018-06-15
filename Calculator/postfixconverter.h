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
    PostfixConverter();
    void convertToPostfix(const QStringList& input);
    QStringList getOutput() const { return output; }
    bool conversionFailed() { return failedToConvert; }

private:
    QStringList output;
    bool failedToConvert;

    bool isInteger(QString token);
    bool isOperator(QString token){ return operators.count(token) == 1; }
    void popOperator(QStack<QString>& operatorStack);
};


#endif // POSTFIXCONVERTER_H
