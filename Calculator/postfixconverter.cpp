#include "postfixconverter.h"
#include "utilityFunctions.h"
#include <QStack>
#include <QChar>


/* Parses an infix mathematical expression to postfix notation
 * using the Shunting-yard algorithm. Returns the list of tokens.
 */
QStringList PostfixConverter::convertToPostfix(const QStringList& input)
{
    // Allows for reuse of converter
    output.clear();

    // Note: operatorStack may contain parentheses, which are NOT operators
    QStack<QString> operatorStack;

    for(int index = 0; index < input.size(); index++)
    {
        QString currentToken = input.at(index);

        // Token is a number
        if(isNumber(currentToken))
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
    }

    // Final emptying
    while(!operatorStack.empty() && isOperator(operatorStack.top()))
    {
        popOperator(operatorStack);
    }

    return output;
}

/* A fairly common operation. See @convertToPostfix. */
void PostfixConverter::popOperator(QStack<QString>& operatorStack)
{
    output.push_back(operatorStack.top());
    operatorStack.pop();
}
