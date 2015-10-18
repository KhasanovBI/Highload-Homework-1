//
// Created by bulat on 18.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_CLIENTINSTANCE_H
#define HIGHLOAD_HTTP_SERVER_CLIENTINSTANCE_H

#include <fcntl.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ev++.h>
#include <list>
#include "Buffer.h"
#include "../main/Configuration.h"

class ClientInstance {
    int clientSocketDescriptor;
    Configuration *configuration;
    static int totalClientsCount;
    ev::io ioWatcher;
    void router_cb(ev::io &watcher, int revents);
    void read_cb(ev::io &watcher);
    // Buffers that are pending write
    std::list<Buffer*> writeQueue;
public:
    static int getTotalClientsCount();

    void write_cb(ev::io &watcher);

    ClientInstance(const Configuration *configuration, const int i);
};


#endif //HIGHLOAD_HTTP_SERVER_CLIENTINSTANCE_H
