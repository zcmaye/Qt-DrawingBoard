#pragma once

#include <QGraphicsScene>
#include"shapeItem.h"
#include<QMouseEvent>
#include<QStack>

class ShapeScene : public QGraphicsScene
{
	Q_OBJECT

public:
	ShapeScene(QObject *parent = nullptr);
	~ShapeScene();

	void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
	void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;

	void keyPressEvent(QKeyEvent* ev) override;

	void setShapeType(ShapeItem::ShapeType type);
	void setToolColor(const QColor& c);

	void signalAndSlot();

	void saveScene();
private:
	ShapeItem* m_curShapeItem = nullptr;
	ShapeItem::ShapeType m_type;
	QPen m_pen;

	QStack<QGraphicsItem*> m_redoStack;
};
