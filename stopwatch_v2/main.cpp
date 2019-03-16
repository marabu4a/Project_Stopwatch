#include "stopwatch.h"
#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    stopwatch w;
    w.show();
    qApp->setStyle(QStyleFactory::create("Fusion"));
    w.setWindowTitle("Секундомер");

    return a.exec();
}
