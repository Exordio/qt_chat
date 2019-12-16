#include "EncMessengerConnectionDialog.h"
#include "ui_EncMessengerConnectionDialog.h"

namespace SandZero {


EncMessengerConnectionDialog::EncMessengerConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EncMessengerConnectionDialog)
{
    ui->setupUi(this);
}

EncMessengerConnectionDialog::~EncMessengerConnectionDialog()
{
    delete ui;
}



void EncMessengerConnectionDialog::on_Okbut_clicked()
{
    mHostname = ui->Hostname->text();
    mPort = ui->port->value();
    accept();
}

void EncMessengerConnectionDialog::on_Cancelbut_clicked()
{
    reject();
}
} // end namespace SandZero
