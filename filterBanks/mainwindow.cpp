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
    if(mat.channels() == 1) {
        return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);
    } else if(mat.channels() == 3) {
        cv::cvtColor(mat, mat, CV_BGR2RGB);
        return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
    } else {
        qDebug() << "it not right the channels 1 or 3, none even got";
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

    source = cv::imread(fileName.toStdString());

    QImage qimgSource = convertOpenCVMatToQtQImage(source);


    ui->sourceLabel->setPixmap(QPixmap::fromImage(qimgSource));

}

void MainWindow::on_gaussBlurButton_clicked()
{

    cv::GaussianBlur(source, dest, cv::Size(1,1), 0,0);
    ui->levelSlider->setValue(1);
    QString lev = QString::number(ui->levelSlider->value());
    ui->sliderValueLabel->setText(lev);

    QImage qimgDest = convertOpenCVMatToQtQImage(dest);
    ui->destLabel->setPixmap(QPixmap::fromImage(qimgDest));
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

    cv::GaussianBlur(source, dest, cv::Size(value,value), 0,0);

    QImage qimgDest = convertOpenCVMatToQtQImage(dest);
    ui->destLabel->setPixmap(QPixmap::fromImage(qimgDest));


}
