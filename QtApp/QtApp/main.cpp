#include "mainwindow.h"
#include <QApplication>
#include <QThread>
#include <mnistfilereader.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Model model(w.updateFromModel);

    w.fromModel(&model);
}
