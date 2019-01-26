#include "coordinate.h"

Coordinate::Coordinate(
        unsigned int xCoordinate,
        unsigned int yCoordinate,
        unsigned int frameWidth,
        unsigned int frameHeight):
    m_xCoordinate(xCoordinate),
    m_yCoordinate(yCoordinate),
    m_frameWidth(frameWidth),
    m_frameHeight(frameHeight){}


unsigned int Coordinate::getFrameHeight(){

           return m_frameHeight;
       }

unsigned int Coordinate::getFrameWidth(){

           return m_frameWidth;
       }


int Coordinate::getQtRenderingYCoordinate(){

           return m_frameHeight - m_yCoordinate;

       }

int Coordinate::getQtRenderingXCoordinate(){

           return m_xCoordinate;

       }


void Coordinate::setYCoordinateToZero(int offset){

           m_yCoordinate=offset;

       }

void Coordinate::setXCoordinateToZero(int offset){

           m_xCoordinate=offset;

       }

void Coordinate::setX(int X){

           m_xCoordinate = X;

       }

void Coordinate::setY(int Y){

           m_yCoordinate = Y;

       }


void Coordinate::setWidth(int width){

           m_frameWidth = width;

       }

void Coordinate::setHeight(int height){

           m_frameHeight = height;

       }

void Coordinate::changeInXCoordinate(int change){

           m_xCoordinate = m_xCoordinate+change;

       }


void Coordinate::changeInYCoordinate(int change){

           m_yCoordinate=m_yCoordinate+change;

       }





