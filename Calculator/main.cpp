#include "mainwindow.h"
#include <QApplication>
#include "calculator.h"
#include "operator.h"   // for global "operators" map (see below for def)


// TODO let user copy  with ctrl+c
// TODO resizing screen? oof

QMap<QString, Operator> operators;

/* Adds all valid operators for this calculator program to the global
 * operators map.
 */
void setUpOperators()
{
    Operator plus(Left, 1);
    Operator minus(Left, 1);
    Operator times(Left, 2);
    Operator divide(Left, 2);
    Operator root(Right, 3);
    operators["+"] = plus;
    operators["-"] = minus;
    operators["×"] = times;
    operators["÷"] = divide;
    operators["rt"] = root;
}

int main(int argc, char *argv[])
{
    setUpOperators();
    QApplication app(argc, argv);
    MainWindow window;
    Calculator calculator;

    // MainWindow signals Calculator when input is ready for processing
    QObject::connect(&window, SIGNAL(input_is_ready(QString)),
                     &calculator, SLOT(on_input_given(QString)));

    // And Calculator signals MainWindow when output is ready for printing
    QObject::connect(&calculator, SIGNAL(output_is_ready(QString)),
                     &window, SLOT(on_output_is_ready(QString)));

    window.show();
    return app.exec();
}
