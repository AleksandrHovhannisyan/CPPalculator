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
        bool decimalAllowed;
        int numOpenParenths;
        int numClosingParenths;

        State(bool dig, bool op, bool dec,
              bool openP, bool closeP,
              int numOpenP=0, int numCloseP=0) :
            digitAllowed(dig), operatorAllowed(op),
            openParenthAllowed(openP), closingParenthAllowed(closeP),
            decimalAllowed(dec), numOpenParenths(numOpenP),
            numClosingParenths(numCloseP) {}

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

public slots:
    void on_output_is_ready(QString output);

private slots:
    void on_digit_released();
    void on_buttonDecimalPoint_released();
    void on_unaryButton_released();
    void on_binary_button_released();
    void on_buttonEquals_released();
    void on_buttonClear_released();
    void on_buttonOpenParenth_released();
    void on_buttonCloseParenth_released();
    void on_buttonBack_released();
};

#endif // MAINWINDOW_H
