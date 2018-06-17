#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "operator.h"
#include <QDebug>               // debug output
#include <QChar>
#include <QShortcut>            // keyboard input
#include <QKeySequence>         // keyboard input
#include <QFont>                // Qt fonts

// TODO add parentheses operations to calculator

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Basic variable setups
    ui->setupUi(this);
    input = ui->labelInput;
    digitAllowed = true;
    operatorAllowed = true;
    openParenthAllowed = false;
    closingParenthAllowed = false;
    numOpenParenths = 0;
    numClosingParenths = 0;

    // Connect digits' released() signals to on_digit_released
    connect(ui->button0, SIGNAL(released()), this, SLOT(on_digit_released()));
    connect(ui->button1, SIGNAL(released()), this, SLOT(on_digit_released()));
    connect(ui->button2, SIGNAL(released()), this, SLOT(on_digit_released()));
    connect(ui->button3, SIGNAL(released()), this, SLOT(on_digit_released()));
    connect(ui->button4, SIGNAL(released()), this, SLOT(on_digit_released()));
    connect(ui->button5, SIGNAL(released()), this, SLOT(on_digit_released()));
    connect(ui->button6, SIGNAL(released()), this, SLOT(on_digit_released()));
    connect(ui->button7, SIGNAL(released()), this, SLOT(on_digit_released()));
    connect(ui->button8, SIGNAL(released()), this, SLOT(on_digit_released()));
    connect(ui->button9, SIGNAL(released()), this, SLOT(on_digit_released()));

    // Connect binary operators' released() signals to on_binary_button_released
    connect(ui->buttonPlus, SIGNAL(released()),
            this, SLOT(on_binary_button_released()));
    connect(ui->buttonMinus, SIGNAL(released()),
            this, SLOT(on_binary_button_released()));
    connect(ui->buttonTimes, SIGNAL(released()),
            this, SLOT(on_binary_button_released()));
    connect(ui->buttonDivide, SIGNAL(released()),
            this, SLOT(on_binary_button_released()));

    // Shortcuts for math input via keyboard
    // TODO potential memory leaks
    QShortcut *shortcut0 = new QShortcut(QKeySequence("0"), this);
    QShortcut *shortcut1 = new QShortcut(QKeySequence("1"), this);
    QShortcut *shortcut2 = new QShortcut(QKeySequence("2"), this);
    QShortcut *shortcut3 = new QShortcut(QKeySequence("3"), this);
    QShortcut *shortcut4 = new QShortcut(QKeySequence("4"), this);
    QShortcut *shortcut5 = new QShortcut(QKeySequence("5"), this);
    QShortcut *shortcut6 = new QShortcut(QKeySequence("6"), this);
    QShortcut *shortcut7 = new QShortcut(QKeySequence("7"), this);
    QShortcut *shortcut8 = new QShortcut(QKeySequence("8"), this);
    QShortcut *shortcut9 = new QShortcut(QKeySequence("9"), this);
    QShortcut *shortcutDecimal = new QShortcut(QKeySequence("."), this);
    QShortcut *shortcutPlus = new QShortcut(QKeySequence("+"), this);
    QShortcut *shortcutMinus = new QShortcut(QKeySequence("-"), this);
    QShortcut *shortcutTimes = new QShortcut(QKeySequence("SHIFT+8"), this);
    QShortcut *shortcutDivide = new QShortcut(QKeySequence("/"), this);
    QShortcut *shortcutOpenParenth = new QShortcut(QKeySequence("SHIFT+9"), this);
    QShortcut *shortcutCloseParenth = new QShortcut(QKeySequence("SHIFT+0"), this);
    QShortcut *shortcutEnter = new QShortcut(QKeySequence(Qt::Key_Return), this);
    QShortcut *shortcutBackspace = new QShortcut(QKeySequence("Backspace"), this);
    connect(shortcut0, SIGNAL(activated()), ui->button0, SLOT(click()));
    connect(shortcut1, SIGNAL(activated()), ui->button1, SLOT(click()));
    connect(shortcut2, SIGNAL(activated()), ui->button2, SLOT(click()));
    connect(shortcut3, SIGNAL(activated()), ui->button3, SLOT(click()));
    connect(shortcut4, SIGNAL(activated()), ui->button4, SLOT(click()));
    connect(shortcut5, SIGNAL(activated()), ui->button5, SLOT(click()));
    connect(shortcut6, SIGNAL(activated()), ui->button6, SLOT(click()));
    connect(shortcut7, SIGNAL(activated()), ui->button7, SLOT(click()));
    connect(shortcut8, SIGNAL(activated()), ui->button8, SLOT(click()));
    connect(shortcut9, SIGNAL(activated()), ui->button9, SLOT(click()));
    connect(shortcutDecimal, SIGNAL(activated()), ui->buttonDecimalPoint, SLOT(click()));
    connect(shortcutPlus, SIGNAL(activated()), ui->buttonPlus, SLOT(click()));
    connect(shortcutMinus, SIGNAL(activated()), ui->buttonMinus, SLOT(click()));
    connect(shortcutTimes, SIGNAL(activated()), ui->buttonTimes, SLOT(click()));
    connect(shortcutDivide, SIGNAL(activated()), ui->buttonDivide, SLOT(click()));
    connect(shortcutOpenParenth, SIGNAL(activated()), ui->buttonOpenParenth, SLOT(click()));
    connect(shortcutCloseParenth, SIGNAL(activated()), ui->buttonCloseParenth, SLOT(click()));
    connect(shortcutEnter, SIGNAL(activated()), ui->buttonEquals, SLOT(click()));
    connect(shortcutBackspace, SIGNAL(activated()), ui->buttonBack, SLOT(click()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* Used by other functions when checking if an operator was
 * already applied directly before the current attempt at
 * either evaluating the expression or adding a new operator.
 */
bool MainWindow::operatorUsedDirectlyBefore() const
{
    if(input->text().length() >= 2)
    {
        // Operators have a space after (e.g., " + "). Hence length()-2.
        // If input is like "1 + 2", return false b/c " " is not operator.
        return ((bool)operators.count(input->text().at(input->text().length()-2)));
    }
    return false;
}


/* When a digit button is pressed, its text gets relayed to input label */
void MainWindow::on_digit_released()
{
    if(digitAllowed)
    {
        QPushButton *button = (QPushButton*)sender();
        operatorAllowed = true;
        openParenthAllowed = false;
        closingParenthAllowed = true;

        if(input->text().length() == 1 && input->text()[0] == '0')
        {
            input->setText(input->text().replace(0, 1, button->text()));
        }
        else
        {
            input->setText(input->text().append(button->text()));
        }
    }
}

/* When the decimal point button is released, add a decimal point to
 * input label if we haven't done so already (see decimalHasBeenAdded).
*/
void MainWindow::on_buttonDecimalPoint_released()
{
    // TODO prevent entry of multiple decimal points
    if(!operatorUsedDirectlyBefore())
    {
        input->setText(input->text() + ".");
    }
}

/* Handles functionality of negating an input expression.
 * Negating an expression applies the negative sign to the
 * last number entered (if one exists). Negating a
 * negative number will remove the negative sign.
 */
void MainWindow::on_buttonNegate_released()
{
    if(operatorUsedDirectlyBefore()){ return; }

    // Check if there are currently any operators in input
    bool inputHasOperators = false;
    for(int i = 0; i < input->text().length(); i++)
    {
        if(operators.count(input->text().at(i)) == 1)
        {
            inputHasOperators = true;
            break;
        }
    }

    // Input expression contains operators
    if(inputHasOperators)
    {
        int indexOfLastWhitespace = input->text().lastIndexOf(' ');

        // If the number is negative and part of an expression w/ ops
        if(input->text().at(indexOfLastWhitespace+1) == '-')
        {
            input->setText(input->text().replace(indexOfLastWhitespace+1, 1, ""));
        }

        // Otherwise, just a positive number part of an expression w/ ops
        else
        {
            input->setText(input->text().insert(indexOfLastWhitespace+1, '-'));
        }
    }

    // TODO or parenthetical expression?
    // No operators and already negative number
    else if(input->text().at(0) == '-')
    {
        input->setText(input->text().replace(0, 1, ""));
    }

    // No operators and positive number
    else
    {
        input->setText(input->text().prepend("-"));
    }
}

/* If the user presses any binary operation's button, like
 * plus, minus, multiply, or divide, this slot will be called
 * to insert the appropriate operation into the current input.
 */
void MainWindow::on_binary_button_released()
{
    QPushButton *button = (QPushButton*)sender();

    if(operatorAllowed)
    {
        input->setText(input->text().append(" " + button->text() + " "));
        digitAllowed = true;
        operatorAllowed = false;
        openParenthAllowed = true;
        closingParenthAllowed = false;
    }
}

/* If the user releases the = button, then they want
 * the answer to their input to be calculated.
 * Emits input_is_ready signal to give Calculator
 * the input it needs to do its job.
 */
void MainWindow::on_buttonEquals_released()
{
    if(!operatorUsedDirectlyBefore() &&
            numOpenParenths == numClosingParenths)
    {
        emit input_is_ready(input->text());
    }
}

/* Pretty straightforward. Basically, if the user
 * presses and releases the clear button, then
 * set the input string to just 0.
 */
void MainWindow::on_buttonClear_released()
{
    input->setText("0");
    digitAllowed = true;
    operatorAllowed = true;
    openParenthAllowed = false;
    closingParenthAllowed = false;
    numOpenParenths = 0;
    numClosingParenths = 0;
}

// TODO IMPORTANT! Does not undo any flags that were set!!!
// maybe create two status objects that encapsulate the flags and have pointers to them
// that destructor cleans up; one is for previous state and one is for current state
// and when backspace released, we should update current state to previous state

// TODO backspace for an operator should remove space before and after the operator
void MainWindow::on_buttonBack_released()
{
    if(input->text().length() == 1)
    {
        input->setText("0");
    }
    else
    {
        QString text = input->text();
        if(text.at(text.length()-1) == '('){ numOpenParenths--; }
        else if(text.at(text.length()-1) == ')'){ numClosingParenths--; }
        else{ input->setText(text.remove(text.length()-1, 1)); }
    }
}

void MainWindow::on_buttonRoot_released()
{
    // TODO nth root
}

void MainWindow::on_buttonOpenParenth_released()
{
    if(openParenthAllowed)
    {
        input->setText(input->text().append("("));
        numOpenParenths++;
        digitAllowed = true;
        operatorAllowed = false;
        closingParenthAllowed = true;
    }
}

void MainWindow::on_buttonCloseParenth_released()
{
    if(closingParenthAllowed &&
            (numClosingParenths < numOpenParenths))
    {
        input->setText(input->text().append(")"));
        numClosingParenths++;
        digitAllowed = false;
        operatorAllowed = true;
        openParenthAllowed = false;
    }
}

void MainWindow::on_buttonXSquared_released()
{
    // TODO x squared
}

void MainWindow::on_buttonSqrt_released()
{
    // TODO square root
}
