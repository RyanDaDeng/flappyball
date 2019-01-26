#ifndef COORDINATE_H
#define COORDINATE_H
/*
 * Author:Da Deng
 * This project is just a practice.
 * */

class Coordinate
{
public:

    Coordinate(unsigned
        int xCoordinate,
        unsigned int yCoordinate,
        unsigned int frameWidth,
        unsigned int frameHeight);

    //get frame height and width
    unsigned int getFrameHeight();
    unsigned int getFrameWidth();

    //rendering X/Y into Qt formate
    int getQtRenderingXCoordinate();
    int getQtRenderingYCoordinate();

    //changing position of coordinate
    void setYCoordinateToZero(int offset);
    void setXCoordinateToZero(int offset);

    //setting up priavte attributes
    void setX(int X);
    void setY(int Y);
    void setWidth(int width);
    void setHeight(int height);

    //changing position of coordinate
    void changeInXCoordinate(int change);
    void changeInYCoordinate(int change);


private:
    unsigned int m_xCoordinate;
    unsigned int m_yCoordinate;
    unsigned int m_frameWidth;
    unsigned int m_frameHeight;

};

#endif // COORDINATE_H
