#include <QGraphicsItem>
#include "health.h"
#include <QFont>
Health::Health(QGraphicsItem *parent) : QGraphicsTextItem (parent)
{
    health =5;
    setPlainText(QString("Score") + QString:: number(health));
    setFont(QFont("times",16));
    setDefaultTextColor(Qt::red);
    setPos(x(),y()+20);
}

void Health::decrease()
{
    health--;
    setPlainText(QString("Health ") + QString:: number(health));

}

int Health::getHealth()
{
    return health;
}
