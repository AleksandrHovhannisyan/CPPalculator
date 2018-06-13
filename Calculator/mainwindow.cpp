#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    decimalHasBeenAdded = false;
    input = ui->labelInput;

    // Plug digit buttons' released() signals into MainWindow's on_digit_released() slot
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

    // Plug unary op buttons' released() signals into MainWindow's on_unary_button_released slot
    connect(ui->buttonNegate, SIGNAL(released()), this, SLOT(on_unary_button_released()));
    connect(ui->buttonPercent, SIGNAL(released()), this, SLOT(on_unary_button_released()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* When a digit button is pressed, its text gets relayed to input label */
void MainWindow::on_digit_released()
{
    QPushButton *button = (QPushButton*)sender();
    input->setText(QString::number(
                                 input->text().append(
                                     button->text()
                                     ).toDouble(), 'g', 15)
                             );
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
    else if(button->text() == "%")
    {
        // TODO should only be applied to a number, so check if input contains anything but digits, ., or -
        double number = input->text().toDouble();
        number /= 100;
        input->setText(QString::number(number, 'g', 15));
    }
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
