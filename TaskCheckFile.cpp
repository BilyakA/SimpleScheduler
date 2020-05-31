#include "TaskCheckFile.hpp"
#include <QDebug>
#include <QFileInfo>

TaskCheckFile::TaskCheckFile(QObject *parent)
    : Task(parent)
    , m_fileName("")
{

}

QString TaskCheckFile::fileName() const
{
    return m_fileName;
}
void TaskCheckFile::setFileName(QString fileName)
{
    m_fileName = fileName;
}

void TaskCheckFile::execute()
{
    if (!QFileInfo(m_fileName).exists()) {
        qDebug() << m_fileName << "does not exist";
    }
}
