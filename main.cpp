#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
//attenzione in file non vengo estratti bene facciamo controllare da ai... controlliamo poi visualizzazione immagine estratta su gui... e che quando si preme estrai facce si disabilitano gli altri bottoni