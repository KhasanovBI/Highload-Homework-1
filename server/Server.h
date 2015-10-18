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

class Server {
    Configuration *configuration;
    uint16_t port;
    unsigned connectionsMaxCount;
    int _socket;
    int workersCount;
    ev::io ioWatcher;
    ev::sig sigintWatcher;
    ev::sig sigtermWatcher;

    void createWorkers();

    static void signal_cb(ev::sig &signal, int revents);

    void io_accept_cb(ev::io &watcher, int revents);

public:
    Server(Configuration *configuration);

    ~Server();

    void start();
};

#endif //HIGHLOAD_HTTP_SERVER_SERVER_H