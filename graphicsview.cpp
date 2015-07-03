#include "graphicsview.h"

#include <QMouseEvent>
#include <QCoreApplication>

GraphicsView::GraphicsView(QGraphicsScene* scene, QWidget* parent)
  : QGraphicsView(scene, parent)
{
}

void GraphicsView::mouseReleaseEvent(QMouseEvent* event)
{
  if(event->button() == Qt::MidButton)
    QCoreApplication::quit();
}
