#include "ShapeItem.h"
#include<QPainter>
#include<QLine>

ShapeGraffiti::ShapeGraffiti(QGraphicsItem* parent)
	:ShapeItem(parent)
{
	
}

void ShapeGraffiti::setStartPos(const QPointF& pos)
{
	m_path.moveTo(pos);
}

void ShapeGraffiti::setEndPos(const QPointF& pos)
{
	m_path.lineTo(pos);
}

QRectF ShapeGraffiti::boundingRect() const
{
	return m_path.boundingRect();
}

void ShapeGraffiti::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->setPen(this->pen());
	painter->drawPath(m_path);
}

/*
*@直线 
*/
ShapeLine::ShapeLine(QGraphicsItem* parent)
	:ShapeItem(parent)
{
	
}

void ShapeLine::setStartPos(const QPointF& pos)
{
	m_startPos = pos;
}
void ShapeLine::setEndPos(const QPointF& pos)
{
	m_path.clear();
	m_path.moveTo(m_startPos);
	m_path.lineTo(pos);
}

QRectF ShapeLine::boundingRect() const
{
	return m_path.boundingRect();
}

void ShapeLine::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->setPen(this->pen());
	painter->drawPath(m_path);
}

/*
*@矩形
*/
ShapeRect::ShapeRect(QGraphicsItem* parent)
	:ShapeItem(parent)
{
}

void ShapeRect::setStartPos(const QPointF& pos)
{
	m_startPos = pos;
}

void ShapeRect::setEndPos(const QPointF& pos)
{
	m_path.clear();
	m_path.addRect(QRectF(m_startPos, pos));
}

QRectF ShapeRect::boundingRect() const
{
	return m_path.boundingRect();
}

void ShapeRect::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->setPen(pen());
	painter->drawPath(m_path);
}

/*
*@椭圆
*/
ShapeEllipse::ShapeEllipse(QGraphicsItem* parent)
	:ShapeItem(parent)
{
}

void ShapeEllipse::setStartPos(const QPointF& pos)
{
	m_startPos = pos;
}

void ShapeEllipse::setEndPos(const QPointF& pos)
{
	m_path.clear();
	m_path.addEllipse(QRectF(m_startPos, pos));
}

QRectF ShapeEllipse::boundingRect() const
{
	return m_path.boundingRect();
}

void ShapeEllipse::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->setPen(pen());
	painter->drawPath(m_path);
}

/*
*@三角形
*/
ShapeTriangle::ShapeTriangle(QGraphicsItem* parent)
	:ShapeItem(parent)
{
}

void ShapeTriangle::setStartPos(const QPointF& pos)
{
	m_startPos = pos;
}

void ShapeTriangle::setEndPos(const QPointF& pos)
{
	m_path.clear();
	m_path.addRect(QRectF(m_startPos, pos));
}

QRectF ShapeTriangle::boundingRect() const
{
	return m_path.boundingRect();
}

void ShapeTriangle::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{

	QRectF rect = m_path.controlPointRect();
	QPointF points[3] =
	{
		rect.bottomLeft(),
		rect.bottomRight(),
		QPointF(rect.topLeft().x() + rect.width() / 2,rect.top())
	};
	painter->setPen(pen());
	painter->drawPolygon(points, 3);
}

/*
*@五边形
*/
ShapePentagon::ShapePentagon(QGraphicsItem* parent)
{
}

void ShapePentagon::setStartPos(const QPointF& pos)
{
	m_startPos = pos;
}

void ShapePentagon::setEndPos(const QPointF& pos)
{
	m_path.clear();
	m_path.addRect(QRectF(m_startPos,pos));
}

QRectF ShapePentagon::boundingRect() const
{
	//cout << m_path.boundingRect();
	return m_path.boundingRect();
}

void ShapePentagon::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->setPen(pen());
	QRectF rect = m_path.controlPointRect();
	cout << rect;
	//五个点，从最上面的点开始顺时针获取
	QPointF points[5] =
	{
		QPointF(rect.x() + rect.width() / 2,	
		rect.y() + 0),

		QPointF(rect.x() + rect.width(),
		rect.y() + rect.height() * 0.385),

		QPointF(rect.x() + rect.width()*(1-0.2),
		rect.y() + rect.height()),

		QPointF(rect.x() + rect.width() * 0.2 ,
		rect.y() + rect.height()),

		QPointF(rect.x() + 0,
		rect.y() + rect.height()* 0.385)
	};

	painter->drawPolygon(points, 5);
}

/*
*@五角星
*/
ShapePentacle::ShapePentacle(QGraphicsItem* parent)
{
}

void ShapePentacle::setStartPos(const QPointF& pos)
{
	m_startPos = pos;
}

void ShapePentacle::setEndPos(const QPointF& pos)
{
	m_path.clear();
	m_path.addRect(QRectF(m_startPos, pos));
}

QRectF ShapePentacle::boundingRect() const
{
	return m_path.boundingRect();
}

void ShapePentacle::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->setPen(pen());
	QRectF rect = m_path.controlPointRect();
	//左上角的坐标
	int x = rect.x();
	int y = rect.y();
	int w = rect.width();
	int h = rect.height();
	QPointF points[11] = 
	{
		QPointF(x + w*0.5	,y + 0),
		QPointF(x + w*0.62	,y + h*0.385),
		QPointF(x + w		,y + h*0.4),
		QPointF(x + w*0.7	,y + h*0.625),	
		QPointF(x + w*0.8	,y + h),	//5
		QPointF(x + w*0.5	,y + h*0.775),
		QPointF(x + w*0.2	,y + h),
		QPointF(x + w*0.3	,y + h*0.625),
		QPointF(x + 0		,y + h*0.4),
		QPointF(x + w*0.385	,y + h*0.385),
	};
	painter->drawPolygon(points, 10);
		/*200 * 200 的矩形，从上面开始顺时针10个点的大概坐标，可以计算出比例
		   x     y
		1 w/2    0		->0.5			0
		2 124    77		->124/200=0.62  77/200=0.385 
		3  w     80		->w				0.4
		4 140    125	->0.7			0.625
		5 160     h		->0.8			h
		6 100    155	->0.5			0.775
		7 40     h		->0.2			h
		8 60     125	->0.3			0.625
		9 0      80		->0				0.4
	   10 77      77	->0.385			0.385
		*/
}
