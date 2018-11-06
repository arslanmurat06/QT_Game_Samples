#include "enemy.h"
#include <QTimer>
#include<QGraphicsScene>
#include <stdlib.h>,
#include <QList>
#include "game.h"

extern Game *game;
Enemy::Enemy()
{
    int random_number = rand() % 700;
    //setRect(0,0,100,100);
    setPixmap(QPixmap(":/images/goktasi.jpg"));
    setPos(random_number, 0);
    QTimer * timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Enemy::move()
{
    QList<QGraphicsItem *> collapsed_item =collidingItems();

   if( this->pos().y() >= 500 )
   {
       game->health->decrease();
       scene()->removeItem(this);
       delete this;
   }

               // we will not remove collapsed items here

//    for (int i=0; i< collapsed_item.size();i++)
//    {
//        if(typeid(* (collapsed_item[i])) == typeid(MyRect))

//        {
//            game->health->decrease();
//            scene()->removeItem(this);
//            delete this;
//        }

//    }

    setPos(x(),y()+10);

    if(pos().y()+ pixmap().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
