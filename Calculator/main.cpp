#include "mainwindow.h"
#include <QApplication>
#include "calculator.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    Calculator calculator;
    // MainWindow signals Calculator when input is ready for processing
    QObject::connect(&window, SIGNAL(input_is_ready(QString)),
                     &calculator, SLOT(on_input_given(QString)));
    window.show();
    return app.exec();
}
