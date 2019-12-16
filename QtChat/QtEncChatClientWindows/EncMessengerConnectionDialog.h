#ifndef ENCMESSENGERCONNECTIONDIALOG_H
#define ENCMESSENGERCONNECTIONDIALOG_H

#include <QDialog>

namespace Ui {
class EncMessengerConnectionDialog;
}

namespace SandZero {



class EncMessengerConnectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EncMessengerConnectionDialog(QWidget *parent = 0);
    ~EncMessengerConnectionDialog();
    QString hostname() const;
    quint16 port() const;

private slots:
    void on_Okbut_clicked();

    void on_Cancelbut_clicked();

private:
    Ui::EncMessengerConnectionDialog *ui;
    QString mHostname;
    quint16 mPort;
};

inline QString EncMessengerConnectionDialog::hostname() const
{
    return mHostname;
}

inline quint16 EncMessengerConnectionDialog::port() const
{
    return mPort;
}
} // end namespace SandZero

#endif // ENCMESSENGERCONNECTIONDIALOG_H
