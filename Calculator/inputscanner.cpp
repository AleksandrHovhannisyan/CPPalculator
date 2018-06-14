#include "inputscanner.h"

/* Splits user-entered string into tokens with whitespace as delimiter. */
QStringList InputScanner::scanInput(QString userInput)
{
    QStringList list = userInput.split(" ");

    for(QStringList::Iterator it = list.begin(); it != list.end(); ++it)
    {
        qDebug() << (*it) << " ";
    }

    return list;
}
