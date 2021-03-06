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
    void output_is_ready(QString output);

public slots:
    /* Called when user hits = button in MainWindow */
    void on_input_given(QString input);

public:
    void run();
    QString evaluateInput(const QStringList &tokens);

private:
    QString input;
    PostfixConverter postfixConverter;
    QStringList scanInputAndGrabTokens();
};



#endif // CALCULATOR_H
