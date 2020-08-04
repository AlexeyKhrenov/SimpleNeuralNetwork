#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <imagearea.h>
#include <QHBoxLayout>
#include <qpushbutton.h>
#include <QThread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    imageArea = new ImageArea;
    //setCentralWidget(imageArea);

    // Set the title
    setWindowTitle(tr("Scribble"));

    // Size the app
    //resize(500, 500);

    QPushButton *button1 = new QPushButton("One");
    QPushButton *button2 = new QPushButton("Two");
    QPushButton *button3 = new QPushButton("Three");
    QPushButton *button4 = new QPushButton("Four");
    QPushButton *button5 = new QPushButton("Five");

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);
    layout->addWidget(button4);
    layout->addWidget(button5);

    ui->gridLayout->addWidget(button1, 0, 0, Qt::AlignCenter);
    ui->gridLayout->addWidget(button2, 0, 1, Qt::AlignCenter);
    ui->gridLayout->addWidget(button3, 1, 0, Qt::AlignCenter);
    ui->gridLayout->addWidget(imageArea, 1, 1, Qt::AlignCenter);


}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
}

void MainWindow::on_actionOpen_triggered()
{
    for(int i = 0; i < 10; i++)
    {
        QThread::msleep(400);
        imageArea->image.fill(i * 10);
        imageArea->repaint();
    }
}

void MainWindow::on_actionSave_triggered()
{

}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.drawRect(QRect(80, 120, 200, 100));
}
