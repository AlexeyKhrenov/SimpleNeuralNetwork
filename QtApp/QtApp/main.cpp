#include "mainwindow.h"
#include <QApplication>
#include <QThread>
#include <mnistfilereader.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    MnistFileReader fileReader("../train-images.idx3-ubyte");

    char image[28*28];

    fileReader.getNextImage(image);
    fileReader.getNextImage(image);
    fileReader.getNextImage(image);

    for(int i = 0; i < 28 * 28; i++)
    {
        w.imageArea->image.setPixel(i % 28, i / 28, image[i]);
    }

    return a.exec();
}
