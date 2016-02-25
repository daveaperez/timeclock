#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QMessageBox>
#include "employee.h"
#include "clockform.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QList<Employee*> *empList;
    QTimer* dateTimer;
    uint quitHoldTime;
    bool exiting;

    void updateTime();
    void updateEmployeeList();

private slots:
    void dateTimer_Tick(void);
    void quitTimer_Tick(void);
    void clock_Click(void);
    void clock_Pressed(void);
    void clock_Released(void);
};

#endif // MAINWINDOW_H
