#include "ball.h"
#include <iostream>
using namespace std;

Ball::Ball(Coordinate coordinate):
    m_coordinate(coordinate){}



Ball::Ball(Coordinate coordinate,
    unsigned int radius):
    m_coordinate(coordinate),
    m_radius(radius){}



Ball::Ball(Coordinate coordinate,
    unsigned int radius,
    double gravity,
    double xVelocity,
    double yVelocity,
    int Colour):
    m_coordinate(coordinate),
    m_radius(radius),
    m_gravity(gravity),
    m_xVelocity(xVelocity),
    m_yVelocity(yVelocity),
    m_Colour(Colour){}




Ball::~Ball()
  {

    //Check if the ball is destroyed.
       cout<<"Ball Destructor called."<<endl;

   }


Coordinate Ball::getCoordinate(){

    return m_coordinate;

   }


unsigned int Ball::getRadius(){

    return m_radius;

   }

void Ball::setRadius(unsigned int new_radius){

    m_radius=new_radius;

   }

double Ball::getGravity(){

    return m_gravity;

   }

double Ball::getXvel(){

    return m_xVelocity;

   }

void Ball::setXvel(double xvel){

    m_xVelocity=xvel;

   }

double Ball::getYvel(){

    return m_yVelocity;

   }

void Ball::setYvel(double yvel){

    m_yVelocity=yvel;

   }

int Ball::getColour(){

    return m_Colour;

   }

void Ball::setColour(int new_colour){

    m_Colour = new_colour;

   }


bool Ball::isCollisionDown(){

    return m_coordinate.getQtRenderingYCoordinate() >=
        (signed int) (m_coordinate.getFrameHeight() - (signed int) m_radius);
   }


void Ball::render(QPainter &painter, int* isClicked){



painter.drawPixmap(0,0,600,400,QPixmap("://images/bg.png"));

    if(*isClicked==1){

        m_yVelocity=15;
        m_xVelocity=0;
        *isClicked=0;

    }

    if(isCollisionDown()&&*isClicked!=1){
         m_coordinate.setYCoordinateToZero(this->getRadius());
        painter.setPen ( Qt::black );
        painter.setBrush( QBrush(  Qt::GlobalColor(m_Colour) ) );

        painter.drawEllipse(m_coordinate.getQtRenderingXCoordinate() - (int) m_radius,
            m_coordinate.getQtRenderingYCoordinate() -(int) m_radius,
            m_radius * 2,
            m_radius * 2);

    }else{


        painter.setPen ( Qt::black );
        painter.setBrush( QBrush(  Qt::GlobalColor(m_Colour) ) );
        painter.drawEllipse(m_coordinate.getQtRenderingXCoordinate() - (int) m_radius,
            m_coordinate.getQtRenderingYCoordinate() -(int) m_radius,
            m_radius * 2,
            m_radius * 2);

                   m_yVelocity += m_gravity / 5.0;
                   m_coordinate.changeInXCoordinate(m_xVelocity);
                   m_coordinate.changeInYCoordinate(m_yVelocity);

    }





   }








