#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <mainwindow.h>
#include <QObject>
#include <QString>
#include "postfixconverter.h"

class Calculator: public QObject
{
    Q_OBJECT

signals:
    // TODO add another signal that indicates error was encountered
    // MainWindow should then clear its output label for a redo
    void output_is_ready(QString output);

public slots:
    /* Called when user hits = button in MainWindow */
    void on_input_given(QString input);

public:
    void run();
    double evaluateInput(const QStringList &tokens);

private:
    QString input;
    PostfixConverter postfixConverter;
    QStringList scanInputAndGrabTokens();
};



#endif // CALCULATOR_H
