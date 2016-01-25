#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>

#include <opencv2/opencv.hpp>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_openButton_clicked();

    void on_gaussBlurButton_clicked();

    void on_levelSlider_sliderMoved(int position);

    void on_levelSlider_valueChanged(int value);

    void on_commitChangesButton_clicked();

    void on_actionGaussian_Blur_triggered();

    void on_actionMedian_Filter_triggered();

    void on_actionBox_Filter_triggered();

    void on_actionBilateral_Filter_triggered();

    void on_actionCanny_Edge_triggered();

private:
    cv::Mat source;
    cv::Mat dest;

    Ui::MainWindow *ui;
    void MainWindow::uncheckAllCheckableFilters();
    QImage MainWindow::convertOpenCVMatToQtQImage(cv::Mat mat);
    QImage MainWindow::convertOpenCVMatToQtQImage2(cv::Mat mat);
};

#endif // MAINWINDOW_H
