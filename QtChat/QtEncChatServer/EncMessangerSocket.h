#ifndef ENCMESSANGERSOCKET_H
#define ENCMESSANGERSOCKET_H

#include <QTcpSocket>


namespace SandZero
{
class EncMessangerSocket : public QTcpSocket
{
    Q_OBJECT
public:
    EncMessangerSocket(qintptr handle, QObject *parent = nullptr);
signals:
    void EncReadyRead(EncMessangerSocket *);
    void EncStateChanged(EncMessangerSocket *, int);
};
}// end namespace SandZero

#endif // ENCMESSANGERSOCKET_H
