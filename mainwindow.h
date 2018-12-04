#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vision.h"
#include <QImage>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    vision Vision;
    QImage matProcessed;
    QTimer* tmrTimer;

private slots:

    void on_maxHue_sliderMoved(int position);

    void on_minHue_sliderMoved(int position);

    void on_maxSaturation_sliderMoved(int position);

    void on_minSaturation_sliderMoved(int position);

    void on_maxValue_sliderMoved(int position);

    void on_minValue_sliderMoved(int position);

public slots:
    void processFrame();

};

#endif // MAINWINDOW_H
