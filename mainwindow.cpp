#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    
    //Конструктор MainWindow
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //Создание секундомера

    ui->setupUi(this);
    sw = new Stopwatch(this);

    //Настройка кнопок и меток:
    ui->pb_startStop->setText("Старт");
    ui->pb_clear->setText("Очистить");
    ui->pb_lap->setText("Круг");
    ui->l_time->setText("Время: ");
    ui->l_showTime->setText(QString::number(sw->getCurrentTime()) + " сек");
    ui->pb_lap->setEnabled(sw->isStart());

    //Соединение сигналов и слотов
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
    /*
    Проверка состояния секундомера :
    Если секундомер не запущен(!sw->isStart()), то он запускается с помощью метода Start().
    Текст кнопки изменяется на “Стоп”.
    */
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
    //Кнопка “Круг”(pb_lap) активируется или деактивируется в зависимости от состояния секундомера(sw->isStart())
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
   /*
   Обновляем текст метки l_showTime, показывая текущее время секундомера.
    Очищаем текстовое поле tb_laps, где отображаются круги.
   */
    ui->l_showTime->setText(QString::number(sw->getCurrentTime()) + " сек");
    ui->tb_laps->clear();
}

void MainWindow::RcvSignalLap()
{
    /*
    Добавляем новую запись в текстовое поле tb_laps с информацией о текущем круге и времени, прошедшем с начала круга.
    Увеличиваем номер текущего круга на 1.
    */
    ui->tb_laps->append("Круг " + QString::number(sw->getCurrentLap()) + ", время: " +
                       QString::number(sw->getCurrentTime() - sw->getStartTime()) + " сек");
    sw->setLap(sw->getCurrentLap() + 1);
}

void MainWindow::RcvSignalShowTime()
{
   
    /*
    Обновляем текст метки l_showTime, показывая текущее время секундомера.
    Увеличиваем текущее время секундомера на 0.1 секунды.
    */
    if(sw->isStart())
    {
        ui->l_showTime->setText(QString::number(sw->getCurrentTime()) + " сек");
        sw->setTime(sw->getCurrentTime() + 0.1);
    }
}







