#include <QApplication>

#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QInputDialog>
#include <QCoreApplication>

#include "Scheduler.hpp"

#include "TaskCheckFile.hpp"
#include "TaskDebugOutput.hpp"

void showTextDialog(TaskDebugOutput* task)
{
    bool ok = false;
    QString debugText = QInputDialog::getText(nullptr, "Specify debug text", "Debug text:",
                                              QLineEdit::Normal, task->text(), &ok, Qt::MSWindowsFixedSizeDialogHint);
    if (ok) {
        task->setText(debugText);
    }
}
void showFileDialog(TaskCheckFile* task)
{
    bool ok = false;
    QString fileName = QInputDialog::getText(nullptr, "Specify file to check", "File to check:",
                                              QLineEdit::Normal, task->fileName(), &ok, Qt::MSWindowsFixedSizeDialogHint);
    if (ok) {
        task->setFileName(fileName);
    }
}
void exitApplication()
{
    QCoreApplication::exit(0);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);

    Scheduler scheduler;

    TaskCheckFile taskCheckFile;
    taskCheckFile.setFileName("C:/ESEMPIO.txt");
    taskCheckFile.setTimePeriod(30000);
    taskCheckFile.startTimer();

    TaskDebugOutput taskDebugOutput;
    taskDebugOutput.setText("42");
    taskDebugOutput.setTimePeriod(10000);
    taskDebugOutput.startTimer();

    scheduler.addTask(&taskCheckFile);
    scheduler.addTask(&taskDebugOutput);

    QSystemTrayIcon systemTrayIcon;
    QMenu trayMenu;

    QAction setTextAction;
    setTextAction.setText("Set text");
    QObject::connect(&setTextAction, &QAction::triggered, QCoreApplication::instance(), [&taskDebugOutput](){
        showTextDialog(&taskDebugOutput);
    });

    QAction setFileAction;
    setFileAction.setText("Set file");
    QObject::connect(&setFileAction, &QAction::triggered, QCoreApplication::instance(), [&taskCheckFile](){
        showFileDialog(&taskCheckFile);
    });

    QAction exitAction;
    exitAction.setText("Exit");
    QObject::connect(&exitAction, &QAction::triggered, QCoreApplication::instance(), exitApplication);

    trayMenu.addAction(&setTextAction);
    trayMenu.addAction(&setFileAction);
    trayMenu.addAction(&exitAction);

    systemTrayIcon.setContextMenu(&trayMenu);
    systemTrayIcon.setIcon(QIcon(":/heart.png"));
    systemTrayIcon.show();

    return a.exec();
}
