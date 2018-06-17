#include "calculator.h"
#include <QDebug>
#include <QstringList>
#include <sstream>
#include "operator.h"

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
    qDebug() << "Input accepted and parsed to postfix.";
    QStringList tokens;
    QString runningToken = "";

    for(int i = 0; i < input.length(); i++)
    {
        QChar c = input[i];

        // Digits
        if(c.isDigit() || c == '.' || c == '-')
        {
            runningToken.append(c);
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

    return tokens;
}


/* Called as soon as input is ready for processing.
 */
void Calculator::run()
{
    QStringList tokens = postfixConverter.convertToPostfix(scanInputAndGrabTokens());

    // Uncomment for debugging
    for(QStringList::Iterator it = tokens.begin(); it != tokens.end(); ++it)
    {
        qDebug() << (*it);
    }

}
