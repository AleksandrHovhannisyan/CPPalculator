#include "postfixconverter.h"
#include <QStack>
#include <QChar>

PostfixConverter::PostfixConverter()
{
    failedToConvert = false;
}

/* Private helper. Checks if a token represents an integer.*/
bool PostfixConverter::isInteger(QString token)
{
    // Negative numbers
    // TODO this is bad logic
    if(token.at(0) == '-' && token.length() > 1) { return true; }

    // TODO isInteger should be isNumber and decimal supported
    for(int i = 0; i < token.length(); i++)
    {
        QChar currentCharacter = token.at(i);
        if(!currentCharacter.isDigit()) { return false; }
    }

    return true;
}

/* Parses an infix mathematical expression to postfix notation
 * using the Shunting-yard algorithm.
 */
void PostfixConverter::convertToPostfix(const QStringList& input)
{
    // Allows for reusability of the converter
    output.clear();
    failedToConvert = false;

    // Note: operatorStack may contain parentheses, which are NOT operators
    QStack<QString> operatorStack;

    for(int index = 0; index < input.size(); index++)
    {
        QString currentToken = input.at(index);

        // Token is an integer
        // TODO in the future, add "currentToken == "pi" || currentToken == "e" ||" to the check
        if(isInteger(currentToken))
        {
            output.push_back(currentToken);
        }
        // Token is an operator
        else if(isOperator(currentToken))
        {
            while( !operatorStack.empty() && isOperator(operatorStack.top()) &&
                 ( (operators[currentToken].associativity == Left
                    && operators[currentToken].precedence <=
                    operators[operatorStack.top()].precedence)
                    ||
                    (operators[currentToken].associativity == Right
                    && operators[currentToken].precedence < operators[operatorStack.top()].precedence)
                 )
                 )
            {
                popOperator(operatorStack);
            }

            operatorStack.push(currentToken);
        }
        // Token is left parenthesis
        else if(currentToken == "(")
        {
            operatorStack.push(currentToken);
        }
        // Token is right parenthesis
        else if(currentToken == ")")
        {
            while(operatorStack.top() != "(")
            {
                popOperator(operatorStack);
            }

            operatorStack.pop();
        }
        // Token is invalid if none of the above were true
        else
        {
            failedToConvert = true;
            return;
        }
    }

    // Final emptying
    while( !operatorStack.empty() && isOperator(operatorStack.top()) )
    {
        popOperator(operatorStack);
    }
}

/* A fairly common operation. See @convertToPostfix. */
void PostfixConverter::popOperator(QStack<QString>& operatorStack)
{
    output.push_back(operatorStack.top());
    operatorStack.pop();
}
