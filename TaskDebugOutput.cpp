#include "TaskDebugOutput.hpp"
#include <QDebug>

TaskDebugOutput::TaskDebugOutput(QObject *parent)
    : Task(parent)
    , m_text("")
{

}

QString TaskDebugOutput::text() const
{
    return m_text;
}
void TaskDebugOutput::setText(QString text)
{
    m_text = text;
}

void TaskDebugOutput::execute()
{
    qDebug() << m_text;
}
