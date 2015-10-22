//
// Created by bulat on 18.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_CLIENTINSTANCE_H
#define HIGHLOAD_HTTP_SERVER_CLIENTINSTANCE_H

#include <fcntl.h>
#include <sys/socket.h>
#include <sys/sendfile.h>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <ev++.h>
#include <list>
#include "Buffer.h"
#include "../HTTP/handlers.h"
#include "../main/Configuration.h"

class ClientInstance {
    const int clientSocketDescriptor;
    static int totalClientsCount;
    ev::io ioWatcher;

    void routerCallback(ev::io &watcher, int revents);

    void readCallback(ev::io &watcher);

    void writeCallback(ev::io &watcher);

    // Buffers that are pending write
    std::list<Buffer *> writeQueue;
public:
    static int getTotalClientsCount();

    ClientInstance(const int i);

    ~ClientInstance();
};


#endif //HIGHLOAD_HTTP_SERVER_CLIENTINSTANCE_H
