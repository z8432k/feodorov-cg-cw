#ifndef CG_CW_OBJECT_H
#define CG_CW_OBJECT_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsScene>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QPolygon pol;
    QMatrix matrixxx;
    int srx,sry, sdvig;
public slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsPolygonItem *polygon;

};

#endif //CG_CW_OBJECT_H
