/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *gaussBlurButton;
    QLabel *sourceLabel;
    QLabel *destLabel;
    QPushButton *openButton;
    QSlider *levelSlider;
    QLabel *sliderValueLabel;
    QMenuBar *menuBar;
    QMenu *menuButtons;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(794, 455);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gaussBlurButton = new QPushButton(centralWidget);
        gaussBlurButton->setObjectName(QStringLiteral("gaussBlurButton"));

        gridLayout->addWidget(gaussBlurButton, 1, 0, 1, 1);

        sourceLabel = new QLabel(centralWidget);
        sourceLabel->setObjectName(QStringLiteral("sourceLabel"));
        sourceLabel->setAutoFillBackground(true);

        gridLayout->addWidget(sourceLabel, 2, 0, 1, 1);

        destLabel = new QLabel(centralWidget);
        destLabel->setObjectName(QStringLiteral("destLabel"));
        destLabel->setAutoFillBackground(true);

        gridLayout->addWidget(destLabel, 2, 2, 1, 1);

        openButton = new QPushButton(centralWidget);
        openButton->setObjectName(QStringLiteral("openButton"));

        gridLayout->addWidget(openButton, 0, 0, 1, 1);

        levelSlider = new QSlider(centralWidget);
        levelSlider->setObjectName(QStringLiteral("levelSlider"));
        levelSlider->setOrientation(Qt::Vertical);

        gridLayout->addWidget(levelSlider, 2, 1, 1, 1);

        sliderValueLabel = new QLabel(centralWidget);
        sliderValueLabel->setObjectName(QStringLiteral("sliderValueLabel"));

        gridLayout->addWidget(sliderValueLabel, 0, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 794, 21));
        menuButtons = new QMenu(menuBar);
        menuButtons->setObjectName(QStringLiteral("menuButtons"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuButtons->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        gaussBlurButton->setText(QApplication::translate("MainWindow", "Gaussian Blur", 0));
        sourceLabel->setText(QString());
        destLabel->setText(QString());
        openButton->setText(QApplication::translate("MainWindow", "Open Source Image", 0));
        sliderValueLabel->setText(QApplication::translate("MainWindow", "Slider Value: ", 0));
        menuButtons->setTitle(QApplication::translate("MainWindow", "Buttons", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
