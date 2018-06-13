#include "calculator.h"


/* MainWindow sends the input_is_ready() signal to
 * this slot to indicate that the user has provided
 * their input and is awaiting a calculation.
 */
void Calculator::on_input_given(QString input)
{
    this->input = input;
    qDebug() << "Got the input! It's: " + input;
}
