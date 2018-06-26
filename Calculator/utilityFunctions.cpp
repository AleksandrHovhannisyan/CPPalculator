#include "utilityFunctions.h"
#include "operator.h"


/* A token is a negation operator if it's an initial negative sign
 * or a negative sign that follows some other operator, like a
 * multiplication, division, or exponentiation, or if it follows an
 * opening parenthesis.
*/
bool tokenIsNegation(QChar c, QString context, int i)
{
    bool negativeSign = (c == '-');
    bool initialNegative = (i == 0 && negativeSign);
    bool previousIsMultOpOrParenth = (i >= 1 && (context[i-1] == MULT ||
                               context[i-1] == DIV ||
                               context[i-1] == EXP ||
                               context[i-1] == "("));
    bool other = (negativeSign && previousIsMultOpOrParenth);

    return initialNegative || other;
}

bool isOperator(QString token)
{
    return operators.contains(token);
}

bool isNumber(QString token)
{
    // Negative numbers
    if(token.at(0) == '-' && token.length() > 1) { return true; }

    // All others
    for(int i = 0; i < token.length(); i++)
    {
        QChar currentCharacter = token.at(i);
        if(!currentCharacter.isDigit() && currentCharacter != '.') { return false; }
    }

    return true;
}
