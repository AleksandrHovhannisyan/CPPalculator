#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

// TODO create a signal named "inputIsReady"
// that is emitted when the = button is released
// and is connected to calculator.h's slot for
// handling parsing and all that


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    Ui::MainWindow* getUI() const { return ui; }
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool decimalHasBeenAdded;
    QLabel *input;

signals:
    void input_is_ready(QString input);

private slots:
    void on_digit_released();
    void on_buttonDecimalPoint_released();
    void on_unary_button_released();
    void on_buttonEquals_released();
};

#endif // MAINWINDOW_H
