#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    decimalHasBeenAdded = false;
    output = ui->labelOutput;

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

/* When a digit button is pressed, its text gets relayed to output label */
void MainWindow::on_digit_released()
{
    QPushButton *button = (QPushButton*)sender();
    output->setText(QString::number(
                                 output->text().append(
                                     button->text()
                                     ).toDouble(), 'g', 15)
                             );
}

/* When the decimal point button is released, add a decimal point to
 * output label if we haven't done so already (see decimalHasBeenAdded).
*/
void MainWindow::on_buttonDecimalPoint_released()
{
    if(!decimalHasBeenAdded)
    {
        output->setText(output->text() + ".");
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
        if(output->text().at(0) == '-')
        {
            output->setText(output->text().replace(0, 1, ""));
        }
        else
        {
            output->setText(output->text().prepend("-"));
        }
    }
    else if(button->text() == "%")
    {
        // TODO should only be applied to a number, so check if output contains anything but digits, ., or -
        double number = output->text().toDouble();
        number /= 100;
        output->setText(QString::number(number, 'g', 15));
    }
}
