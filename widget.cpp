#include "widget.h"

int first  = 0;
int second = 0;
bool win = false;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    g = new Game();


    text1 = new QLabel("first gamer:");
    text2 = new QLabel("second gamer:");

    gamer1 = new QLabel();
    gamer1->setText(QString::number(first));
    gamer2 = new QLabel();
    gamer2->setText(QString::number(second));

    field1 = new QPushButton();
    field1->setIcon(QIcon(":resourse/images/field.png"));
    field1->setStyleSheet("background-color: black");
    field1->setIconSize(QSize(50, 50));
    field2 = new QPushButton();
    field2->setIcon(QIcon(":resourse/images/field.png"));
    field2->setStyleSheet("background-color: black");
    field2->setIconSize(QSize(50, 50));
    field3 = new QPushButton();
    field3->setIcon(QIcon(":resourse/images/field.png"));
    field3->setStyleSheet("background-color: black");
    field3->setIconSize(QSize(50, 50));
    field4 = new QPushButton();
    field4->setIcon(QIcon(":resourse/images/field.png"));
    field4->setStyleSheet("background-color: black");
    field4->setIconSize(QSize(50, 50));
    field5 = new QPushButton();
    field5->setIcon(QIcon(":resourse/images/field.png"));
    field5->setStyleSheet("background-color: black");
    field5->setIconSize(QSize(50, 50));
    field6 = new QPushButton();
    field6->setIcon(QIcon(":resourse/images/field.png"));
    field6->setStyleSheet("background-color: black");
    field6->setIconSize(QSize(50, 50));
    field7 = new QPushButton();
    field7->setIcon(QIcon(":resourse/images/field.png"));
    field7->setStyleSheet("background-color: black");
    field7->setIconSize(QSize(50, 50));
    field8 = new QPushButton();
    field8->setIcon(QIcon(":resourse/images/field.png"));
    field8->setStyleSheet("background-color: black");
    field8->setIconSize(QSize(50, 50));
    field9 = new QPushButton();
    field9->setIcon(QIcon(":resourse/images/field.png"));
    field9->setStyleSheet("background-color: black");
    field9->setIconSize(QSize(50, 50));

    restart   = new QPushButton("restart");
    game_next = new QPushButton("next");

    QGridLayout *grid = new QGridLayout();
    setLayout(grid);
    setWindowTitle("Tic Tac Toe");

    grid->addWidget(field1, 0, 0);
    grid->addWidget(field2, 0, 1);
    grid->addWidget(field3, 0, 2);
    grid->addWidget(text1,  0, 3);
    grid->addWidget(gamer1, 0, 4);

    grid->addWidget(field4, 1, 0);
    grid->addWidget(field5, 1, 1);
    grid->addWidget(field6, 1, 2);
    grid->addWidget(text2,  1, 3);
    grid->addWidget(gamer2, 1, 4);

    grid->addWidget(field7, 2, 0);
    grid->addWidget(field8, 2, 1);
    grid->addWidget(field9, 2, 2);
    grid->addWidget(restart,   2, 3);
    grid->addWidget(game_next, 2, 4);

    connect(field1, SIGNAL(clicked(bool)), this, SLOT(field1Cliced()));
    connect(field2, SIGNAL(clicked(bool)), this, SLOT(field2Cliced()));
    connect(field3, SIGNAL(clicked(bool)), this, SLOT(field3Cliced()));
    connect(field4, SIGNAL(clicked(bool)), this, SLOT(field4Cliced()));
    connect(field5, SIGNAL(clicked(bool)), this, SLOT(field5Cliced()));
    connect(field6, SIGNAL(clicked(bool)), this, SLOT(field6Cliced()));
    connect(field7, SIGNAL(clicked(bool)), this, SLOT(field7Cliced()));
    connect(field8, SIGNAL(clicked(bool)), this, SLOT(field8Cliced()));
    connect(field9, SIGNAL(clicked(bool)), this, SLOT(field9Cliced()));

    connect(restart, SIGNAL(clicked(bool)), this, SLOT(restartGame()));
    connect(game_next, SIGNAL(clicked(bool)), this, SLOT(clearField()));
}

Widget::~Widget()
{

}

void Widget::restartGame() {
    clearField();
    first = 0;
    second = 0;
    gamer1->setText(QString::number(first));
    gamer2->setText(QString::number(second));
}

void Widget::clearField() {
    g->next_game();
    win = false;
    field1->setIcon(QIcon(":resourse/images/field.png"));
    field2->setIcon(QIcon(":resourse/images/field.png"));
    field3->setIcon(QIcon(":resourse/images/field.png"));
    field4->setIcon(QIcon(":resourse/images/field.png"));
    field5->setIcon(QIcon(":resourse/images/field.png"));
    field6->setIcon(QIcon(":resourse/images/field.png"));
    field7->setIcon(QIcon(":resourse/images/field.png"));
    field8->setIcon(QIcon(":resourse/images/field.png"));
    field9->setIcon(QIcon(":resourse/images/field.png"));
}

void Widget::checkWin() {
    if (g->get_order() > 4) {
        if (g->check_win() == 1) {
            win = true;
            first++;
            gamer1->setText(QString::number(first));
        } else if (g->check_win() == 2) {
            win = true;
            second++;
            gamer2->setText(QString::number(second));
        } else if (g->get_order() == 9 && g->check_win() == 3) {
            win = true;
        }
    }
}

QIcon Widget::setField() {
    if (g->get_order() % 2 != 0) {
        return QIcon(":resourse/images/X.png");
    } else {
        return QIcon(":resourse/images/O.png");
    }
}

void Widget::field1Cliced() {
    if (!win) {
        g->set_input(0, 0);
        field1->setIcon(setField());
        checkWin();
    }
}

void Widget::field2Cliced() {
    if (!win) {
        g->set_input(0, 1);
        field2->setIcon(setField());
        checkWin();
    }
}

void Widget::field3Cliced() {
    if (!win) {
        g->set_input(0, 2);
        field3->setIcon(setField());
        checkWin();
    }
}

void Widget::field4Cliced() {
    if (!win) {
        g->set_input(1, 0);
        field4->setIcon(setField());
        checkWin();
    }
}

void Widget::field5Cliced() {
    if (!win) {
        g->set_input(1, 1);
        field5->setIcon(setField());
        checkWin();
    }
}

void Widget::field6Cliced() {
    if (!win) {
        g->set_input(1, 2);
        field6->setIcon(setField());
        checkWin();
    }
}

void Widget::field7Cliced() {
    if (!win) {
        g->set_input(2, 0);
        field7->setIcon(setField());
        checkWin();
    }
}

void Widget::field8Cliced() {
    if (!win) {
        g->set_input(2, 1);
        field8->setIcon(setField());
        checkWin();
    }
}

void Widget::field9Cliced() {
    if (!win) {
        g->set_input(2, 2);
        field9->setIcon(setField());
        checkWin();
    }
}
