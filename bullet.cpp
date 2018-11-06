
#include "bullet.h"
#include <QTimer>
#include<QGraphicsScene>
#include <QList>
#include "enemy.h"
#include "game.h"

extern Game *game;
Bullet::Bullet()
{
    //setRect(0,0,10,50);
    setPixmap(QPixmap(":/images/fire.png"));
    QTimer * timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Bullet::move()
{
    QList<QGraphicsItem *>  collided_items = collidingItems();

    for(int i=0; i< collided_items.size();i++)
    {
        if(typeid(*(collided_items[i]))==typeid(Enemy))
        {
            game->score->increase();
            scene()->removeItem(collided_items[i]);
            scene()->removeItem(this);
            delete collided_items[i];
            delete this;
            return;

        }

    }
    setPos(x(),y()-10);

    if(pos().y()+ pixmap().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
