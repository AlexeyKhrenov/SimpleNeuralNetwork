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
    model = NULL;

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
    ui->gridLayout->addWidget(imageArea, 0, 0, Qt::AlignCenter);

    ui->comboBox->addItem("Train");
    ui->comboBox->addItem("Test");

    ui->stepEdit->setValidator( new QIntValidator(1, 99999, this) );
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
    ui->labelLabelValue->setText(QString(model->labelFile));
    ui->imagesLabelValue->setText(QString(model->imageFile));

    ui->comboBox->setCurrentIndex((int)model->isTestingMode);
    ui->stepEdit->setText(QString::number(model->step));

    ui->labelValue->setText(QString::number(model->label));
    ui->positionValue->setText(QString::number(model->position));

    ui->textOutput->setText(QString(model->warning));

    char *t = model->image;

    for(int i = 0; i < 28; i++){
        for(int j = 0; j < 28; j++){
            imageArea->image.setPixelColor(j, i, model->image[i * 28 + j]);
        }
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(model != NULL){
        model->setTrainingMode((bool)index);
    }
}

void MainWindow::on_pushButton_clicked()
{
    model->start();
}

void MainWindow::on_stepEdit_returnPressed()
{
    int step = ui->stepEdit->text().toInt();
    model->setStep(step);
}
