//
// Created by bulat on 05.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_SERVER_H
#define HIGHLOAD_HTTP_SERVER_SERVER_H

#include <ev++.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include "ClientInstance.h"
#include "../main/Configuration.h"
#include "../HTTP/Methods.h"
#include "../HTTP/MIMETypes.h"
#include "../HTTP/StatusCodes.h"
#include "../HTTP/Versions.h"

class Server {
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

    void IOAcceptCallback(ev::io &watcher, int revents);

    void instanciateHTTP();

    void deleteInstancesHTTP();

public:
    Server(Configuration *pConfiguration);

    ~Server();

    void start();


};

#endif //HIGHLOAD_HTTP_SERVER_SERVER_H