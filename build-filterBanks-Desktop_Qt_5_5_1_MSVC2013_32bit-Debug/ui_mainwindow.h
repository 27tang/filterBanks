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
    QAction *actionNL_Means;
    QAction *actionFilter2D;
    QAction *actionErode;
    QAction *actionNormalized_Block_Filter;
    QAction *actionColor_Transfer;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *openButton;
    QSlider *levelSlider;
    QPushButton *commitChangesButton;
    QLabel *destLabel;
    QLabel *sourceLabel;
    QLabel *sliderValueLabel;
    QSlider *biSlider;
    QMenuBar *menuBar;
    QMenu *menuButtons;
    QMenu *menuFilters;
    QMenu *menuDenoising;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(794, 455);
        MainWindow->setStyleSheet(QLatin1String("QMainWindow {\n"
"	background-color: grey;\n"
"border-width: 7px;\n"
"    border-color: #1e1e1e;\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton\n"
"{\n"
"    color: #b1b1b1;\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #565656, stop: 0.1 #525252, stop: 0.5 #4e4e4e, stop: 0.9 #4a4a4a, stop: 1 #464646);\n"
"    border-width: 1px;\n"
"    border-color: #1e1e1e;\n"
"    border-style: solid;\n"
"    border-radius: 6;\n"
"    padding: 3px;\n"
"    font-size: 12px;\n"
"    padding-left: 5px;\n"
"    padding-right: 5px;\n"
"}\n"
"\n"
"QLabel {\n"
"background-color: #3d3d29;\n"
"color: #b1b1b1;\n"
"\n"
"\n"
"}\n"
""));
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
        actionNL_Means = new QAction(MainWindow);
        actionNL_Means->setObjectName(QStringLiteral("actionNL_Means"));
        actionNL_Means->setCheckable(true);
        actionNL_Means->setEnabled(true);
        actionFilter2D = new QAction(MainWindow);
        actionFilter2D->setObjectName(QStringLiteral("actionFilter2D"));
        actionFilter2D->setCheckable(true);
        actionErode = new QAction(MainWindow);
        actionErode->setObjectName(QStringLiteral("actionErode"));
        actionErode->setCheckable(true);
        actionNormalized_Block_Filter = new QAction(MainWindow);
        actionNormalized_Block_Filter->setObjectName(QStringLiteral("actionNormalized_Block_Filter"));
        actionNormalized_Block_Filter->setCheckable(true);
        actionNormalized_Block_Filter->setEnabled(false);
        actionColor_Transfer = new QAction(MainWindow);
        actionColor_Transfer->setObjectName(QStringLiteral("actionColor_Transfer"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        openButton = new QPushButton(centralWidget);
        openButton->setObjectName(QStringLiteral("openButton"));

        gridLayout->addWidget(openButton, 0, 0, 1, 1);

        levelSlider = new QSlider(centralWidget);
        levelSlider->setObjectName(QStringLiteral("levelSlider"));
        levelSlider->setEnabled(false);
        levelSlider->setOrientation(Qt::Vertical);

        gridLayout->addWidget(levelSlider, 2, 1, 1, 1);

        commitChangesButton = new QPushButton(centralWidget);
        commitChangesButton->setObjectName(QStringLiteral("commitChangesButton"));
        commitChangesButton->setEnabled(false);
        commitChangesButton->setFlat(false);

        gridLayout->addWidget(commitChangesButton, 0, 4, 1, 1);

        destLabel = new QLabel(centralWidget);
        destLabel->setObjectName(QStringLiteral("destLabel"));
        destLabel->setAutoFillBackground(false);

        gridLayout->addWidget(destLabel, 2, 4, 1, 1);

        sourceLabel = new QLabel(centralWidget);
        sourceLabel->setObjectName(QStringLiteral("sourceLabel"));
        sourceLabel->setAutoFillBackground(false);

        gridLayout->addWidget(sourceLabel, 2, 0, 1, 1);

        sliderValueLabel = new QLabel(centralWidget);
        sliderValueLabel->setObjectName(QStringLiteral("sliderValueLabel"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        sliderValueLabel->setFont(font);
        sliderValueLabel->setAutoFillBackground(false);

        gridLayout->addWidget(sliderValueLabel, 0, 1, 1, 1);

        biSlider = new QSlider(centralWidget);
        biSlider->setObjectName(QStringLiteral("biSlider"));
        biSlider->setOrientation(Qt::Vertical);

        gridLayout->addWidget(biSlider, 2, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 794, 21));
        menuBar->setStyleSheet(QLatin1String("QMenuBar\n"
" {\n"
"	background-color: grey;\n"
"	border-width: 7px;\n"
"    border-color: #1e1e1e;\n"
"color: white;\n"
"\n"
"\n"
"}\n"
"QMenuBar::item{\n"
"	background-color: transparent\n"
"\n"
"}\n"
"\n"
"QMenu {\n"
"	background-color: grey;\n"
"	border-width: 7px;\n"
"    border-color: #1e1e1e;\n"
"\n"
"}"));
        menuButtons = new QMenu(menuBar);
        menuButtons->setObjectName(QStringLiteral("menuButtons"));
        menuFilters = new QMenu(menuBar);
        menuFilters->setObjectName(QStringLiteral("menuFilters"));
        menuFilters->setEnabled(true);
        menuDenoising = new QMenu(menuBar);
        menuDenoising->setObjectName(QStringLiteral("menuDenoising"));
        menuDenoising->setEnabled(true);
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuButtons->menuAction());
        menuBar->addAction(menuFilters->menuAction());
        menuBar->addAction(menuDenoising->menuAction());
        menuFilters->addAction(actionGaussian_Blur);
        menuFilters->addAction(actionMedian_Filter);
        menuFilters->addAction(actionBox_Filter);
        menuFilters->addAction(actionBilateral_Filter);
        menuFilters->addAction(actionCanny_Edge);
        menuDenoising->addAction(actionNL_Means);
        menuDenoising->addAction(actionFilter2D);
        menuDenoising->addAction(actionErode);
        menuDenoising->addAction(actionNormalized_Block_Filter);
        menuDenoising->addAction(actionColor_Transfer);

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
        actionNL_Means->setText(QApplication::translate("MainWindow", "NL-Means", 0));
        actionFilter2D->setText(QApplication::translate("MainWindow", "Filter2D", 0));
        actionErode->setText(QApplication::translate("MainWindow", "Erode", 0));
        actionNormalized_Block_Filter->setText(QApplication::translate("MainWindow", "Normalized Block Filter", 0));
        actionColor_Transfer->setText(QApplication::translate("MainWindow", "Color Transfer", 0));
        openButton->setText(QApplication::translate("MainWindow", "Open Source Image", 0));
        commitChangesButton->setText(QApplication::translate("MainWindow", "Commit Changes", 0));
        destLabel->setText(QString());
        sourceLabel->setText(QString());
        sliderValueLabel->setText(QApplication::translate("MainWindow", "0", 0));
        menuButtons->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuFilters->setTitle(QApplication::translate("MainWindow", "Filters", 0));
        menuDenoising->setTitle(QApplication::translate("MainWindow", "Additional", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
