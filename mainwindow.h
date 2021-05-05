#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"Config.h"

#include <QMainWindow>

#include<QGraphicsView>
#include"shapescene.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    void initToolBar();         //初始化工具栏
    void resizeEvent(QResizeEvent *ev) override;
protected slots:
    void onPenAction();         //涂鸦
    void onLineAction();        //直线
    void onEllipseAction();     //椭圆
    void onRectAction();        //矩形
    void onTriangleAction();    //三角形
    void onPentagonAction();     //五边形
    void onPentacleAction();    //五角星
    void onColorAction();       //设置颜色
    void onClearAllAction();    //清空所有
    

private:
    QGraphicsView* graphView = nullptr;
    ShapeScene* graphScene = nullptr;
};
#endif // MAINWINDOW_H
