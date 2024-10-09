#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_startStop_clicked();
    void on_pb_clear_clicked();
    void on_pb_lap_clicked();

    void RcvSignalShowTime();
    void RcvSignalStart();
    void RcvSignalStop();
    void RcvSignalClear();
    void RcvSignalLap();


private:
    Ui::MainWindow *ui;
    Stopwatch* sw;
};
#endif // MAINWINDOW_H
