#ifndef CLOCKFORM_H
#define CLOCKFORM_H

#include <QDialog>

namespace Ui {
class ClockForm;
}

class ClockForm : public QDialog
{
    Q_OBJECT

public:
    explicit ClockForm(QWidget *parent = 0);
    ~ClockForm();

private:
    Ui::ClockForm *ui;
};

#endif // CLOCKFORM_H
