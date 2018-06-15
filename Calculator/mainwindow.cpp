#include "mainwindow.h"
#include "ui_mainwindow.h"
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

    // Connect unary operators' released() signals to on_unary_button_released
    connect(ui->buttonNegate, SIGNAL(released()),
            this, SLOT(on_unary_button_released()));
    connect(ui->buttonPercent, SIGNAL(released()),
            this, SLOT(on_unary_button_released()));

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
    if(!decimalHasBeenAdded)
    {
        input->setText(input->text() + ".");
        decimalHasBeenAdded = true;
    }
}

/* Unary operations are +/- and percent (%)
*/
void MainWindow::on_unary_button_released()
{
    QPushButton *button = (QPushButton*)sender();

    if(button->text() == "+/-")
    {
        if(input->text().at(0) == '-')
        {
            input->setText(input->text().replace(0, 1, ""));
        }
        else
        {
            input->setText(input->text().prepend("-"));
        }
    }
    // TODO get rid of % operation
    else if(button->text() == "%")
    {
        // TODO should only be applied to a number
        // check if input contains anything but digits/./-
        double number = input->text().toDouble();
        number /= 100;
        input->setText(QString::number(number, 'g', 15));
    }
}

/* If the user presses any binary operation's button, like
 * plus, minus, multiply, or divide, this slot will be called
 * to insert the appropriate operation into the current input.
 */
void MainWindow::on_binary_button_released()
{
    QPushButton *button = (QPushButton*)sender();

    // TODO ensure that we don't do two + operations in row, for example...

    input->setText(input->text().append(" " + button->text() + " "));
}

/* If the user releases the = button, then they want
 * the answer to their input to be calculated.
 * Emits input_is_ready signal to give Calculator
 * the input it needs to do its job.
 */
void MainWindow::on_buttonEquals_released()
{
    emit input_is_ready(input->text());
}

/* Pretty straightforward. Basically, if the user
 * presses and releases the clear button, then
 * set the input string to just 0.
 */
void MainWindow::on_buttonClear_released()
{
    input->setText("0");
}
