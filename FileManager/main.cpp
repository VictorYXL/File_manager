#include <QApplication>
#include "filemanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FileManager w;
    w.show();
    
    return a.exec();
}
