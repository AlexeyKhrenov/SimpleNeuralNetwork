#ifndef IMAGEAREA_H
#define IMAGEAREA_H

#include <QColor>
#include <QImage>
#include <QPoint>
#include <QWidget>

class ImageArea : public QWidget{
    Q_OBJECT

public:
    ImageArea(QWidget *parent=0);
    QImage image;

    //bool OpenPixelMap();
protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // IMAGEAREA_H
