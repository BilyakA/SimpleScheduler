#include "Scheduler.hpp"
#include <QDebug>

Scheduler::Scheduler(QObject *parent)
    : QObject(parent)
    , p_executerThread(nullptr)
    , p_executer(nullptr)
{
    p_executerThread = new QThread(this);
    p_executerThread->setObjectName("Executer thread");
    p_executer = new Executer();
    p_executer->moveToThread(p_executerThread);
    p_executerThread->start();
}

Scheduler::~Scheduler()
{
    if (p_executer) {
        p_executer->deleteLater();
    }

    if (p_executerThread) {
        p_executerThread->quit();
        if (!p_executerThread->wait(1000)) {
            p_executerThread->terminate();
            p_executerThread->wait();
        }
    }
}

void Scheduler::addTask(Task *task)
{
    if (m_tasks.contains(task)) {
        return;
    }

    m_tasks.append(task);

    connect(task, &Task::timeout, this, [this, task](){
        executeTask(task);
    });
}

void Scheduler::executeTask(Task* task)
{
    // schedule execution
    QMetaObject::invokeMethod(p_executer, [this, task](){
        p_executer->execute(task);
    });
}
