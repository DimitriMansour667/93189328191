#include "qtchess.h"
#include <QtWidgets/QApplication>
#include <QGridLayout>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qtchess w;
    w.show();
    return a.exec();
}
