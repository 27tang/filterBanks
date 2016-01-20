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

private:
    cv::Mat source;
    cv::Mat dest;

    Ui::MainWindow *ui;
    QImage MainWindow::convertOpenCVMatToQtQImage(cv::Mat mat);
};

#endif // MAINWINDOW_H
