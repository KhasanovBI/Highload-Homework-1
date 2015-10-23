//
// Created by bulat on 05.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_SERVER_H
#define HIGHLOAD_HTTP_SERVER_SERVER_H

#include <ev++.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/sendfile.h>
#include <unistd.h>

#include "Buffer.h"
#include "../main/Configuration.h"
#include "../HTTP/handlers.h"
#include "../HTTP/Methods.h"
#include "../HTTP/MIMETypes.h"
#include "../HTTP/Response.h"
#include "../HTTP/StatusCodes.h"
#include "../HTTP/Versions.h"

class Server {
public:
    Server(Configuration *pConfiguration);

    ~Server();

    void start();

private:
    Configuration *pConfiguration;
    uint16_t port;
    unsigned connectionsMaxCount;
    int _socket;
    int workersCount;
    ev::io ioWatcher;
    ev::sig sigintWatcher;
    ev::sig sigtermWatcher;

    void createWorkers();

    static void signalCallback(ev::sig &signal, int revents);

    static int totalClientsCount;

    void IOAcceptCallback(ev::io &watcher, int revents);

    void writeCallback(ev::io &watcher, int revents);

    void readCallback(ev::io &watcher, int revents);

    void instanciateStatics();

    void deleteStaticInstances();
};

#endif //HIGHLOAD_HTTP_SERVER_SERVER_H