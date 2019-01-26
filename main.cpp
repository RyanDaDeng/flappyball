#include "dialog.h"
#include "ball.h"
#include "coordinate.h"
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;

    w.show();




    return a.exec();
}
