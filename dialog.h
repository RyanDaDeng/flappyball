#ifndef DIALOG_H
#define DIALOG_H

#include "ball.h"
#include "ground.h"
#include "pipes.h"
#include "guid.h"
#include <QDialog>
#include <QTimer>
#include <QPushButton>
#include <QFile>
//#include <QPainter>

/*
 * Author:Da Deng
 * This project is just a practice.
 * */
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
public slots:
    void nextFrame();
    void addScore();

    void showScore();

    void startGame();

    void replay();

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();



protected:

    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *e);
    void setBackgroundImage(QString img);

    void isCollision();
    void saveBestScore();
    void loadBestScore();
signals:
    void gameOver();
    void gameStart();

private:
    Ui::Dialog *ui;
    Ball  * m_ball;
    ground * m_ground;
    Pipes *m_pipes[3];
    QTimer * timer;
    int score;
    int *isClicked;

    QPushButton *replayButton;

    guid *m_guid;

   QTimer * guidTimer;

   enum status{GAME_OVER,GAME_START,GAME_GUIDE,GAME_RESULT}gameStatus; //0=lose 1=start 2=guide

   int bestScore;



};

#endif // DIALOG_H
