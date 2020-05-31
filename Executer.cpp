#include "Executer.hpp"
#include <QMutexLocker>

Executer::Executer(QObject *parent)
    : QObject(parent)
    , m_executionMutex()
{

}

void Executer::execute(Task *task)
{
    // using mutex here because if execution of some task will sleep for any
    // reason - Qt event loop may start execution of another with same thread
    QMutexLocker locker(&m_executionMutex);
    task->execute();
}
