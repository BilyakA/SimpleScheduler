#pragma once

#include <QObject>
#include <QTimer>

class Task : public QObject
{
    Q_OBJECT
public:
    explicit Task(QObject *parent = nullptr);
    virtual ~Task() override;

    virtual void execute() = 0;

    time_t timePeriod() const;
    void setTimePeriod(time_t timePeriod);

    void startTimer();

signals:
    // any complicated time period logic could be added to this class or subclasses
    // in any case timeout signal must be emmited to execute task
    void timeout();

private:
    time_t m_timePeriod;
    QTimer* p_timer;
};
