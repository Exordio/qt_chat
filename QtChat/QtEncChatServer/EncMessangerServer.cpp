#include "EncMessangerServer.h"
#include "EncMessangerSocket.h"
#include <QDebug>
#include <QTextStream>

namespace SandZero
{

EncMessangerServer::EncMessangerServer(QObject *parent)
    : QTcpServer(parent)
{

}

bool EncMessangerServer::startServer(quint16 port)
{
    return listen(QHostAddress::Any, port);
}

void EncMessangerServer::incomingConnection(qintptr handle)
{
    qDebug() << "Clent connected with handle:" << handle;
    auto socket = new EncMessangerSocket(handle, this);
    mSockets << socket;

    for(auto i : mSockets){
        QTextStream T(i);
        T << "Server: Connected: " << handle;
        i->flush();
    }

    connect(socket, &EncMessangerSocket::EncReadyRead, [&](EncMessangerSocket *S)
    {
        qDebug() << "EncReaduRead..";
        QTextStream T(S);
        auto text = T.readAll();

        for(auto i : mSockets) {
            QTextStream K(i);
            K << text;
            i->flush();
        }
    });

    connect(socket, &EncMessangerSocket::EncStateChanged,
            [&](EncMessangerSocket *S, int ST) {
        qDebug() << "EncStateChanged with handle:"
                 << S->socketDescriptor() ;
        if (ST == QTcpSocket::UnconnectedState) {
            qDebug() << "Unconnected state with handle:"
                     << S->socketDescriptor() ;
            mSockets.removeOne(S);
            for (auto i : mSockets) {
                QTextStream K(i);
                K << "Server : Client"
                  << S->socketDescriptor()
                  << "has been disconnect.";
                i->flush();
            }
        }
    });

}
} // end namespace SandZero
