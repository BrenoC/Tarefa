#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QtCore>

using namespace cv;
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Vision.openCamera();


    tmrTimer = new QTimer(this);
    connect(tmrTimer, SIGNAL(timeout() ), this, SLOT(processFrame() ));
    tmrTimer->start(20);  
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_maxHue_sliderMoved(int position)
{
    ui->lcd_highH->display(position);
    Vision.setHighH(position);
}

void MainWindow::on_minHue_sliderMoved(int position)
{
   ui->lcd_lowH->display(position);
   Vision.setLowH(position);
}


void MainWindow::on_maxSaturation_sliderMoved(int position)
{
    ui->lcd_highS->display(position);
    Vision.setHighS(position);
}


void MainWindow::on_minSaturation_sliderMoved(int position)
{
    ui->lcd_lowS->display(position);
    Vision.setLowS(position);
}

void MainWindow::on_maxValue_sliderMoved(int position)
{
    ui->lcd_highV->display(position);
    Vision.setHighV(position);
}

void MainWindow::on_minValue_sliderMoved(int position)
{
    ui->lcd_lowV->display(position);
    Vision.setLowV(position);
}

void MainWindow::processFrame() {
    Vision.updateFrame();
    Vision.treatment();
    QImage matProcessed((uchar*)Vision.getDst().data, Vision.getDst().cols, Vision.getDst().rows, Vision.getDst().step, QImage::Format_RGB888);
    ui->cam->setPixmap(QPixmap::fromImage(matProcessed) );

}


