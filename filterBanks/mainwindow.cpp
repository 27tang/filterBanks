#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QtCore>
#include <vector>

using namespace std;
using namespace cv;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->levelSlider->setRange(0,49);
    ui->biSlider->setRange(0,49);
    ui->biSlider->setVisible(false);
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

    fileName = QFileDialog::getOpenFileName();

    if(fileName == "") {
        //do something if its empty "file not chosen"
        return;
    }


    source = cv::imread(fileName.toStdString(),CV_LOAD_IMAGE_UNCHANGED);

    QImage qimgSource = convertOpenCVMatToQtQImage(source);


    ui->sourceLabel->setPixmap(QPixmap::fromImage(qimgSource));
  //  ui->destLabel->setPixmap(QPixmap::fromImage(qimgSource));
    ui->menuFilters->setEnabled(true);
    ui->menuDenoising->setEnabled(true);


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

void MainWindow::on_biSlider_valueChanged(int value)
{
    value = 1+value*2;
    value = value * 10;
    int biVal = ui->levelSlider->value()*10;
    cv::bilateralFilter(source,dest,15,biVal, value);
    QImage qimgDest = convertOpenCVMatToQtQImage2(dest);
    ui->destLabel->setPixmap(QPixmap::fromImage(qimgDest));

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
        cv::bilateralFilter(source,dest,15,value, ui->biSlider->value());
    }
   // else if(ui->actionNL_Means->isChecked())
    else if(ui->actionErode->isChecked()){
        cv::Mat element = getStructuringElement(cv::MORPH_CROSS,
                      cv::Size(2 * value + 1, 2 * value + 1),
                      cv::Point(value, value) );

        cv::erode(source,dest,element);
        //cv::dilate(source,dest,element);
        //cv::blur(source,dest,cv::Size(value, value) );
        //cv:imshow("stuff", dest);
    }
    else if(ui->actionCanny_Edge->isChecked())
        cv::Canny(source,dest,value, value);
    else if(ui->actionFilter2D->isChecked())
    {
        cv::Mat kernel;
        cv::Point anchor;
        double delta;
        int ddepth;
        int kernel_size;

        anchor = cv::Point( -1, -1 );
          delta = 0;
          ddepth = -1;
          kernel_size = value;
          kernel = cv::Mat::ones( kernel_size, kernel_size, CV_32F )/ (float)(kernel_size*kernel_size);

          /// Apply filter
          cv::filter2D(source, dest, ddepth , kernel, anchor, delta, cv::BORDER_DEFAULT );

    } else if(ui->actionNormalized_Block_Filter->isChecked())
    {
        std::vector<cv::Mat> svec;
        svec.push_back(source);
        cv::denoise_TVL1(svec, dest,3,30);


    }


    QImage qimgDest = convertOpenCVMatToQtQImage2(dest);
    ui->destLabel->setPixmap(QPixmap::fromImage(qimgDest));
    //cv::imshow("window", dest);


}

void MainWindow::on_commitChangesButton_clicked()
{
    source = dest;
    QImage qimgSource = convertOpenCVMatToQtQImage2(source);
    ui->sourceLabel->setPixmap(QPixmap::fromImage(qimgSource));
    //ui->levelSlider->setValue(0);
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
    ui->levelSlider->
            setEnabled(true);
}

void MainWindow::uncheckAllCheckableFilters()
{
    ui->actionMedian_Filter->setChecked(false);
    ui->actionGaussian_Blur->setChecked(false);
    ui->actionBilateral_Filter->setChecked(false);
    ui->actionCanny_Edge->setChecked(false);
    ui->actionBox_Filter->setChecked(false);
    ui->actionNL_Means->setChecked(false);
    ui->biSlider->setVisible(false);
    ui->actionErode->setChecked(false);
    ui->actionFilter2D->setChecked(false);
    ui->actionNormalized_Block_Filter->setChecked(false);
    ui->levelSlider->setValue(0);
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
    ui->levelSlider->setValue(0);
    ui->biSlider->setValue(0);
    uncheckAllCheckableFilters();
    ui->actionBilateral_Filter->setChecked(true);
    ui->commitChangesButton->setEnabled(true);
    ui->levelSlider->setEnabled(true);
    ui->biSlider->setVisible(true);
    /*cv::bilateralFilter(source,dest,15,80,80);
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

void MainWindow::on_actionNL_Means_triggered()
{
    uncheckAllCheckableFilters();
    ui->actionNL_Means->setChecked(true);
    ui->commitChangesButton->setEnabled(true);
    cv::fastNlMeansDenoisingColored(source,dest,20,10,7,21);

    QImage qimgDest = convertOpenCVMatToQtQImage2(dest);
    ui->destLabel->setPixmap(QPixmap::fromImage(qimgDest));

    //cv::imshow("stuff", dest);
    ui->levelSlider->setEnabled(false);
}



void MainWindow::on_actionFilter2D_triggered()
{
      cv::Mat kernel;
      cv::Point anchor;
      double delta;
      int ddepth;
      int kernel_size;

      anchor = cv::Point( -1, -1 );
        delta = 0;
        ddepth = -1;
        kernel_size = 3;
        kernel = cv::Mat::ones( kernel_size, kernel_size, CV_32F )/ (float)(kernel_size*kernel_size);

        /// Apply filter
        cv::filter2D(source, dest, ddepth , kernel, anchor, delta, cv::BORDER_DEFAULT );
    uncheckAllCheckableFilters();
    ui->actionFilter2D->setChecked(true);
    ui->commitChangesButton->setEnabled(true);


    QImage qimgDest = convertOpenCVMatToQtQImage2(dest);
    ui->destLabel->setPixmap(QPixmap::fromImage(qimgDest));

    //cv::imshow("stuff", dest);
    ui->levelSlider->setEnabled(true);
}

void MainWindow::on_actionErode_triggered()
{
    uncheckAllCheckableFilters();
    ui->actionErode->setChecked(true);
    ui->commitChangesButton->setEnabled(true);
    ui->levelSlider->setEnabled(true);

}

void MainWindow::on_actionNormalized_Block_Filter_triggered()
{
    uncheckAllCheckableFilters();
    ui->actionNormalized_Block_Filter->setChecked(true);
    ui->commitChangesButton->setEnabled(true);
    ui->levelSlider->setEnabled(false);

   // std::vector<cv::Mat> svec;
   // svec.push_back(cv::imread(fileName.toStdString(),IMREAD_));

    //cv::denoise_TVL1(svec, dest);
    //cv::fastNlMeansDenoisingColoredMulti(source,dest,11);
    //QImage qimgDest = convertOpenCVMatToQtQImage2(dest);
    //ui->destLabel->setPixmap(QPixmap::fromImage(qimgDest));
}

void MainWindow::on_actionColor_Transfer_triggered()
{
    Mat src = cv::imread(fileName.toStdString(),CV_LOAD_IMAGE_UNCHANGED);

    fileName = QFileDialog::getOpenFileName();

    if(fileName == "") {
        //do something if its empty "file not chosen"
        return;
    }

      Mat tar = cv::imread(fileName.toStdString(),CV_LOAD_IMAGE_UNCHANGED);

     // imshow("dsfs", src);
      Mat src_lab, tar_lab;
      cvtColor(src, src_lab, COLOR_BGR2Lab );
      cvtColor(tar, tar_lab, COLOR_BGR2Lab );
      src_lab.convertTo(src_lab,CV_32FC1);
      tar_lab.convertTo(tar_lab,CV_32FC1);


      //Find mean
      Mat mean_src, mean_tar, stdd_src, stdd_tar;
      meanStdDev(src_lab, mean_src, stdd_src);
      meanStdDev(tar_lab, mean_tar, stdd_src);
         // Split
      vector<Mat> src_chan, tar_chan;
      split( src_lab, src_chan );
      split( tar_lab, tar_chan );

      for( int i = 0; i < 3; i++ ) {
             tar_chan[i] -= mean_tar.at<double>(i);
             tar_chan[i] *= (stdd_src.at<double>(i) / stdd_src. at<double>(i));
             tar_chan[i] += mean_src.at<double>(i);
      }
         //Merge the channels, convert to CV_8UC1 each channel and convert to BGR
         Mat output;
         merge(tar_chan, output);
         output.convertTo(output,CV_8UC1);
         cvtColor(output, output, COLOR_Lab2BGR );


         QImage qimgDest = convertOpenCVMatToQtQImage(output);
         ui->destLabel->setPixmap(QPixmap::fromImage(qimgDest));
         ui->commitChangesButton->setEnabled(true);
}
