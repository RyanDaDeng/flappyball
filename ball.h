#ifndef BALL_H
#define BALL_H

#include "coordinate.h"
#include <QPainter>

/*
 * Author:Da Deng
 * This project is just a practice.
 * */
class Ball
{

public:


    Ball(Coordinate coordinate);

    Ball(Coordinate coordinate,
        unsigned int radius);

    Ball(Coordinate coordinate,
        unsigned int radius,
        double gravity,
        double xVelocity,
        double yVelocity,
        int Colour);



    ~Ball(); //Destructor

    //Functions for getting private attributes
    Coordinate getCoordinate();
    unsigned int getRadius();
    double getGravity();
    double getXvel();
    double getYvel();
    int getColour();

    //Functions for setting private attributes.
    void setRadius(unsigned int new_radius);
    void setXvel(double xvel);
    void setYvel(double yvel);
    void setColour(int new_colour);

    // Functions for ball bouncing, isCollision()checks if the ball hitting the sides(Top,Down,Right,Left)
    bool isCollisionDown();
    bool isCollisionRight();
    bool isCollisionTop();
    bool isCollisionLeft();

    //Functions for rendering ball
    void render(QPainter &painter,int* isClicked);


private:

    Ball();
    Coordinate m_coordinate;
    unsigned int m_radius;
    double m_gravity;
    double m_xVelocity;
    double m_yVelocity;
    int m_Colour; //It prensents the colour of ball, which will be inserted as a parameter for QBrush().



    int frameCount;

};

#endif // BALL_H
