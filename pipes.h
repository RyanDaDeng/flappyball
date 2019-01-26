#ifndef PIPES_H
#define PIPES_H


#include <QPainter>
#include "coordinate.h"
/*
 * Author:Da Deng
 * This project is just a practice.
 * */
class Pipes
{



public:

    Pipes(Coordinate coordinate,int topPipe_height,int botPipe_height,double xvelocity);


    ~Pipes(); //Destructor


    void paintPipes(QPainter &painter);

    void setTopHeight(int topHeight);
    void setBotHeight(int botHeight);
    int getTopHeight(){
        return m_topPipe_height;
    }

    int getBotHeight(){
        return m_botPipe_height;
    }

    Coordinate getCoordinate();
    int randBotHeight();

    signals:
      void passPipe();

    private:


    Coordinate m_coordinate;
    int m_topPipe_height;
    int m_botPipe_height;
    double pipes_xvelocity;
};

#endif // BALL_H
