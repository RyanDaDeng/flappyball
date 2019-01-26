#ifndef GROUND_H
#define GROUND_H

#include "coordinate.h"
#include <QPainter>
/*
 * Author:Da Deng
 * This project is just a practice.
 * */
class ground
{

public:

    ground(Coordinate coordinate,double xvelocity);

    ~ground(); //Destructor


    void paintGround(QPainter &painter);


private:

    ground();
    Coordinate m_coordinate;


    double ground_xvelocity;
};

#endif // BALL_H
