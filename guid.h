#ifndef GUID_H
#define GUID_H

#include "coordinate.h"
#include <QPainter>
/*
 * Author:Da Deng
 * This project is just a practice.
 * */
class guid
{

public:

    guid();

    ~guid(); //Destructor


    void paintGuid(QPainter &painter);

    void changePicture();
  void setPixmap(QString picName);
  void setCount(int cout);

private:


    QPixmap pix;
    int count;

};

#endif // BALL_H
