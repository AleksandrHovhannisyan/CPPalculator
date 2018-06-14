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
 */
void Calculator::run()
{
    QStringList tokens = parser.scanInput(input);
}
