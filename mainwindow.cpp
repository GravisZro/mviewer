#include "mainwindow.h"

#include "graphicsview.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent),
    m_pixmap(nullptr),
    m_is_scaled(false)
{
  GraphicsView* view = new GraphicsView(new QGraphicsScene());
  QString filename;
  setWindowTitle("MViewer");


  if(QCoreApplication::arguments().size() != 2)
    throw(QString("Usage: %1 <filename>").arg(QCoreApplication::applicationName()));

  filename = QCoreApplication::arguments().at(1);
  if(!QFile::exists(filename))
    throw(QString("Error: bad filename"));

  QPixmap pix(filename);
  m_pixmap = view->scene()->addPixmap(pix);

  setCentralWidget(view);
  //resize(size());
  setFixedSize(size());

  QRect geometry = QApplication::desktop()->availableGeometry();

  move((geometry.width () - width ()) / 2,
       (geometry.height() - height()) / 2);

  if(m_is_scaled)
  {
    float w_scale = geometry.width();
          w_scale /= pix.width();
    float h_scale = geometry.height();
          h_scale /= pix.height();

    if(w_scale < 1.0 || h_scale < 1.0)
      m_pixmap->setScale(w_scale < h_scale ? w_scale : h_scale);
  }

#if 0
  QMessageBox(QMessageBox::Information,
              QString("info"),
              QString("desktop: %1 x %2\nimage: %3 x %4\nsize: %5 x %6\nposition: %7 x %8")
                .arg(desktop->width ())
                .arg(desktop->height())
                .arg(m_pixmap->pixmap().width())
                .arg(m_pixmap->pixmap().height())
                .arg(width())
                .arg(height())
                .arg((desktop->width () - width ()) / 2)
                .arg((desktop->height() - height()) / 2)
             ).exec();
#endif
}

MainWindow::~MainWindow()
{
}


QSize MainWindow::size(void)
{
  if(!m_sz.isValid())
  {
    QRect geometry = QApplication::desktop()->availableGeometry();
    m_sz = m_pixmap->pixmap().size() + QSize(2, 2);

    if(m_sz.width () > geometry.width () ||
       m_sz.height() > geometry.height())
    {
      m_sz.scale(geometry.size(), Qt::KeepAspectRatio);
      m_is_scaled = true;
    }
  }

  return m_sz;
}


void MainWindow::keyPressEvent(QKeyEvent* event)
{
  switch(event->key())
  {
    case Qt::Key_Escape:
    case Qt::Key_Q:
      qApp->quit();

    default:
      QMainWindow::keyPressEvent(event);
  }
}
