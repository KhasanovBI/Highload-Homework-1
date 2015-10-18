//
// Created by bulat on 05.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_SERVER_H
#define HIGHLOAD_HTTP_SERVER_SERVER_H

#include <ev++.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/socket.h>

#include "../main/Configuration.h"

class Server {
    Configuration *configuration;
    uint16_t port;
    int threadsCount;
    unsigned connectionsMaxCount;
    int _socket;
    ev::io stdin_watcher;
    ev::timer timeout_watcher;
public:
    Server(Configuration *configuration);

    void start();
};

#endif //HIGHLOAD_HTTP_SERVER_SERVER_H