#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    quitHoldTime = 0;
    exiting = false;
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    dateTimer = new QTimer();
    ui->setupUi(this);

    updateTime();
    updateEmployeeList();

    connect(dateTimer, SIGNAL(timeout()), this, SLOT(dateTimer_Tick()));
    connect(ui->clockButton, SIGNAL(clicked(bool)), this, SLOT(clock_Click()));
    connect(ui->clockButton, SIGNAL(pressed()), this, SLOT(clock_Pressed()));
    connect(ui->clockButton, SIGNAL(released()), this, SLOT(clock_Released()));
    dateTimer->start(2000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTime()
{
    QTime currentTime = QTime::currentTime();
    QDate currentDate = QDate::currentDate();
    QString time = currentTime.toString("HH:mm A");
    QString date = currentDate.toString("dddd, MMMM d, yyyy");
    ui->timeLabel->setText(time);
    ui->dateLabel->setText(date);
}

void MainWindow::updateEmployeeList()
{

    empList = Employee::getEmployees();
    if(empList == NULL)
    {
        qDebug() << "Not valid";
        QMessageBox msg;
        msg.setWindowTitle("Error");
        msg.setInformativeText("Could not connect to employee database.\nExiting.");
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
        QApplication::quit();
    }
    int i;
    for (i = 0; i < empList->count(); i++)
    {
        QString name = QString("%0, %1").arg(empList->at(i)->lastname(), empList->at(i)->firstname());
        ui->employeeList->addItem(name);
    }
}

void MainWindow::dateTimer_Tick()
{
    updateTime();
}

void MainWindow::quitTimer_Tick()
{

}

void MainWindow::clock_Click()
{
    if(exiting)
    {
        qDebug() << "Exiting";
        close();
        return;
    }
    ClockForm *clockForm = new ClockForm(this);
    clockForm->exec();
}

void MainWindow::clock_Pressed()
{
    quitHoldTime = QDateTime::currentDateTime().toTime_t();
}

void MainWindow::clock_Released()
{
    uint msec = QDateTime::currentDateTime().toTime_t();
    if( msec - quitHoldTime > 5)
        exiting = true;
}
