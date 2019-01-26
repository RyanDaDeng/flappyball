#include "ground.h"

using namespace std;

ground::ground(Coordinate coordinate, double xvelocity):
    m_coordinate(coordinate),
    ground_xvelocity(xvelocity){}





void ground::paintGround(QPainter &painter){

       QPixmap pixmap;
       pixmap.load(":/images/ground.png");
//ground_xvelocity-=0.1;

      if(ground_xvelocity<-45){
       ground_xvelocity=-10;

      }
       ground_xvelocity=ground_xvelocity-10;
       painter.drawPixmap(ground_xvelocity ,
                      400,
                      500,
                      100,pixmap);//a function to draw pixmap



   }



ground::~ground()
     {



      }
