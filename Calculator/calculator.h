#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <mainwindow.h>

// TODO - Calculator should have a slot where we can plug in a signal from
// mainwindow telling Calculator that the output has requested a result (=),
// in which case the Calculator will take that output somehow
// and use it to produce postfix notation and do all that nonsense.
// And then the calculator should send a signal to the mainwindow
// telling it to display the result in its output label.


class Calculator{

public:
    void run();

private:
};



#endif // CALCULATOR_H
