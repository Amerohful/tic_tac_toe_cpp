#ifndef WIDGET_H
#define WIDGET_H

#include "game.h"
#include <QWidget>
#include <QSize>
#include <QtGui/QIcon>
#include <QtGui/QPixmap>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    Game *g;

    QPushButton *field1;
    QPushButton *field2;
    QPushButton *field3;
    QPushButton *field4;
    QPushButton *field5;
    QPushButton *field6;
    QPushButton *field7;
    QPushButton *field8;
    QPushButton *field9;
    QPushButton *restart;
    QPushButton *game_next;
    QLabel *text1;
    QLabel *text2;
    QLabel *gamer1;
    QLabel *gamer2;
    QIcon setField();
    void checkWin();

private slots:
    void restartGame();
    void clearField();
    void field1Cliced();
    void field2Cliced();
    void field3Cliced();
    void field4Cliced();
    void field5Cliced();
    void field6Cliced();
    void field7Cliced();
    void field8Cliced();
    void field9Cliced();
};

#endif // WIDGET_H
