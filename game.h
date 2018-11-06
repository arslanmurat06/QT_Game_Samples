#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QGraphicsScene>
#include<QGraphicsView>
#include <QGraphicsRectItem>
#include "myrect.h"
#include <QTimer>
#include "score.h"
#include "health.h"

 class Game :public QGraphicsView {
  public:
     QGraphicsScene * scene;
     MyRect * player;
     QGraphicsView * view ;
     QTimer *timer ;
 public:
     Score *score;
     Health *health;


public :
    Game();

public :
   void show();

};

#endif // GAME_H
