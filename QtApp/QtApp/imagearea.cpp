#include <QtWidgets>
#include <imagearea.h>

ImageArea::ImageArea(QWidget *parent) : QWidget(parent)
{
    //setGeometry(0, 0, 300, 100);
    QPalette pal = palette();

    // set black background
    pal.setColor(QPalette::Background, Qt::green);
    setAutoFillBackground(true);
    setPalette(pal);

    image = QImage(28, 28, QImage::Format_Grayscale8);

    this->setFixedSize(100,100);
}

void ImageArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(1, 1, image);
}
