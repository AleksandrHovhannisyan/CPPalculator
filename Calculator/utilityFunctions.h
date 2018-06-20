#ifndef UTILITY_H
#define UTILITY_H

#include <QString>
#include <QChar>

/* Checks if the given character token is a negation within the provided context.
 * @param token - the ambiguous character in question, which may be negation or subtraction
 * @param context - the string in which token is found
 * @param i - the index at which the given token appears within the context string
 */
bool tokenIsNegation(QChar token, QString context, int i);

/* Returns true if a token is a valid operator. */
bool isOperator(QString token);

/* Returns true if a token is a valid number. */
bool isNumber(QString token);

#endif // UTILITY_H
