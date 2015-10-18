//
// Created by bulat on 05.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_SERVER_H
#define HIGHLOAD_HTTP_SERVER_SERVER_H

#include <ev++.h>
#include "../main/Configuration.h"

class Server {
    Configuration *configuration;
    int port;
    int threadsCount;
    ev_io stdin_watcher;
    ev_timer timeout_watcher;

    static void stdin_cb(EV_P_ ev_io *w, int revents);

    static void timeout_cb(EV_P_ ev_timer *w, int revents);

public:
    Server(Configuration *configuration);

    void start();
};

#endif //HIGHLOAD_HTTP_SERVER_SERVER_H