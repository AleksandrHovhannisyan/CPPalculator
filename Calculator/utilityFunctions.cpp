#include "utilityFunctions.h"


bool tokenIsNegation(QChar c, QString context, int i)
{
    return (c == '-' &&
                (i == 0 || context[i-1] == "×" || context[i-1] == "÷"));
}
