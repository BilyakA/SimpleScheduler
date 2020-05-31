#pragma once

#include <QObject>
#include <QThread>
#include <QList>

#include "TaskDebugOutput.hpp"
#include "TaskCheckFile.hpp"
#include "Executer.hpp"

class Scheduler : public QObject
{
    Q_OBJECT
public:
    Scheduler(QObject *parent = nullptr);
    ~Scheduler();

    void addTask(Task* task);

private slots:
    void executeTask(Task* task);

private:
    QList<Task*> m_tasks;

    QThread* p_executerThread;
    Executer* p_executer;
};
