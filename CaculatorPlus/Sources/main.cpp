
#include "caculatorplus.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CaculatorPlus w;
    w.show();
    return a.exec();
}
