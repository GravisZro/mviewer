#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QtWidgets>

class MainWindow : public QMainWindow
{
    Q_OBJECT
  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow(void);

    QSize size(void);


  protected:
    virtual void keyPressEvent(QKeyEvent* event);
//    virtual void resizeEvent(QResizeEvent* event);

  private:
    QGraphicsPixmapItem* m_pixmap;
    QSize m_sz;
    bool m_is_scaled;
};

#endif // MAINWINDOW_H
