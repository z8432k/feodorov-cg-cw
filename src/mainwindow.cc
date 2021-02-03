#include <mainwindow.h>
#include <ui_mainwindow.h>
#include <QApplication>
#include <QPushButton>
#include <cmath>

MainWindow::MainWindow(QWidget *parent):
QMainWindow(parent),
ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene (this);
    ui->graphicsView->setScene(scene);
    sdvig=0;
    QBrush redBrush(Qt::red);
    QBrush blueBrush(Qt::blue);
    QPen blackpen(Qt::black);
    blackpen.setWidth(2);
    pol     << QPoint(100, 75) << QPoint(170, 75)
            << QPoint(170, 55) << QPoint(215, 100)
            << QPoint(170, 145)<< QPoint(170, 125)
            << QPoint(100, 125);
    polygon = scene->addPolygon(pol,blackpen,redBrush);
    srx=floor(((100*2+170*4+215)/7)+0.5) ;
    sry=floor(((75*2+55+145+100+125*2)/7)+0.5);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    QBrush redBrush(Qt::red);
    QPen blackpen(Qt::black);
    blackpen.setWidth(2);
    scene->clear();
    matrixxx.translate(srx+sdvig,sry);
    matrixxx.rotate(-5.0);
    matrixxx.translate(-srx-sdvig,-sry);
    pol =  matrixxx.map(pol);
    polygon = scene->addPolygon(pol,blackpen,redBrush);
    matrixxx.reset();
    //   ui->graphicsView->update();

}

void MainWindow::on_pushButton_clicked()
{
    QBrush redBrush(Qt::blue);
    QPen blackpen(Qt::black);
    blackpen.setWidth(2);
    scene->clear();
    matrixxx.translate(srx+sdvig,sry);
    matrixxx.rotate(5.0);
    matrixxx.translate(-srx-sdvig,-sry);
    pol =  matrixxx.map(pol);
    matrixxx.reset();
    polygon = scene->addPolygon(pol,blackpen,redBrush);
    //ui->graphicsView->update();
}

void MainWindow::on_pushButton_3_clicked()
{
    QBrush redBrush(Qt::blue);
    QPen blackpen(Qt::black);
    blackpen.setWidth(2);
    scene->clear();
    matrixxx.translate(srx,sry);
    matrixxx.translate(5,0);
    matrixxx.translate(-srx,-sry);
    pol =  matrixxx.map(pol);
    matrixxx.reset();
    polygon = scene->addPolygon(pol,blackpen,redBrush);
    ui->graphicsView->update();
    sdvig+=5;
}

void MainWindow::on_pushButton_4_clicked()
{
    QBrush redBrush(Qt::red);
    QPen blackpen(Qt::black);
    blackpen.setWidth(2);
    scene->clear();
    matrixxx.inverted();
    matrixxx.translate(srx,sry);
    matrixxx.translate(-5,0);
    matrixxx.translate(-srx,-sry);
    pol =  matrixxx.map(pol);
    matrixxx.reset();
    polygon = scene->addPolygon(pol,blackpen,redBrush);
    ui->graphicsView->update();
    sdvig-=5;
}
