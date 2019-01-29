#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	a.setApplicationName("Slogorub");
	a.setApplicationVersion("1.0");
	a.setOrganizationName("Unlimited Web Works");
    a.setWindowIcon(QIcon(":/main.ico"));

    MainWindow w;
    w.show();
    
    return a.exec();
}
