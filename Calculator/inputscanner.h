#ifndef INPUTSCANNER_H
#define INPUTSCANNER_H

#include <Qstring>
#include <sstream>
#include <QStringList>
#include <QDebug>

class InputScanner
{
private:
    QStringList tokens;

public:
    QStringList scanInput(QString userInput);
};

#endif // INPUTSCANNER_H
