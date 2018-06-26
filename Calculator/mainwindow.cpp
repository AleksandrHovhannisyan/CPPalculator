#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "operator.h"
#include "utilityFunctions.h"           // custom commonly used functions
#include <QDebug>                       // debug output
#include <QChar>
#include <QShortcut>                    // keyboard input
#include <QKeySequence>                 // keyboard input
#include <QThread>                      // for sleep delay when dividing by zero
#include <QApplication>                 // same as QThread


/* Constructor for MainWindow objects. Connects all button signals
 * to their appropriate private slots to handle user input and sets
 * up some basic member variables.
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Basic variable setups
    ui->setupUi(this);
    input = ui->labelInput;
    reset();

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
    connect(ui->buttonRoot, SIGNAL(released()),
            this, SLOT(on_binary_button_released()));
    connect(ui->buttonPow, SIGNAL(released()),
            this, SLOT(on_binary_button_released()));

    // Unary buttons
    connect(ui->buttonSqrt, SIGNAL(released()),
            this, SLOT(on_unaryButton_released()));
    connect(ui->buttonNegate, SIGNAL(released()),
            this, SLOT(on_unaryButton_released()));
    connect(ui->buttonXSquared, SIGNAL(released()),
            this, SLOT(on_unaryButton_released()));

    // Shortcuts for math input via keyboard
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
    QShortcut *shortcutEnter1 = new QShortcut(QKeySequence(Qt::Key_Return), this);
    QShortcut *shortcutEnter2 = new QShortcut(QKeySequence("Enter"), this);
    QShortcut *shortcutBackspace = new QShortcut(QKeySequence("Backspace"), this);
    QShortcut *shortcutClear = new QShortcut(QKeySequence("Delete"), this);
    QShortcut *shortcutRoot = new QShortcut(QKeySequence(Qt::Key_R), this);
    QShortcut *shortcutSqrt = new QShortcut(QKeySequence(Qt::Key_S), this);
    QShortcut *shortcutPow = new QShortcut(QKeySequence("SHIFT+6"), this);
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
    connect(shortcutEnter1, SIGNAL(activated()), ui->buttonEquals, SLOT(click()));
    connect(shortcutEnter2, SIGNAL(activated()), ui->buttonEquals, SLOT(click()));
    connect(shortcutBackspace, SIGNAL(activated()), ui->buttonBack, SLOT(click()));
    connect(shortcutClear, SIGNAL(activated()), ui->buttonClear, SLOT(click()));
    connect(shortcutRoot, SIGNAL(activated()), ui->buttonRoot, SLOT(click()));
    connect(shortcutSqrt, SIGNAL(activated()), ui->buttonSqrt, SLOT(click()));
    connect(shortcutPow, SIGNAL(activated()), ui->buttonPow, SLOT(click()));
}

MainWindow::~MainWindow()
{
    delete input;
    delete ui;
}

/* Used by other functions to check if an operator was
 * applied directly before the current user's input token.
 */
bool MainWindow::operatorUsedDirectlyBefore() const
{
    return isOperator(input->text().at(input->text().length()-1));
}


/* Called when a user clicks any of the digit buttons (0-9) or
 * enters a digit from their keyboard (0-9). Appends the corresponding
 * digit to the input.
 */
void MainWindow::on_digit_released()
{
    State currentState = history.top();

    if(currentState.digitAllowed)
    {
        QPushButton *button = (QPushButton*)sender();

        history.push(State(true, true, true, false, true,
                                history.top().numOpenParenths,
                                history.top().numClosingParenths));

        // Initial input is just a 0, so check for that case
        if(input->text().length() == 1 && input->text()[0] == '0')
        {
            input->setText(input->text().replace(0, 1, button->text()));
        }
        // Otherwise, just append the digit
        else
        {
            input->setText(input->text().append(button->text()));
        }
    }
}

/* Called when a user clicks the '.' button or uses the keyboard
 * shortcut '.' Appends a decimal point to the last digit that was
 * entered.
 */
void MainWindow::on_buttonDecimalPoint_released()
{
    if(history.top().decimalAllowed)
    {
        input->setText(input->text() + ".");
        history.push(State(true, true, false, false, true,
                                history.top().numOpenParenths,
                                history.top().numClosingParenths));
    }
}

/* Called when a user clicks a unary button. The unary
 * buttons for this calculator are +/, sqrt, and x^2.
 */
void MainWindow::on_unaryButton_released()
{
    QChar op = QChar::QChar(((QPushButton*)sender())->text().at(0));
    State currentState = history.top();

    // ---------------------- NEGATION OPERATOR ----------------------
    if(op == 0x00b1)
    {
        // Check if there are currently any operators in input
        bool inputHasOperators = false;

        // If so, get the index of the last one (hence reverse traversal)
        int indexOfLastOperator = -1;

        for(int i = input->text().length() - 1; i >= 0; i--)
        {
            // Check that what we found is in fact an operator and not a negation
            // (That's only ambiguous for subtraction)
            QChar c = input->text().at(i);
            if((isOperator(c) || c == 'r' || c == 't' || c == '(') &&
                    !(tokenIsNegation(c, input->text(), i)))
            {
                inputHasOperators = true;
                indexOfLastOperator = i;
                break;
            }
        }

        // If user entered an operator and then tried to negate something
        if(indexOfLastOperator == input->text().length()-1){ return; }

        // Case 1: Input contains operators
        if(inputHasOperators)
        {
            QChar lastOperator = input->text().at(indexOfLastOperator);

            // If the number in question is already negative, undo it
            if(input->text().at(indexOfLastOperator+1) == '-')
            {
                input->setText(input->text().replace(indexOfLastOperator+1, 1, ""));
            }

            // If not, let's check what kind of operator came before it
            else
            {
                // If it was a plus, change that to a minus
                if(lastOperator == '+')
                {
                    input->setText(input->text().replace(indexOfLastOperator, 1, SUB));
                }
                // If it was a minus, change that to a plus
                else if(lastOperator == '-')
                {
                    input->setText(input->text().replace(indexOfLastOperator, 1, ADD));
                }
                // Otherwise, just negate the last number
                else
                {
                    input->setText(input->text().insert(indexOfLastOperator+1, SUB));
                }
            }
        }

        // Case 2: No operators and already negative number
        else if(input->text().at(0) == '-')
        {
            input->setText(input->text().replace(0, 1, ""));
        }

        // Case 3: No operators and positive number
        else
        {
            input->setText(input->text().prepend(SUB));
        }
    }

    // ---------------------- SQUARE ROOT OPERATOR -----------------------
    else if(op == 0x221a)
    {
        if(input->text() == "0"){ input->setText(op); }
        else{ input->setText(input->text().append(op)); }
        history.push(State(true, false, true, true, false,
                    currentState.numOpenParenths,
                    currentState.numClosingParenths));
    }

    // // ---------------------- X SQUARED OPERATOR ----------------------
    else if(op == 'x')
    {
        input->setText(input->text().append("^2"));
        history.push(State(true, true, true, false, true,
                                history.top().numOpenParenths,
                                history.top().numClosingParenths));
    }
}

/* Called when a user clicks any binary operation's button
 * (+, -, *, /). Appends the corresponding operator to input.
 */
void MainWindow::on_binary_button_released()
{
    QPushButton *button = (QPushButton*)sender();
    State currentState = history.top();
    bool inputAltered = false;

    // This code handles negation in multiplication/division expressions via keyboard input
    if(tokenIsNegation(button->text().at(0), input->text(), input->text().length()))
    {
        input->setText(input->text().append(button->text()));
        inputAltered = true;
    }
    else if(button->text() == "-" && input->text() == "0")
    {
        input->setText("-");
        inputAltered = true;
    }
    // All other cases of operators, if one is allowed
    else if(currentState.operatorAllowed)
    {
        input->setText(input->text().append(button->text()));
        inputAltered = true;
    }

    // To avoid repeating this code block, and this should only be inserted
    // if we actually altered the input, not on every call to this function
    if(inputAltered)
    {
        history.push(State(true, false, true, true, false,
                    currentState.numOpenParenths,
                    currentState.numClosingParenths));
    }
}

/* Called when a user clicks the '=' button or uses the keyboard
 * shortcut 'Enter'. Checks if the input is ready for evaluation.
 * If so, emits input_is_ready signal, effectively handing its
 * input string to the Calculator for processing.
 */
void MainWindow::on_buttonEquals_released()
{
    State currentState = history.top();
    if(!operatorUsedDirectlyBefore() &&
            currentState.numOpenParenths == currentState.numClosingParenths)
    {
        emit input_is_ready(input->text());
    }
}

/* Used to reset user input. Sets the input string to "0", clears its
 * history, and applies all initial input restrictions.
 */
void MainWindow::reset()
{
    input->setText("0");
    history.clear();
    history.push(State(true, true, true, true, false));
}

/* Called when a user clicks the 'Clear' button or uses the keyboard
 * shortcut 'Delete'. Resets the input. See MainWindow::reset().
 */
void MainWindow::on_buttonClear_released()
{
    reset();
}

/* Called when a user clicks the 'Back' button or uses the
 * keyboard shortcut 'Backspace'. Reverts the calculator to
 * its previous state of input. Reapplies all appropriate input
 * restrictions that existed prior to deletion of the last token.
 */
void MainWindow::on_buttonBack_released()
{
    // If the input is just a single digit, set it to 0
    if(input->text().length() == 1)
    {
        input->setText("0");
    }

    // Otherwise, if we have 2 or more non-"0" entries, remove last char
    else
    {
        QString text = input->text();
        input->setText(text.remove(text.length()-1, 1));
    }

    if(history.size() >= 2){ history.pop();}
}

/* Called when a user pushes the '(' button or uses the
 * keyboard shortcut SHIFT+9. Appends an opening parenthesis
 * to the input. Disables entry of closing parentheses
 * and operators directly afterwards.
 */
void MainWindow::on_buttonOpenParenth_released()
{
    if(history.top().openParenthAllowed)
    {
        if(input->text() == "0")
        {
            input->setText("(");
        }
        else if(!isdigit(input->text().at(input->text().length()-1).toLatin1()))
        {
            input->setText(input->text().append("("));
        }

        history.push(State(true, false, true, true, false,
                           history.top().numOpenParenths+1,
                           history.top().numClosingParenths));
    }
}

/* Called when a user pushes the ')' button or uses the
 * keyboard shortcut SHIFT+0. Appends a closing parenthesis
 * to the input. Disables entry of opening parentheses and
 * digits directly afterwards.
 */
void MainWindow::on_buttonCloseParenth_released()
{
    State currentState = history.top();
    if(currentState.closingParenthAllowed &&
            (currentState.numClosingParenths < currentState.numOpenParenths))
    {
        input->setText(input->text().append(")"));
        history.push(State(false, true, false, false, true,
                           history.top().numOpenParenths,
                           history.top().numClosingParenths+1));
    }
}

/* Receives signal from Calculator that output of calculation is ready */
void MainWindow::on_output_is_ready(QString output)
{
    // Reset state
    reset();

    // Update result on screen
    input->setText(output);

    // If an error was encountered
    if(output == "No division by zero" || output == "No negative radicands")
    {
        QApplication::processEvents();
        QThread::sleep(1);

        // And then reset again
        reset();
    }
}
