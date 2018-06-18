#include "calculator.h"
#include "operator.h"
#include "utilityFunctions.h"
#include <QDebug>
#include <QStringList>
#include <QString>
#include <QStack>
#include <sstream>

/* MainWindow sends the input_is_ready() signal to
 * this slot to indicate that the user has provided
 * their input and is awaiting a calculation.
 */
void Calculator::on_input_given(QString input)
{
    this->input = input;
    run();
}

/* Takes user's input and processes it to extract
 * individual tokens, such as numbers, operators,
 * and parentheses.
 */
QStringList Calculator::scanInputAndGrabTokens()
{
    QStringList tokens;
    QString runningToken = "";

    for(int i = 0; i < input.length(); i++)
    {
        QChar c = input[i];

        // Digits, including decimals or negation
        if(c.isDigit() || c == '.' || tokenIsNegation(c, input, i))
        {
            runningToken.append(c);
            // If the digit is at the end of the input, push it
            if(i == input.length()-1) { tokens.push_back(runningToken); }
        }
        // Operators
        else if(operators.count(QString::QString(c)))
        {
            tokens.push_back(runningToken);
            runningToken = "";
            tokens.push_back(QString::QString(c));
        }
        // Parentheses
        else if(c == '(' || c == ')')
        {
            if(runningToken != ""){ tokens.push_back(runningToken); runningToken = ""; }
            tokens.push_back(QString::QString(c));
        }
    }

    qDebug() << "----------------INPUT TOKENS-------------------";
    for(int i = 0; i < tokens.size(); i++)
    {
        qDebug() << tokens[i];
    }

    return tokens;
}

/* Calculates the floating-point value of the input. */
QString Calculator::evaluateInput(const QStringList &tokens)
{
    QStack<double> operands;
    bool divByZero = false;

    for(QStringList::const_iterator i = tokens.begin(); i != tokens.end(); ++i)
    {
        QString token = (*i);

        // Operator
        if(operators.count(token))
        {
            double rightOperand = operands.pop();
            double leftOperand = operands.pop();

            if(token == "+"){ operands.push(leftOperand+rightOperand); }
            else if(token == "-"){ operands.push(leftOperand-rightOperand); }
            else if(token == "×"){ operands.push(leftOperand*rightOperand); }
            else if(token == "÷")
            {
                divByZero = (rightOperand == 0);
                if(divByZero){ return "No division by zero"; }
                operands.push(leftOperand/rightOperand);
            }
        }
        // Number
        else { operands.push(token.toDouble()); }
    }

    return QString::number(operands.pop());
}

/* Called as soon as input is ready for processing. */
void Calculator::run()
{
    QStringList tokens = postfixConverter.convertToPostfix(scanInputAndGrabTokens());
    QString answer = evaluateInput(tokens);
    emit output_is_ready(answer);
}
