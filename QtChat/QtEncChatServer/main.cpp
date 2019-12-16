#include <QCoreApplication>
#include <EncMessangerServer.h>

using namespace SandZero;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    EncMessangerServer Server;
    if (!Server.startServer(3333)){

        qDebug() << "Error : " << Server.errorString();
        return 1;
    }
    qDebug() << "Server has been started...";

        return a.exec();
}
