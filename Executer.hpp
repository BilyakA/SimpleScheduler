#pragma once

#include <QObject>
#include "Task.hpp"
#include <QMutex>

class Executer : public QObject
{
    Q_OBJECT
public:
    explicit Executer(QObject *parent = nullptr);

    void execute(Task* task);

private:
    QMutex m_executionMutex;
};
