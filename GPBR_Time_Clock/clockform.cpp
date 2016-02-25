#include "clockform.h"
#include "ui_clockform.h"

ClockForm::ClockForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClockForm)
{
    ui->setupUi(this);
}

ClockForm::~ClockForm()
{
    delete ui;
}
