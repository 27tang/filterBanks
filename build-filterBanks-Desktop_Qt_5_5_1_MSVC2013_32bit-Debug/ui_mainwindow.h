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
    QAction *actionGaussian_Blur;
    QAction *actionMedian_Filter;
    QAction *actionBox_Filter;
    QAction *actionBilateral_Filter;
    QAction *actionCanny_Edge;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *sliderValueLabel;
    QLabel *sourceLabel;
    QPushButton *commitChangesButton;
    QSlider *levelSlider;
    QLabel *destLabel;
    QPushButton *openButton;
    QMenuBar *menuBar;
    QMenu *menuButtons;
    QMenu *menuFilters;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(794, 455);
        actionGaussian_Blur = new QAction(MainWindow);
        actionGaussian_Blur->setObjectName(QStringLiteral("actionGaussian_Blur"));
        actionGaussian_Blur->setCheckable(true);
        actionMedian_Filter = new QAction(MainWindow);
        actionMedian_Filter->setObjectName(QStringLiteral("actionMedian_Filter"));
        actionMedian_Filter->setCheckable(true);
        actionBox_Filter = new QAction(MainWindow);
        actionBox_Filter->setObjectName(QStringLiteral("actionBox_Filter"));
        actionBox_Filter->setCheckable(true);
        actionBilateral_Filter = new QAction(MainWindow);
        actionBilateral_Filter->setObjectName(QStringLiteral("actionBilateral_Filter"));
        actionBilateral_Filter->setCheckable(true);
        actionCanny_Edge = new QAction(MainWindow);
        actionCanny_Edge->setObjectName(QStringLiteral("actionCanny_Edge"));
        actionCanny_Edge->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        sliderValueLabel = new QLabel(centralWidget);
        sliderValueLabel->setObjectName(QStringLiteral("sliderValueLabel"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        sliderValueLabel->setFont(font);
        sliderValueLabel->setAutoFillBackground(true);

        gridLayout->addWidget(sliderValueLabel, 0, 1, 1, 1);

        sourceLabel = new QLabel(centralWidget);
        sourceLabel->setObjectName(QStringLiteral("sourceLabel"));
        sourceLabel->setAutoFillBackground(true);

        gridLayout->addWidget(sourceLabel, 2, 0, 1, 1);

        commitChangesButton = new QPushButton(centralWidget);
        commitChangesButton->setObjectName(QStringLiteral("commitChangesButton"));
        commitChangesButton->setEnabled(false);
        commitChangesButton->setFlat(false);

        gridLayout->addWidget(commitChangesButton, 0, 3, 1, 1);

        levelSlider = new QSlider(centralWidget);
        levelSlider->setObjectName(QStringLiteral("levelSlider"));
        levelSlider->setEnabled(false);
        levelSlider->setOrientation(Qt::Vertical);

        gridLayout->addWidget(levelSlider, 2, 1, 1, 1);

        destLabel = new QLabel(centralWidget);
        destLabel->setObjectName(QStringLiteral("destLabel"));
        destLabel->setAutoFillBackground(true);

        gridLayout->addWidget(destLabel, 2, 3, 1, 1);

        openButton = new QPushButton(centralWidget);
        openButton->setObjectName(QStringLiteral("openButton"));

        gridLayout->addWidget(openButton, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 794, 21));
        menuButtons = new QMenu(menuBar);
        menuButtons->setObjectName(QStringLiteral("menuButtons"));
        menuFilters = new QMenu(menuBar);
        menuFilters->setObjectName(QStringLiteral("menuFilters"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuButtons->menuAction());
        menuBar->addAction(menuFilters->menuAction());
        menuFilters->addAction(actionGaussian_Blur);
        menuFilters->addAction(actionMedian_Filter);
        menuFilters->addAction(actionBox_Filter);
        menuFilters->addAction(actionBilateral_Filter);
        menuFilters->addAction(actionCanny_Edge);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionGaussian_Blur->setText(QApplication::translate("MainWindow", "Gaussian Blur", 0));
        actionMedian_Filter->setText(QApplication::translate("MainWindow", "Median Filter", 0));
        actionBox_Filter->setText(QApplication::translate("MainWindow", "Box Filter", 0));
        actionBilateral_Filter->setText(QApplication::translate("MainWindow", "Bilateral Filter", 0));
        actionCanny_Edge->setText(QApplication::translate("MainWindow", "Canny Edge", 0));
        sliderValueLabel->setText(QApplication::translate("MainWindow", "0", 0));
        sourceLabel->setText(QString());
        commitChangesButton->setText(QApplication::translate("MainWindow", "Commit Changes", 0));
        destLabel->setText(QString());
        openButton->setText(QApplication::translate("MainWindow", "Open Source Image", 0));
        menuButtons->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuFilters->setTitle(QApplication::translate("MainWindow", "Filters", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
