#include "widget.h"
#include <QApplication>
#include <QSplashScreen>
#include <QtGui/QPixmap>
#include <QMutex>

void sleep(int ms){
   static QMutex mutex;
   static QMutexLocker locker(&mutex);
   mutex.tryLock(ms);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pixmap("/home/amerohful/ProgrammingProject/TicTacToe/course___/screen.png");
    QSplashScreen *screen = new QSplashScreen;
    screen->setPixmap(pixmap);
    screen->show();
    sleep(1000);
    Widget w;
    w.show();
    screen->finish(&w);

    return a.exec();
}
