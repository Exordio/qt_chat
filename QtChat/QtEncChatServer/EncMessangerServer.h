#ifndef ENCMESSANGERSERVER_H
#define ENCMESSANGERSERVER_H

#include <QTcpServer>

namespace SandZero
{

class EncMessangerSocket;

class EncMessangerServer : public QTcpServer
{
public:
    EncMessangerServer(QObject *parent = nullptr);
    bool startServer(quint16 port);
protected:
    void incomingConnection(qintptr handle);
private:
    QList<EncMessangerSocket *> mSockets;

};
} // end namespace SandZero

#endif // ENCMESSANGERSERVER_H
