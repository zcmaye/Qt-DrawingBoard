#include "shapescene.h"
#include<QGraphicsSceneMouseEvent>
#include<QList>
#include<QFileDialog>
#include<QPainter>

ShapeScene::ShapeScene(QObject *parent)
	: QGraphicsScene(parent)
	, m_curShapeItem(nullptr)
	,m_type(ShapeItem::St_Graffiti)
	,m_pen(Qt::transparent,2)
{
	m_curShapeItem = new ShapeGraffiti;
	m_pen.setColor(Qt::black);
	signalAndSlot();
}

ShapeScene::~ShapeScene()
{
}

void ShapeScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	//如果不是左键按下，直接退出即可
	if (event->button() != Qt::LeftButton)
		return;
	//通过工厂产生不同的形状实例
	m_curShapeItem = ShapeItemFactory::create(m_type);
	if (m_curShapeItem != nullptr)
	{
		m_curShapeItem->setStartPos(event->scenePos());
		this->addItem(m_curShapeItem);	//把当前图形放到Scene中
		m_curShapeItem->setPen(m_pen);
	}
}

void ShapeScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	if (m_curShapeItem != nullptr)
	{
		m_curShapeItem->setEndPos(event->scenePos());
		update();
	}
}

void ShapeScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
	if (m_curShapeItem && !m_curShapeItem->isValid())
	{
		this->removeItem(m_curShapeItem);
		m_curShapeItem = nullptr;
	}
}

void ShapeScene::keyPressEvent(QKeyEvent* ev)
{
	//获取Scene中所有图元
	QList<QGraphicsItem*> item_list =  this->items(Qt::AscendingOrder);
	
	if (ev->modifiers() == Qt::ControlModifier)
	{
	
		switch (ev->key())
		{
		case Qt::Key_Z:			//Ctrl+Z撤销
			if (!item_list.empty())
			{
				//把撤销的图元放在反撤销Stack中
				m_redoStack.append(item_list.last());
				//为了节约内存，如果反撤销Stack中的元素大于10个,则直接永久栈底元素
				if (m_redoStack.size() > 10)
				{
					delete m_redoStack.front();
					m_redoStack.pop_front();
				}

				//从Scene中移除元素，但是不会释放内存
				this->removeItem(item_list.last());				
			}
			break;
		case Qt::Key_Y:			//反撤销
			if (!m_redoStack.empty())
			{
				//获取栈顶元素，并放入Scene
				this->addItem(m_redoStack.top());
				m_redoStack.pop();
			}
			break;
		case Qt::Key_S:
			saveScene();
			break;
		default:
			break;
		}
	}
}

void ShapeScene::setShapeType(ShapeItem::ShapeType type)
{
	m_type = type;
}

void ShapeScene::setToolColor(const QColor& c)
{
	m_pen.setColor(c);

}

void ShapeScene::signalAndSlot()
{

}

void ShapeScene::saveScene()
{

	QString saveFileName = QFileDialog::getSaveFileName(nullptr, "选择保存路径", QDir::currentPath(),
		"image(*.jpg *.png *.bmp)");
	cout << saveFileName;
	QRectF rect = this->sceneRect();
	//rect = this->itemsBoundingRect();
	//创建QImage对象,大小为Scene的大小
	QImage img = QImage(rect.size().toSize(), QImage::Format_RGB32);
	img.fill(Qt::white);
	//画家和img建立关联，让画家在img上绘图
	QPainter painter(&img);
	//把scene中的内容通过画家绘制到img上
	this->render(&painter);
	//保存img
	img.save(saveFileName);
}
