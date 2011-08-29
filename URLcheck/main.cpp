#include <QtGui/QApplication>
#include "urlcheck.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    URLcheck w;
    w.show();
    return a.exec();
}
