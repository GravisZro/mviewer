#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
  try
  {
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();
  }
  catch(QString message)
  {
    qDebug(qPrintable(message));
  }

  return 0;
}
