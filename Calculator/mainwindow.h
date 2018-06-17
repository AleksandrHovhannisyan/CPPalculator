#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QKeyEvent>
#include <QStack>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    /* Used to keep track of the history of operations that the user
     * performed when entering input. Primarily used by backspace and
     * clear to undo previous user input and restore the calculator's
     * state to its previous input restrictions.
     */
    struct State
    {
        bool digitAllowed;
        bool operatorAllowed;
        bool openParenthAllowed;
        bool closingParenthAllowed;
        int numOpenParenths;
        int numClosingParenths;
        State(bool dig, bool op, bool oP, bool cP, int nO=0, int nC=0) :
            digitAllowed(dig), operatorAllowed(op),
            openParenthAllowed(oP), closingParenthAllowed(cP),
            numOpenParenths(nO), numClosingParenths(nC) {}
        State() {}
    };

public:
    explicit MainWindow(QWidget *parent = 0);
    Ui::MainWindow* getUI() const { return ui; }
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLabel *input;
    QStack<State> history;
    bool operatorUsedDirectlyBefore() const;
    void reset();

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
