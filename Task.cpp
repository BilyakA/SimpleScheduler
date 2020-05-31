#include "Task.hpp"

Task::Task(QObject *parent)
    : QObject(parent)
    , m_timePeriod(1000)
    , p_timer(nullptr)
{
    p_timer = new QTimer(this);
    p_timer->setSingleShot(false);
    p_timer->setInterval(m_timePeriod);

    connect(p_timer, &QTimer::timeout, this, &Task::timeout);
}

Task::~Task()
{

}

time_t Task::timePeriod() const
{
    return m_timePeriod;
}
void Task::setTimePeriod(time_t timePeriod)
{
    m_timePeriod = timePeriod;
    p_timer->setInterval(m_timePeriod);
}

void Task::startTimer()
{
    p_timer->start();
}
