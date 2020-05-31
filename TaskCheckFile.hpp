#pragma once

#include "Task.hpp"

class TaskCheckFile : public Task
{
    Q_OBJECT
public:
    explicit TaskCheckFile(QObject *parent = nullptr);

    void execute() override;

    QString fileName() const;
    void setFileName(QString fileName);

private:
    QString m_fileName;
};
