#include "calculator.h"
#include "operator.h"
#include "utilityFunctions.h"
#include <QDebug>
#include <QStringList>
#include <QString>
#include <QStack>

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

        /* // Uncomment to debug
        qDebug() << "Character: " << c;
        qDebug() << "As a string: " << QString::QString(c);
        qDebug() << "Running token: " << runningToken;
        */

        // Digits, including decimals or negation
        if(c.isDigit() || c == '.' || tokenIsNegation(c, input, i))
        {
            runningToken.append(c);
            // If the digit is at the end of the input, push it
            if(i == input.length()-1) { tokens.push_back(runningToken); }
        }
        // Special case of root, two characters
        else if(c == 'r')
        {
            tokens.push_back(runningToken);
            runningToken = "";
            tokens.push_back(c + input[++i]);
        }
        // Square root character
        else if (c == 0x221a)
        {
            // Because sqrt is essentially (2)rt(x)
            input.replace(i, 1, "");
            input.insert(i, "2rt");
            // To read the 2 after i increments at end of iteration
            i--;
        }
        // Other operators
        else if(isOperator(QString::QString(c)))
        {
            if(runningToken != ""){ tokens.push_back(runningToken); runningToken = ""; }
            tokens.push_back(QString::QString(c));
        }
        // Parentheses
        else if(c == '(' || c == ')')
        {
            // Have to do the != "-" check in case we have something like 5*-(2)
            if(runningToken != "" && runningToken != "-"){ tokens.push_back(runningToken); runningToken = ""; }
            tokens.push_back(QString::QString(c));
        }
    }

    /* // Uncomment to debug
    qDebug() << "----------------INPUT TOKENS-------------------";
    for(int i = 0; i < tokens.size(); i++)
    {
        qDebug() << tokens[i];
    }
    */

    return tokens;
}

/* Calculates the floating-point value of the input. */
QString Calculator::evaluateInput(const QStringList &tokens)
{
    QStack<double> operands;

    for(QStringList::const_iterator i = tokens.begin(); i != tokens.end(); ++i)
    {
        QString token = (*i);

        // Number
        if(isNumber(token))
        {
            operands.push(token.toDouble());
        }
        // Operator
        else
        {
            double rightOperand = operands.pop();
            double leftOperand = operands.pop();

            if(token == ADD){ operands.push(leftOperand+rightOperand); }
            else if(token == SUB){ operands.push(leftOperand-rightOperand); }
            else if(token == MULT){ operands.push(leftOperand*rightOperand); }
            else if(token == EXP){ operands.push(std::pow(leftOperand, rightOperand)); }
            else if(token == ROOT)
            {
                if(leftOperand == 0){ return "No division by zero"; }
                else if(rightOperand < 0){ return "No negative radicands"; }
                else{ operands.push(std::pow(rightOperand, 1/leftOperand)); }
            }
            else if(token == DIV)
            {
                if(rightOperand == 0){ return "No division by zero"; }
                else{ operands.push(leftOperand/rightOperand); }
            }

        }
    }

    return QString::number(operands.pop());
}

/* Called as soon as input is ready for processing. */
void Calculator::run()
{
    QStringList tokens = postfixConverter.convertToPostfix(scanInputAndGrabTokens());

    // Uncomment to debug
    /* qDebug() << "Postfix choo choo!!";
    for(int i = 0; i < tokens.size(); i++)
    {
        qDebug() << tokens[i];
    }
    */

    QString answer = evaluateInput(tokens);
    emit output_is_ready(answer);
}
