#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent)
    /*
    
    Инициализируем объект Stopwatch с родительским объектом parent.
    Устанавливаем начальные значения для переменных:
        isStart_ — флаг, указывающий, запущен ли секундомер (изначально false).
        currentTime_ — текущее время (изначально 0.0 секунд).
        startTime_ — время начала (изначально 0.0 секунд).
        currentLap_ — текущий круг (изначально 1).
    Создаем объект QTimer и привязываем его к секундомеру.
    */
    
    : QObject{parent}
{
    isStart_ = false;
    currentTime_ = 0.;
    startTime_ = 0.;
    currentLap_ = 1;
    qTimer = new QTimer(this);
}

void Stopwatch::Start()
{
    
    /*
    Устанавливаем флаг isStart_ в true, указывая, что секундомер запущен.
    Запускаем таймер qTimer с интервалом 100 миллисекунд.
    Излучаем сигнал sig_Start, уведомляя об этом другие части программы.
    */
    isStart_ = true;
    qTimer->start(100);
    emit sig_Start();
}

void Stopwatch::Stop()
{
    /*
    Устанавливаем флаг isStart_ в false, указывая, что секундомер остановлен.
    Останавливаем таймер qTimer.
    Излучаем сигнал sig_Stop, уведомляя об этом другие части программы.
    */
    isStart_ = false;
    qTimer->stop();
    emit sig_Stop();
}

void Stopwatch::Clear()
{
    /*
    Сбрасываем текущее время (currentTime_) и время начала (startTime_) до 0.0 секунд.
    Сбрасываем текущий круг (currentLap_) до 1.
    Излучаем сигнал sig_Clear, уведомляя об этом другие части программы.
    */
    currentTime_ = 0.;
    startTime_ = 0.;
    currentLap_ = 1;
    emit sig_Clear();
}

void Stopwatch::Lap()
{
    /*
    Сигнал sig_Lap, уведомляя об этом другие части программы.
    */
    emit sig_Lap();
}

void Stopwatch::setTime(float time)
{
    /*
   Устанавливаем текущее время секундомера (currentTime_) в значение time.
   */
    currentTime_ = time;
}

void Stopwatch::setLap(int lap)
{
    /*
   Устанавливаем текущий круг (currentLap_) в значение lap.
   */
    currentLap_ = lap;
}

float Stopwatch::getCurrentTime()
{
    /*
   Возвращаем текущее время секундомера (currentTime_).
   */
    return currentTime_;
}

float Stopwatch::getStartTime()
{
    /*
   Возвращаем время начала (startTime_).
   */
    return startTime_;
}

int Stopwatch::getCurrentLap()
{
    /*
    Устанавливаем время начала (startTime_) в текущее время (currentTime_).
       Возвращаем текущий круг (currentLap_).
    */
    startTime_ = currentTime_;
    return currentLap_;
}

bool Stopwatch::isStart()
{
    /*
   Возвращаем состояние секундомера (isStart_), указывая, запущен ли он.
   */
    return isStart_;
}

QTimer *Stopwatch::getQTimer()
{
    /*
   Возвращаем указатель на объект QTimer (qTimer).
   */
    return qTimer;
}

