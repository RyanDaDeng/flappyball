#include "pipes.h"

using namespace std;

 Pipes::Pipes(Coordinate coordinate,int topPipe_height,int botPipe_height,double xvelocity):
      m_coordinate(coordinate),
      m_topPipe_height(topPipe_height),
      m_botPipe_height(botPipe_height),
      pipes_xvelocity(xvelocity){}





void Pipes::paintPipes(QPainter &painter){



    if(m_coordinate.getQtRenderingXCoordinate()==-70){
             m_coordinate.setXCoordinateToZero(500);
             m_botPipe_height=randBotHeight();
             m_topPipe_height=-(250-(m_botPipe_height-120));


    }


       QPixmap pix;
 //  painter.setRenderHint(QPainter::Antialiasing,true);

       pix.load(":/images/pipe1.png");
       painter.drawPixmap(m_coordinate.getQtRenderingXCoordinate(), m_topPipe_height,70,250,pix);
       pix.load(":/images/pipe2.png");
       painter.drawPixmap(m_coordinate.getQtRenderingXCoordinate(),m_botPipe_height,70,250,pix);


        m_coordinate.changeInXCoordinate(pipes_xvelocity);
/*  300>bot>170*/

       /*120 gap*/
       /*mid width500*/

   }


void Pipes::setTopHeight(int topHeight){

     m_topPipe_height=topHeight;
}

void Pipes::setBotHeight(int botHeight){

    m_botPipe_height=botHeight;
}

int  Pipes::randBotHeight(){
     int pipeR=0;
     while(pipeR<170||pipeR>300){
           pipeR=qrand()%300+170;
     }


     return pipeR;

}

    Coordinate Pipes::getCoordinate(){

        return m_coordinate;
    }

Pipes::~Pipes()
     {


      }
