#include<QGraphicsItem>
#include"Config.h"

class ShapeItem :public QAbstractGraphicsShapeItem
{
public:
    enum ShapeType  //所有形状类型
    {
        St_Shape,
        St_Line,        //直线
        St_Graffiti,    //涂鸦(画笔)
        St_Rect,        //矩形
        St_Ellipse,     //椭圆
        St_Triangle,    //三角形
        St_Pentagon,    //五边形
        St_Pentacle     //五角星
    };
    ShapeItem(QGraphicsItem* parent = nullptr):QAbstractGraphicsShapeItem(parent) {};
    virtual ~ShapeItem() {};
    //自定义的纯虚函数
    virtual void setStartPos(const QPointF& pos) = 0;        //设置开始点坐标
    virtual void setEndPos(const QPointF& pos) = 0;          //设置当前点坐标
    //基类的纯虚函数
    virtual QRectF boundingRect() const = 0;                 //返回形状的边界矩形
    virtual void paint(QPainter* painter, 
        const QStyleOptionGraphicsItem* option, 
        QWidget* widget) = 0;                                //形状的绘制方法   
    
    virtual inline bool isValid()
    {
        return !(this->boundingRect().width() == 0 && this->boundingRect().height() == 0);
    }
    inline int type() const override 
    { return ShapeType::St_Shape; }   //返回当前绘图形状的类型

};
/*
* @涂鸦
*/
class ShapeGraffiti :public ShapeItem
{
public:
    ShapeGraffiti(QGraphicsItem* parent = nullptr);
    void setStartPos(const QPointF& pos) override;
    void setEndPos(const QPointF& pos) override;
    QRectF boundingRect() const override;
    void paint(QPainter* painter,const QStyleOptionGraphicsItem* option,QWidget* widget);
    int type() const override { return ShapeItem::St_Graffiti; }
private:
    QPainterPath m_path;
};
/*
* @直线
*/
class ShapeLine :public ShapeItem
{
public:
    ShapeLine(QGraphicsItem* parent = nullptr);
    void setStartPos(const QPointF& pos) override;
    void setEndPos(const QPointF& pos) override;
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    int type() const override { return ShapeItem::St_Line; }

private:
    QPointF m_startPos;
    QPainterPath  m_path;
};
/*
* @矩形
*/
class ShapeRect :public ShapeItem
{
public:
    ShapeRect(QGraphicsItem* parent = nullptr);
    void setStartPos(const QPointF& pos) override;
    void setEndPos(const QPointF& pos) override;
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    int type() const override { return ShapeItem::St_Rect; }
protected:
    QPointF m_startPos;
    QPainterPath m_path;
};

/*
* @椭圆
*/
class ShapeEllipse :public ShapeItem
{
public:
    ShapeEllipse(QGraphicsItem* parent = nullptr);
    void setStartPos(const QPointF& pos) override;
    void setEndPos(const QPointF& pos) override;
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    int type() const override { return ShapeItem::St_Ellipse; }
private:
    QPointF m_startPos;
    QPainterPath m_path;
};

/*
* @三角形
*/
class ShapeTriangle :public ShapeItem
{
public:
    ShapeTriangle(QGraphicsItem* parent = nullptr);
    void setStartPos(const QPointF& pos) override;
    void setEndPos(const QPointF& pos) override;
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    int type() const override { return ShapeItem::St_Triangle; }
private:
    QPointF m_startPos;
    QPainterPath m_path;
};

/*
* @五边形
*/
class ShapePentagon :public ShapeItem
{
public:
    ShapePentagon(QGraphicsItem* parent = nullptr);
    void setStartPos(const QPointF& pos) override;
    void setEndPos(const QPointF& pos) override;
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    int type() const override { return ShapeItem::St_Triangle; }
private:
    QPointF m_startPos;
    QPainterPath m_path;
};

/*
* @五角星
*/
class ShapePentacle :public ShapeItem
{
public:
    ShapePentacle(QGraphicsItem* parent = nullptr);
    void setStartPos(const QPointF& pos) override;
    void setEndPos(const QPointF& pos) override;
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    int type() const override { return ShapeItem::St_Triangle; }
private:
    QPointF m_startPos;
    QPainterPath m_path;
};




class ShapeItemFactory
{
public:
    static ShapeItem* create(ShapeItem::ShapeType type)
    {
        switch (type)
        {
        case ShapeItem::St_Graffiti:
           return new ShapeGraffiti;
            break;
        case ShapeItem::St_Line:
            return new ShapeLine;
            break;
        case ShapeItem::St_Rect:
            return new ShapeRect;
            break;
        case ShapeItem::St_Ellipse:
            return new ShapeEllipse;
            break;
        case ShapeItem::St_Triangle:
            return new ShapeTriangle;
            break;
        case ShapeItem::St_Pentagon:
            return new ShapePentagon;
            break;
        case ShapeItem::St_Pentacle:
            return new ShapePentacle;
            break;
        default:
            return nullptr;
            break;
        }
    }
};