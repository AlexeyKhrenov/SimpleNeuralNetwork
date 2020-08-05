#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPainter>
#include <imagearea.h>

#include <model.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    virtual void paintEvent(QPaintEvent *event);
    ImageArea *imageArea;

    void fromModel(Model* model);
    void updateFromModel();

private slots:

private:
    Ui::MainWindow *ui;
    QString currentFile = "";
    Model* model;
};

#endif // MAINWINDOW_H
