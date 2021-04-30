#include "mainwindow.h"
#include <QApplication>
#include<QSplashScreen>
#include<QTimer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen *splash=new QSplashScreen;
    splash->setPixmap(QPixmap(":/images/mathBoard.jpg"));
    splash->show();
    MainWindow w;
    QTimer::singleShot(4000,splash,SLOT(close()));
    QTimer::singleShot(4000,&w,SLOT(showFullScreen()));
    //w.show();
    return a.exec();
}
