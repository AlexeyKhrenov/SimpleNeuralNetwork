#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <imagearea.h>
#include <QHBoxLayout>
#include <qpushbutton.h>
#include <QThread>
#include <model.h>

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

void MainWindow::paintEvent(QPaintEvent *event)
{
    //QPainter painter(this);
}

void MainWindow::fromModel(Model* model){
    this->model = model;
    updateFromModel();
}

void MainWindow::updateFromModel(){
    ui->warningLabel->setText(QString(model->warning));
    ui->labelLabelValue->setText(QString(model->labelFile));
    ui->imagesLabelValue->setText(QString(model->imageFile));
}
