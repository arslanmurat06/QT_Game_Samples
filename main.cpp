#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsScene>
#include<QGraphicsView>
#include <QGraphicsRectItem>
#include "myrect.h"
#include <QTimer>
#include "game.h"

Game *game;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show();

    return a.exec();

}
