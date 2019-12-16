#include "widget.h"
#include "ui_widget.h"
#include "EncMessengerConnectionDialog.h"
#include <QTcpSocket>

namespace SandZero {


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("EncChat, Prod by sandborn V0.1");
    mSocket = new QTcpSocket(this);
    connect(mSocket, &QTcpSocket::readyRead, [&]() {
        QTextStream T(mSocket);
        auto text = T.readAll();
        ui->textEdit->append(text);
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_send_clicked()
{
    QTextStream T(mSocket);
    T << ui->Nickname->text() << ": " << ui->Message->text();
    mSocket->flush();
    ui->Message->clear();
}

void Widget::on_connectbind_clicked()
{
    EncMessengerConnectionDialog D(this);
    if(D.exec() == QDialog::Rejected){
        return;
    }
    mSocket->connectToHost(D.hostname(),D.port());



}
} // end namespace SandZero
