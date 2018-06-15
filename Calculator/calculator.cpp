#include "calculator.h"
#include <QDebug>
#include <QstringList>

/* MainWindow sends the input_is_ready() signal to
 * this slot to indicate that the user has provided
 * their input and is awaiting a calculation.
 */
void Calculator::on_input_given(QString input)
{
    this->input = input;
    run();
}

/* Called as soon as input is ready for processing.
 * Extracts each individual token from the input
 * string and stores it in a QStringList.
 */
void Calculator::run()
{
    QStringList tokens = input.split(" ", QString::SkipEmptyParts);

    /* // Don't you just love debugging...
    for(QStringList::Iterator it = tokens.begin(); it != tokens.end(); ++it)
    {
        qDebug() << (*it);
    }
    */

    postfixConverter.convertToPostfix(tokens);
    QStringList postfix = postfixConverter.getOutput();

     // More debugging!
    for(QStringList::Iterator it = postfix.begin(); it != postfix.end(); ++it)
    {
        qDebug() << (*it);
    }
}
