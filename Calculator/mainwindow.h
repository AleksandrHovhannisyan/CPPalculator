#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QKeyEvent>

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
    QLabel *input;
    bool operatorAllowed;
    bool digitAllowed;
    bool openParenthAllowed;
    bool closingParenthAllowed;
    int numOpenParenths;
    int numClosingParenths;
    bool operatorUsedDirectlyBefore() const;

signals:
    void input_is_ready(QString input);

private slots:
    void on_digit_released();
    void on_buttonDecimalPoint_released();
    void on_buttonNegate_released();
    void on_binary_button_released();
    void on_buttonEquals_released();
    void on_buttonClear_released();
    void on_buttonRoot_released();
    void on_buttonOpenParenth_released();
    void on_buttonCloseParenth_released();
    void on_buttonXSquared_released();
    void on_buttonSqrt_released();
    void on_buttonBack_released();
};

#endif // MAINWINDOW_H
