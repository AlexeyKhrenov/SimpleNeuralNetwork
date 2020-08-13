#include "mainwindow.h"
#include <QApplication>
#include <QThread>
#include <mnistfilereader.h>
#include <neuralnetworkmock.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    NeuralNetworkmock aiMock;

    w.show();

    std::function<void()> fp = std::bind(&MainWindow::updateFromModel, &w);

    const char* imageFile = "../train-images.idx3-ubyte";
    const char* labelFile = "../train-labels.idx1-ubyte";
    // update from model
    Model model(fp, imageFile, labelFile, &aiMock);

    w.fromModel(&model);

    return a.exec();
}
