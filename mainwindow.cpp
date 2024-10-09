#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sw = new Stopwatch(this);


    ui->pb_startStop->setText("Старт");
    ui->pb_clear->setText("Очистить");
    ui->pb_lap->setText("Круг");
    ui->l_time->setText("Время: ");
    ui->l_showTime->setText(QString::number(sw->getCurrentTime()) + " сек");
    ui->pb_lap->setEnabled(sw->isStart());

    connect(sw, &Stopwatch::sig_Start, this, &MainWindow::RcvSignalStart);
    connect(sw, &Stopwatch::sig_Stop, this, &MainWindow::RcvSignalStop);
    connect(sw, &Stopwatch::sig_Clear, this, &MainWindow::RcvSignalClear);
    connect(sw, &Stopwatch::sig_Lap, this, &MainWindow::RcvSignalLap);
    connect(sw->getQTimer(), &QTimer::timeout, this, &MainWindow::RcvSignalShowTime);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_startStop_clicked()
{
    if (!sw->isStart())
    {
        sw->Start();
        ui->pb_startStop->setText("Стоп");
    }
    else
    {
        sw->Stop();
        ui->pb_startStop->setText("Старт");
    }
    ui->pb_lap->setEnabled(sw->isStart());
}

void MainWindow::on_pb_clear_clicked()
{
    sw->Clear();
}

void MainWindow::on_pb_lap_clicked()
{
    sw->Lap();
}

void MainWindow::RcvSignalStart()
{

}

void MainWindow::RcvSignalStop()
{

}

void MainWindow::RcvSignalClear()
{
    ui->l_showTime->setText(QString::number(sw->getCurrentTime()) + " сек");
    ui->tb_laps->clear();
}

void MainWindow::RcvSignalLap()
{
    ui->tb_laps->append("Круг " + QString::number(sw->getCurrentLap()) + ", время: " +
                       QString::number(sw->getCurrentTime() - sw->getStartTime()) + " сек");
    sw->setLap(sw->getCurrentLap() + 1);
}

void MainWindow::RcvSignalShowTime()
{
    if(sw->isStart())
    {
        ui->l_showTime->setText(QString::number(sw->getCurrentTime()) + " сек");
        sw->setTime(sw->getCurrentTime() + 0.1);
    }
}







