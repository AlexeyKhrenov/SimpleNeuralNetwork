#include "mainwindow.h"
#include <QApplication>
#include <QThread>
#include <mnistfilereader.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    std::function<void()> fp = std::bind(&MainWindow::updateFromModel, &w);

    // update from model
    Model model(fp);

    w.fromModel(&model);

    return a.exec();
}
