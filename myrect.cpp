#include "myrect.h"
#include <QDebug>
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include <myrect.h>
#include "enemy.h"
#include "game.h"
#include <QGraphicsPixmapItem>
extern Game *game;
void MyRect::keyPressEvent(QKeyEvent *event)
{
   // qDebug() <<"Kareye tıklandı";
    if(event->key() == Qt::Key_Left )
    {
        qDebug() <<"Sola tıklandı";

        if(pos().x() > 0)
                setPos(x()-10,y());


    }
    else if (event->key() == Qt::Key_Right)
    {
        qDebug() <<"Sağa tıklandı";


        if(pos().x()+100 < 800 )
            setPos(x()+10,y());
    }


    else if(event->key() ==Qt::Key_Space)
    {
        Bullet *bullet = new Bullet();
        bullet->setPos(x() +game->player->pixmap().width()/2-pixmap().width()/2,y());
        scene()-> addItem(bullet);
        qDebug() << "Bullet created";

    }
}

void MyRect::spawn()
{
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);

}
