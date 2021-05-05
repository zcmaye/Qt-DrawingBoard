#include "mainwindow.h"
#include<QToolBar>
#include<QAction>
#include<QActionGroup>
#include<QColorDialog>


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    this->resize(640, 480);
    initToolBar();
    

    graphScene = new ShapeScene;
    graphView = new QGraphicsView(graphScene, this);
    graphView->setRenderHint(QPainter::Antialiasing);   // 反锯齿，让线条圆滑
    this->setCentralWidget(graphView);



}

MainWindow::~MainWindow()
{
}

void MainWindow::initToolBar()
{
    QToolBar* toolBar = addToolBar("绘图工具");
    QActionGroup* actionGroup = new QActionGroup(toolBar);

    auto penAction = toolBar->addAction(QIcon(":/images/drawPoint.png"),
        "画笔", this, &MainWindow::onPenAction);
    actionGroup->addAction(penAction);
    penAction->setCheckable(true);      //设置点击会有选中效果
    penAction->setChecked(true);        //设为默认选中



    auto lineAction = toolBar->addAction(QIcon("://images/drawLine.png"),
        "直线", this, &MainWindow::onLineAction);
    actionGroup->addAction(lineAction);
    lineAction->setCheckable(true);

    auto ellipseAction = toolBar->addAction(QIcon("://images/drawEllipse.png"), "椭圆",
        this, &MainWindow::onEllipseAction);
    actionGroup->addAction(ellipseAction);
    ellipseAction->setCheckable(true);

    auto rectAction = toolBar->addAction(QIcon("://images/drawRect.png"), "矩形",
        this, &MainWindow::onRectAction);
    actionGroup->addAction(rectAction);
    rectAction->setCheckable(true);

    auto triangleAction = toolBar->addAction(QIcon("://images/drawTriangle.png"), "三角形",
        this, &MainWindow::onTriangleAction);
    actionGroup->addAction(triangleAction);
    triangleAction->setCheckable(true);

    auto pentagonAction = toolBar->addAction(QIcon("://images/drawPoligon.png"), "五边形",
        this, &MainWindow::onPentagonAction);
    actionGroup->addAction(pentagonAction);
    pentagonAction->setCheckable(true);

    auto pentacleAction = toolBar->addAction(QIcon("://images/drawFillPentacle.png"), "五角星",
        this, &MainWindow::onPentacleAction);
    actionGroup->addAction(pentacleAction);
    pentacleAction->setCheckable(true);

    auto colorAction = toolBar->addAction(QIcon("://images/Color.png"), "颜色",
        this, &MainWindow::onColorAction);
    actionGroup->addAction(colorAction);
    colorAction->setCheckable(true);

    auto clearAction = toolBar->addAction(QIcon("://images/deleteZone.png"), "清空",
        this, &MainWindow::onClearAllAction);


}

void MainWindow::resizeEvent(QResizeEvent* ev)
{
    graphView->setSceneRect(0, 0, this->width(), this->height());
    graphScene->setSceneRect(0, 0, this->width() - 10, this->height() - 10);
    graphView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graphView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

void MainWindow::onPenAction()
{
    qDebug() << "openaction";
    graphScene->setShapeType(ShapeItem::St_Graffiti);
}

void MainWindow::onLineAction()
{
    qDebug() << "onLineAction";
    graphScene->setShapeType(ShapeItem::St_Line);
}

void MainWindow::onEllipseAction()
{
    qDebug() << "onEllipseAction";
    graphScene->setShapeType(ShapeItem::St_Ellipse);
}

void MainWindow::onRectAction()
{
    qDebug() << "onRectAction";
    graphScene->setShapeType(ShapeItem::St_Rect);
}

void MainWindow::onTriangleAction()
{
    graphScene->setShapeType(ShapeItem::St_Triangle);
}

void MainWindow::onPentagonAction()
{
    graphScene->setShapeType(ShapeItem::St_Pentagon);
}

void MainWindow::onPentacleAction()
{
    graphScene->setShapeType(ShapeItem::St_Pentacle);
}



void MainWindow::onColorAction()
{
    cout << "onRectAction";
    QColorDialog colorDialog(this);
    colorDialog.setCurrentColor(qRgb(123, 125, 126));
    colorDialog.setCustomColor(0, Qt::red);
    colorDialog.setCustomColor(1, Qt::green);
    colorDialog.setCustomColor(2, Qt::blue);
    //colorDialog.setOptions(QColorDialog::ShowAlphaChannel);   //显示alpha通道

    int res = colorDialog.exec();
    if (res == QDialog::Accepted)
    {
        QColor c = colorDialog.currentColor();
        graphScene->setToolColor(c);
    }
    else
    {
        cout << res;
    }
}

void MainWindow::onClearAllAction()
{
    graphScene->clear();
}



