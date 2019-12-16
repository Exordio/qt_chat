#include "EncMessangerSocket.h"

namespace SandZero
{
EncMessangerSocket::EncMessangerSocket(qintptr handle, QObject *parent) : QTcpSocket(parent)
{
    setSocketDescriptor(handle);


    connect(this, &EncMessangerSocket::readyRead, [&]() {
        emit EncReadyRead(this);
    });

    connect(this, &EncMessangerSocket::stateChanged, [&](int S){
       emit EncStateChanged(this, S);
    });


}
} // end namespace SandZero
