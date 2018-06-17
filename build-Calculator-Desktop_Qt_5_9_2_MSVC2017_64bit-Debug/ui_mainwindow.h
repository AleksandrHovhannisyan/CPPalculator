/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *button0;
    QPushButton *button2;
    QPushButton *button1;
    QPushButton *button3;
    QPushButton *buttonDecimalPoint;
    QPushButton *button4;
    QPushButton *button5;
    QPushButton *button6;
    QPushButton *button7;
    QPushButton *button8;
    QPushButton *button9;
    QPushButton *buttonEquals;
    QPushButton *buttonPlus;
    QPushButton *buttonMinus;
    QPushButton *buttonTimes;
    QPushButton *buttonDivide;
    QPushButton *buttonRoot;
    QPushButton *buttonSquared;
    QPushButton *buttonClear;
    QLabel *labelInput;
    QPushButton *buttonNegate;
    QPushButton *buttonOpenParenth;
    QPushButton *buttonCloseParenth;
    QPushButton *buttonXSquared;
    QPushButton *buttonSqrt;
    QPushButton *buttonBack;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(512, 436);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(1000, 1000));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        button0 = new QPushButton(centralWidget);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(button0);
        button0->setObjectName(QStringLiteral("button0"));
        button0->setGeometry(QRect(210, 370, 91, 51));
        QFont font;
        font.setPointSize(16);
        button0->setFont(font);
        button2 = new QPushButton(centralWidget);
        buttonGroup->addButton(button2);
        button2->setObjectName(QStringLiteral("button2"));
        button2->setGeometry(QRect(210, 310, 91, 51));
        button2->setFont(font);
        button1 = new QPushButton(centralWidget);
        buttonGroup->addButton(button1);
        button1->setObjectName(QStringLiteral("button1"));
        button1->setGeometry(QRect(110, 310, 91, 51));
        button1->setFont(font);
        button3 = new QPushButton(centralWidget);
        buttonGroup->addButton(button3);
        button3->setObjectName(QStringLiteral("button3"));
        button3->setGeometry(QRect(310, 310, 91, 51));
        button3->setFont(font);
        buttonDecimalPoint = new QPushButton(centralWidget);
        buttonGroup->addButton(buttonDecimalPoint);
        buttonDecimalPoint->setObjectName(QStringLiteral("buttonDecimalPoint"));
        buttonDecimalPoint->setGeometry(QRect(310, 370, 91, 51));
        buttonDecimalPoint->setFont(font);
        button4 = new QPushButton(centralWidget);
        buttonGroup->addButton(button4);
        button4->setObjectName(QStringLiteral("button4"));
        button4->setGeometry(QRect(110, 250, 91, 51));
        button4->setFont(font);
        button5 = new QPushButton(centralWidget);
        buttonGroup->addButton(button5);
        button5->setObjectName(QStringLiteral("button5"));
        button5->setGeometry(QRect(210, 250, 91, 51));
        button5->setFont(font);
        button6 = new QPushButton(centralWidget);
        buttonGroup->addButton(button6);
        button6->setObjectName(QStringLiteral("button6"));
        button6->setGeometry(QRect(310, 250, 91, 51));
        button6->setFont(font);
        button7 = new QPushButton(centralWidget);
        buttonGroup->addButton(button7);
        button7->setObjectName(QStringLiteral("button7"));
        button7->setGeometry(QRect(110, 190, 91, 51));
        button7->setFont(font);
        button8 = new QPushButton(centralWidget);
        buttonGroup->addButton(button8);
        button8->setObjectName(QStringLiteral("button8"));
        button8->setGeometry(QRect(210, 190, 91, 51));
        button8->setFont(font);
        button9 = new QPushButton(centralWidget);
        buttonGroup->addButton(button9);
        button9->setObjectName(QStringLiteral("button9"));
        button9->setGeometry(QRect(310, 190, 91, 51));
        button9->setFont(font);
        buttonEquals = new QPushButton(centralWidget);
        buttonGroup->addButton(buttonEquals);
        buttonEquals->setObjectName(QStringLiteral("buttonEquals"));
        buttonEquals->setGeometry(QRect(410, 370, 91, 51));
        buttonEquals->setFont(font);
        buttonPlus = new QPushButton(centralWidget);
        buttonGroup->addButton(buttonPlus);
        buttonPlus->setObjectName(QStringLiteral("buttonPlus"));
        buttonPlus->setGeometry(QRect(410, 310, 91, 51));
        buttonPlus->setFont(font);
        buttonMinus = new QPushButton(centralWidget);
        buttonGroup->addButton(buttonMinus);
        buttonMinus->setObjectName(QStringLiteral("buttonMinus"));
        buttonMinus->setGeometry(QRect(410, 250, 91, 51));
        buttonMinus->setFont(font);
        buttonTimes = new QPushButton(centralWidget);
        buttonGroup->addButton(buttonTimes);
        buttonTimes->setObjectName(QStringLiteral("buttonTimes"));
        buttonTimes->setGeometry(QRect(410, 190, 91, 51));
        buttonTimes->setFont(font);
        buttonDivide = new QPushButton(centralWidget);
        buttonGroup->addButton(buttonDivide);
        buttonDivide->setObjectName(QStringLiteral("buttonDivide"));
        buttonDivide->setGeometry(QRect(410, 130, 91, 51));
        buttonDivide->setFont(font);
        buttonRoot = new QPushButton(centralWidget);
        buttonGroup->addButton(buttonRoot);
        buttonRoot->setObjectName(QStringLiteral("buttonRoot"));
        buttonRoot->setGeometry(QRect(10, 130, 91, 51));
        buttonRoot->setFont(font);
        buttonSquared = new QPushButton(centralWidget);
        buttonGroup->addButton(buttonSquared);
        buttonSquared->setObjectName(QStringLiteral("buttonSquared"));
        buttonSquared->setGeometry(QRect(110, 130, 91, 51));
        buttonSquared->setFont(font);
        buttonClear = new QPushButton(centralWidget);
        buttonGroup->addButton(buttonClear);
        buttonClear->setObjectName(QStringLiteral("buttonClear"));
        buttonClear->setGeometry(QRect(310, 130, 91, 51));
        buttonClear->setFont(font);
        labelInput = new QLabel(centralWidget);
        labelInput->setObjectName(QStringLiteral("labelInput"));
        labelInput->setGeometry(QRect(10, 40, 491, 51));
        QFont font1;
        font1.setPointSize(28);
        labelInput->setFont(font1);
        labelInput->setLayoutDirection(Qt::LeftToRight);
        labelInput->setStyleSheet(QLatin1String("QLabel {\n"
"	border: solid;\n"
"	border-color: rgb(0, 0, 0)\n"
"}"));
        labelInput->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        buttonNegate = new QPushButton(centralWidget);
        buttonGroup->addButton(buttonNegate);
        buttonNegate->setObjectName(QStringLiteral("buttonNegate"));
        buttonNegate->setGeometry(QRect(10, 310, 91, 51));
        buttonNegate->setFont(font);
        buttonOpenParenth = new QPushButton(centralWidget);
        buttonGroup->addButton(buttonOpenParenth);
        buttonOpenParenth->setObjectName(QStringLiteral("buttonOpenParenth"));
        buttonOpenParenth->setGeometry(QRect(10, 370, 91, 51));
        buttonOpenParenth->setFont(font);
        buttonCloseParenth = new QPushButton(centralWidget);
        buttonGroup->addButton(buttonCloseParenth);
        buttonCloseParenth->setObjectName(QStringLiteral("buttonCloseParenth"));
        buttonCloseParenth->setGeometry(QRect(110, 370, 91, 51));
        buttonCloseParenth->setFont(font);
        buttonXSquared = new QPushButton(centralWidget);
        buttonGroup->addButton(buttonXSquared);
        buttonXSquared->setObjectName(QStringLiteral("buttonXSquared"));
        buttonXSquared->setGeometry(QRect(10, 250, 91, 51));
        buttonXSquared->setFont(font);
        buttonSqrt = new QPushButton(centralWidget);
        buttonGroup->addButton(buttonSqrt);
        buttonSqrt->setObjectName(QStringLiteral("buttonSqrt"));
        buttonSqrt->setGeometry(QRect(10, 190, 91, 51));
        buttonSqrt->setFont(font);
        buttonBack = new QPushButton(centralWidget);
        buttonGroup->addButton(buttonBack);
        buttonBack->setObjectName(QStringLiteral("buttonBack"));
        buttonBack->setGeometry(QRect(210, 130, 91, 51));
        buttonBack->setFont(font);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Calculator", Q_NULLPTR));
        button0->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        button2->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        button1->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        button3->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        buttonDecimalPoint->setText(QApplication::translate("MainWindow", ".", Q_NULLPTR));
        button4->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        button5->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        button6->setText(QApplication::translate("MainWindow", "6", Q_NULLPTR));
        button7->setText(QApplication::translate("MainWindow", "7", Q_NULLPTR));
        button8->setText(QApplication::translate("MainWindow", "8", Q_NULLPTR));
        button9->setText(QApplication::translate("MainWindow", "9", Q_NULLPTR));
        buttonEquals->setText(QApplication::translate("MainWindow", "=", Q_NULLPTR));
        buttonPlus->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        buttonMinus->setText(QApplication::translate("MainWindow", "\342\200\223", Q_NULLPTR));
        buttonTimes->setText(QApplication::translate("MainWindow", "\303\227", Q_NULLPTR));
        buttonDivide->setText(QApplication::translate("MainWindow", "\303\267", Q_NULLPTR));
        buttonRoot->setText(QApplication::translate("MainWindow", "rt", Q_NULLPTR));
        buttonSquared->setText(QApplication::translate("MainWindow", "^", Q_NULLPTR));
        buttonClear->setText(QApplication::translate("MainWindow", "Clear", Q_NULLPTR));
        labelInput->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        buttonNegate->setText(QApplication::translate("MainWindow", "\302\261", Q_NULLPTR));
        buttonOpenParenth->setText(QApplication::translate("MainWindow", "(", Q_NULLPTR));
        buttonCloseParenth->setText(QApplication::translate("MainWindow", ")", Q_NULLPTR));
        buttonXSquared->setText(QApplication::translate("MainWindow", "x^2", Q_NULLPTR));
        buttonSqrt->setText(QApplication::translate("MainWindow", "\342\210\232", Q_NULLPTR));
        buttonBack->setText(QApplication::translate("MainWindow", "Back", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
