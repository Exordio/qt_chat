#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class QTcpSocket;

namespace SandZero {


class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_send_clicked();

    void on_connectbind_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket *mSocket;
};

} // end namespace SandZero
#endif // WIDGET_H
