#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>

class GraphicsView : public QGraphicsView
{
    Q_OBJECT
  public:
    explicit GraphicsView(QGraphicsScene* scene, QWidget* parent = nullptr);
    
  protected:
    void mouseReleaseEvent(QMouseEvent* event);
};

#endif // GRAPHICSVIEW_H
