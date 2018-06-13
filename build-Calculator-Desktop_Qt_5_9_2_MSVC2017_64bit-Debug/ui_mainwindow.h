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
    QPushButton *buttonNegate;
    QPushButton *buttonEquals;
    QPushButton *buttonPlus;
    QPushButton *buttonMinus;
    QPushButton *buttonTimes;
    QPushButton *buttonDivide;
    QPushButton *buttonPercent;
    QPushButton *buttonSquared;
    QPushButton *buttonBack;
    QLabel *labelOutput;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(410, 453);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(410, 453));
        MainWindow->setMaximumSize(QSize(410, 453));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        button0 = new QPushButton(centralWidget);
        button0->setObjectName(QStringLiteral("button0"));
        button0->setGeometry(QRect(110, 390, 91, 51));
        QFont font;
        font.setPointSize(16);
        button0->setFont(font);
        button2 = new QPushButton(centralWidget);
        button2->setObjectName(QStringLiteral("button2"));
        button2->setGeometry(QRect(110, 330, 91, 51));
        button2->setFont(font);
        button1 = new QPushButton(centralWidget);
        button1->setObjectName(QStringLiteral("button1"));
        button1->setGeometry(QRect(10, 330, 91, 51));
        button1->setFont(font);
        button3 = new QPushButton(centralWidget);
        button3->setObjectName(QStringLiteral("button3"));
        button3->setGeometry(QRect(210, 330, 91, 51));
        button3->setFont(font);
        buttonDecimalPoint = new QPushButton(centralWidget);
        buttonDecimalPoint->setObjectName(QStringLiteral("buttonDecimalPoint"));
        buttonDecimalPoint->setGeometry(QRect(210, 390, 91, 51));
        buttonDecimalPoint->setFont(font);
        button4 = new QPushButton(centralWidget);
        button4->setObjectName(QStringLiteral("button4"));
        button4->setGeometry(QRect(10, 270, 91, 51));
        button4->setFont(font);
        button5 = new QPushButton(centralWidget);
        button5->setObjectName(QStringLiteral("button5"));
        button5->setGeometry(QRect(110, 270, 91, 51));
        button5->setFont(font);
        button6 = new QPushButton(centralWidget);
        button6->setObjectName(QStringLiteral("button6"));
        button6->setGeometry(QRect(210, 270, 91, 51));
        button6->setFont(font);
        button7 = new QPushButton(centralWidget);
        button7->setObjectName(QStringLiteral("button7"));
        button7->setGeometry(QRect(10, 210, 91, 51));
        button7->setFont(font);
        button8 = new QPushButton(centralWidget);
        button8->setObjectName(QStringLiteral("button8"));
        button8->setGeometry(QRect(110, 210, 91, 51));
        button8->setFont(font);
        button9 = new QPushButton(centralWidget);
        button9->setObjectName(QStringLiteral("button9"));
        button9->setGeometry(QRect(210, 210, 91, 51));
        button9->setFont(font);
        buttonNegate = new QPushButton(centralWidget);
        buttonNegate->setObjectName(QStringLiteral("buttonNegate"));
        buttonNegate->setGeometry(QRect(10, 390, 91, 51));
        buttonNegate->setFont(font);
        buttonEquals = new QPushButton(centralWidget);
        buttonEquals->setObjectName(QStringLiteral("buttonEquals"));
        buttonEquals->setGeometry(QRect(310, 390, 91, 51));
        buttonEquals->setFont(font);
        buttonPlus = new QPushButton(centralWidget);
        buttonPlus->setObjectName(QStringLiteral("buttonPlus"));
        buttonPlus->setGeometry(QRect(310, 330, 91, 51));
        buttonPlus->setFont(font);
        buttonMinus = new QPushButton(centralWidget);
        buttonMinus->setObjectName(QStringLiteral("buttonMinus"));
        buttonMinus->setGeometry(QRect(310, 270, 91, 51));
        buttonMinus->setFont(font);
        buttonTimes = new QPushButton(centralWidget);
        buttonTimes->setObjectName(QStringLiteral("buttonTimes"));
        buttonTimes->setGeometry(QRect(310, 210, 91, 51));
        buttonTimes->setFont(font);
        buttonDivide = new QPushButton(centralWidget);
        buttonDivide->setObjectName(QStringLiteral("buttonDivide"));
        buttonDivide->setGeometry(QRect(310, 150, 91, 51));
        buttonDivide->setFont(font);
        buttonPercent = new QPushButton(centralWidget);
        buttonPercent->setObjectName(QStringLiteral("buttonPercent"));
        buttonPercent->setGeometry(QRect(10, 150, 91, 51));
        buttonPercent->setFont(font);
        buttonSquared = new QPushButton(centralWidget);
        buttonSquared->setObjectName(QStringLiteral("buttonSquared"));
        buttonSquared->setGeometry(QRect(110, 150, 91, 51));
        buttonSquared->setFont(font);
        buttonBack = new QPushButton(centralWidget);
        buttonBack->setObjectName(QStringLiteral("buttonBack"));
        buttonBack->setGeometry(QRect(210, 150, 91, 51));
        buttonBack->setFont(font);
        labelOutput = new QLabel(centralWidget);
        labelOutput->setObjectName(QStringLiteral("labelOutput"));
        labelOutput->setGeometry(QRect(14, 70, 381, 41));
        QFont font1;
        font1.setPointSize(28);
        labelOutput->setFont(font1);
        labelOutput->setLayoutDirection(Qt::LeftToRight);
        labelOutput->setStyleSheet(QLatin1String("QLabel {\n"
"	border: solid;\n"
"	border-color: rgb(0, 0, 0)\n"
"}"));
        labelOutput->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
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
        buttonNegate->setText(QApplication::translate("MainWindow", "+/-", Q_NULLPTR));
        buttonEquals->setText(QApplication::translate("MainWindow", "=", Q_NULLPTR));
        buttonPlus->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        buttonMinus->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        buttonTimes->setText(QApplication::translate("MainWindow", "x", Q_NULLPTR));
        buttonDivide->setText(QApplication::translate("MainWindow", "/", Q_NULLPTR));
        buttonPercent->setText(QApplication::translate("MainWindow", "%", Q_NULLPTR));
        buttonSquared->setText(QApplication::translate("MainWindow", "x^2", Q_NULLPTR));
        buttonBack->setText(QApplication::translate("MainWindow", "Del", Q_NULLPTR));
        labelOutput->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
