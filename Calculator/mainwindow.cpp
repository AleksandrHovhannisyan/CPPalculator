#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "operator.h"
#include <QDebug>
#include <QChar>

// TODO add parentheses operations to calculator

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    decimalHasBeenAdded = false;
    input = ui->labelInput;

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
    QPushButton *button = (QPushButton*)sender();

    if(input->text().length() == 1 && input->text()[0] == '0')
    {
        input->setText(input->text().replace(0, 1, button->text()));
    }
    else
    {
        input->setText(input->text().append(button->text()));
    }
    //input->setText(QString::number(
    //                                input->text().append(
    //                                button->text()
    //                                ).toDouble(), 'g', 15)
    //                         );
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

    if(!operatorUsedDirectlyBefore())
    {
        input->setText(input->text().append(" " + button->text() + " "));
    }
}

/* If the user releases the = button, then they want
 * the answer to their input to be calculated.
 * Emits input_is_ready signal to give Calculator
 * the input it needs to do its job.
 */
void MainWindow::on_buttonEquals_released()
{
    if(!operatorUsedDirectlyBefore())
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
}

void MainWindow::on_buttonRoot_released()
{
}
