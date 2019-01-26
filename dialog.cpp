#include "dialog.h"
#include "ui_dialog.h"


using namespace std;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //this->setFixedSize(600, 500);
   this->setFixedSize(380, 500);
   gameStatus=GAME_GUIDE;
    isClicked=new int;
    *isClicked=0;
    score=0;
    loadBestScore();



    replayButton=new QPushButton(this);
    replayButton->setGeometry(120,400,140,78);
    replayButton->setStyleSheet("QPushButton{border-image:url(:/images/replay.png);}"
                             "QPushButton:pressed{margin: 2px 2px 2px 2px;}");
    replayButton->setHidden(true);



    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));

    guidTimer = new QTimer(this);
    connect(guidTimer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    guidTimer->start(200);


    connect(this, SIGNAL(gameStart()), this, SLOT(startGame()));

    m_ball=new Ball(Coordinate(60, 250,600, 400), 15, -9.8, 0,0,7);

    m_ground=new ground(Coordinate(0,100,600,500),0);

    m_guid=new guid();
    m_guid->setCount(1);
    m_guid->setPixmap(":/images/guid1.png");

    m_pipes[0]=new Pipes(Coordinate(500,0,600,500),-200,170,-5);
    m_pipes[1]=new Pipes(Coordinate(690,0,600,500),-170,200,-5);
    m_pipes[2]=new Pipes(Coordinate(880,0,600,500),-130,240,-5);

   connect(this, SIGNAL(gameOver()), this, SLOT(showScore()));
   connect(replayButton,SIGNAL(clicked()),this,SLOT(replay()));

}


void Dialog::addScore(){

    score++;
}

void Dialog::showScore(){

    timer->stop();

    replayButton->setHidden(false);

    if(score>bestScore){

        bestScore=score;
        saveBestScore();

    }

}

void Dialog::replay(){


 guidTimer->start();
 replayButton->setHidden(true);
 gameStatus=GAME_GUIDE;

 score=0;

 m_pipes[0]=new Pipes(Coordinate(500,0,600,500),-200,170,-5);
 m_pipes[1]=new Pipes(Coordinate(690,0,600,500),-170,200,-5);
 m_pipes[2]=new Pipes(Coordinate(880,0,600,500),-130,240,-5);
     m_ball=new Ball(Coordinate(60, 250,600, 400), 15, -9.8, 0,0,7);

    }

void Dialog::startGame(){

    guidTimer->stop();
    timer->start(32);
    gameStatus=GAME_START;

}

void Dialog::setBackgroundImage(QString img)
{
    this->setAutoFillBackground(true);
    QImage image;
    image.load(img);

    QPalette palette;
    palette.setBrush(QPalette::Window,
                      QBrush(image.scaled(size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
}

void Dialog::mousePressEvent(QMouseEvent *e)
{
      *isClicked=1;
    if(gameStatus==GAME_GUIDE){
        emit gameStart();
    }

}



Dialog::~Dialog()
{
    delete ui;

    delete isClicked;
}


void Dialog::isCollision(){


    int ballX=m_ball->getCoordinate().getQtRenderingXCoordinate()+15;
    int ballY=m_ball->getCoordinate().getQtRenderingYCoordinate()+15;




    if(ballY==400){

       gameStatus=GAME_OVER;
         emit gameOver();
    }
    for(int i=0;i<3;i++){

        if(  ballX> m_pipes[i]->getCoordinate().getQtRenderingXCoordinate()&&

             m_ball->getCoordinate().getQtRenderingXCoordinate()< m_pipes[i]->getCoordinate().getQtRenderingXCoordinate()+70){

            if(ballY>m_pipes[i]->getBotHeight()||ballY<m_pipes[i]->getTopHeight()+250+30){


               gameStatus=GAME_OVER;
                 emit gameOver();
            }


        }



    }



    }

void Dialog::paintEvent(QPaintEvent *event)
{

    if(m_pipes[0]->getCoordinate().getQtRenderingXCoordinate()==-60||
            m_pipes[1]->getCoordinate().getQtRenderingXCoordinate()==-60||
            m_pipes[2]->getCoordinate().getQtRenderingXCoordinate()==-60){
        score++;


    }

    QString s=tr( "<font color=white size='40' face='Sans'>%1</font>" ).arg(score) ;
    Dialog::ui->scoreLable->setText(s);



    if (gameStatus==GAME_START) {

            isCollision();
        // code for this exercise goes here
        QPainter painter(this);
        m_ball->render(painter,isClicked);

        m_pipes[0]->paintPipes(painter);

        m_pipes[1]->paintPipes(painter);
        m_pipes[2]->paintPipes(painter);

        m_ground->paintGround(painter);



    }

    else if(gameStatus==GAME_GUIDE){


        QString s=tr( "<font color=white size='40' face='Sans'>Best Score: %1</font>" ).arg(bestScore) ;
        Dialog::ui->bestscore->setText(s);

          QPainter painter(this);
          m_guid->paintGuid(painter);

    }

}


void Dialog::nextFrame()
{


    update();
}

void Dialog::saveBestScore()
{

    QFile file("top.d");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out<<this->bestScore;
}

void Dialog::loadBestScore()
{

    QFile file("top.d");
    if(file.open(QIODevice::ReadOnly))
    {
        QDataStream in(&file);
        in>>this->bestScore;
    }
    else
        bestScore=0;

}


