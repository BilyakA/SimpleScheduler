#pragma once

#include "Task.hpp"

class TaskDebugOutput : public Task
{
    Q_OBJECT
public:
    explicit TaskDebugOutput(QObject *parent = nullptr);

    void execute() override;

    QString text() const;
    void setText(QString text);

private:
    QString m_text;
};
