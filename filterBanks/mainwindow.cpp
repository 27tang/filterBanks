#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QtCore>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->levelSlider->setRange(0,49);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QImage MainWindow::convertOpenCVMatToQtQImage(cv::Mat mat) {
    if(mat.channels() == 1) {                                   // if 1 channel (grayscale or black and white) image
        return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);     // return QImage
    } else if(mat.channels() == 3) {                            // if 3 channel color image
        cv::cvtColor(mat, mat, CV_BGR2RGB);                     // flip colors
        return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);       // return QImage
    } else {
        qDebug() << " image was not 1 channel or 3 channel";
    }
    return QImage();

}

QImage MainWindow::convertOpenCVMatToQtQImage2(cv::Mat mat) {
    if(mat.channels() == 1) {                                   // if 1 channel (grayscale or black and white) image
        return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);     // return QImage
    } else if(mat.channels() == 3) {                            // if 3 channel color image
        //cv::cvtColor(mat, mat, CV_BGR2RGB);                     // flip colors
        return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);       // return QImage
    } else {
        qDebug() << " image was not 1 channel or 3 channel";
    }
    return QImage();

}

void MainWindow::on_openButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName();
    if(fileName == "") {
        //do something if its empty "file not chosen"
        return;
    }

    source = cv::imread(fileName.toStdString(),CV_LOAD_IMAGE_UNCHANGED);

    QImage qimgSource = convertOpenCVMatToQtQImage(source);


    ui->sourceLabel->setPixmap(QPixmap::fromImage(qimgSource));
    ui->destLabel->setPixmap(QPixmap::fromImage(qimgSource));


}

void MainWindow::on_gaussBlurButton_clicked()
{


    ui->levelSlider->setValue(1);

    QString lev = QString::number(ui->levelSlider->value());

    ui->sliderValueLabel->setText(lev);

    cv::GaussianBlur(source, dest, cv::Size(3,3), 0,0);
    QImage qimgDest = convertOpenCVMatToQtQImage2(dest);
    ui->destLabel->setPixmap(QPixmap::fromImage(qimgDest));
   // cv::imshow("window", dest);
}

void MainWindow::on_levelSlider_sliderMoved(int position)
{

}

void MainWindow::on_levelSlider_valueChanged(int value)
{
    value = 1+value*2;
    QString lev = QString::number(value);
    //QString lev = QString::number(ui->levelSlider->value());
    ui->sliderValueLabel->setText(lev);

    if(ui->actionGaussian_Blur->isChecked())
        cv::GaussianBlur(source, dest, cv::Size(value,value), 0,0);
    else if(ui->actionMedian_Filter->isChecked())
        cv::medianBlur(source, dest, value);
    else if(ui->actionBox_Filter->isChecked())
        cv::boxFilter(source,dest,-1,cv::Size(value,value));
    else if(ui->actionBilateral_Filter->isChecked()){
        value = value * 10;
        cv::bilateralFilter(source,dest,15  ,value, value);
    }
    else if(ui->actionCanny_Edge->isChecked())
        cv::Canny(source,dest,value, value);


    QImage qimgDest = convertOpenCVMatToQtQImage2(dest);
    ui->destLabel->setPixmap(QPixmap::fromImage(qimgDest));
    //cv::imshow("window", dest);


}

void MainWindow::on_commitChangesButton_clicked()
{
    source = dest;
    QImage qimgSource = convertOpenCVMatToQtQImage2(source);
    ui->sourceLabel->setPixmap(QPixmap::fromImage(qimgSource));
    ui->levelSlider->setValue(0);
}

void MainWindow::on_actionGaussian_Blur_triggered()
{
    uncheckAllCheckableFilters();
    ui->actionGaussian_Blur->setChecked(true);
    ui->commitChangesButton->setEnabled(true);
    ui->levelSlider->setEnabled(true);
}

void MainWindow::on_actionMedian_Filter_triggered()
{

    uncheckAllCheckableFilters();
    ui->actionMedian_Filter->setChecked(true);
    ui->commitChangesButton->setEnabled(true);
    ui->levelSlider->setEnabled(true);
}

void MainWindow::uncheckAllCheckableFilters()
{
    ui->actionMedian_Filter->setChecked(false);
    ui->actionGaussian_Blur->setChecked(false);
}

void MainWindow::on_actionBox_Filter_triggered()
{
    uncheckAllCheckableFilters();
    ui->actionBox_Filter->setChecked(true);
    ui->commitChangesButton->setEnabled(true);
    ui->levelSlider->setEnabled(true);
}

void MainWindow::on_actionBilateral_Filter_triggered()
{
    uncheckAllCheckableFilters();
    ui->actionBilateral_Filter->setChecked(true);
    ui->commitChangesButton->setEnabled(true);
    ui->levelSlider->setEnabled(true);
    /*cv::bilateralFilter(source,dest,15  ,80,80);
    QImage qimgDest = convertOpenCVMatToQtQImage2(dest);
    ui->destLabel->setPixmap(QPixmap::fromImage(qimgDest));*/
}

void MainWindow::on_actionCanny_Edge_triggered()
{
    uncheckAllCheckableFilters();
    ui->actionCanny_Edge->setChecked(true);
    ui->commitChangesButton->setEnabled(true);
    ui->levelSlider->setEnabled(true);
}
