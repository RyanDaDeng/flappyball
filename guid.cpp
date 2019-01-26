#include "guid.h"

using namespace std;

guid::guid(){}



void guid::paintGuid(QPainter &painter)
{

    changePicture();
    painter.drawPixmap(0,0,380,500,pix);
}

void guid::setPixmap(QString picName){

     pix.load(picName);
}

  void guid::setCount(int cout){
      count=cout;
  }

void guid::changePicture()
{
    QString picName;
    count=count+1;
    if(count>3) count=1;
    switch(count)
    {
    case 1:picName=":/images/guid1.png";break;
    case 2:picName=":/images/guid2.png";break;
    case 3:picName=":/images/guid3.png";break;
    default:break;
    }
    pix.load(picName,0,Qt::AvoidDither|Qt::ThresholdDither|Qt::ThresholdAlphaDither);

}

guid::~guid()
     {



      }
