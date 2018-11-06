
#include "game.h"

Game::Game() {

    scene = new QGraphicsScene();
    player = new MyRect();
    player->setPixmap(QPixmap(":/images/superman.jpg"));

    //player->setRect(0,0,100,100);
    scene->addItem(player);
    player->setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    player->setFocus();
    view = new QGraphicsView();
    view->setScene(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);
    timer = new QTimer();
    score = new Score();
    health = new Health();
    scene->addItem(score);
    scene->addItem(health);


     player->setPos(view->width()/2-player->pixmap().width()/2,view->height()-player->pixmap().height());
     QObject::connect(timer,SIGNAL(timeout()), player,SLOT(spawn()));
     timer->start(2000);

}

void Game::show()
{
    view->show();
}

