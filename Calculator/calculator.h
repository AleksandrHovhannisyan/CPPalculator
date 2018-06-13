#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <mainwindow.h>
#include <QObject>
#include <QString>
#include <QDebug>




class Calculator: public QObject
{
    Q_OBJECT

signals:
    // TODO add a signal that indicates error was encountered
    // MainWindow should then clear its output label for a redo
    void output_is_ready(QString output);

public slots:
    /* Called when user hits = button in MainWindow */
    void on_input_given(QString input);

public:
    void run();

private:
    QString input;
    QString output;
};



#endif // CALCULATOR_H
