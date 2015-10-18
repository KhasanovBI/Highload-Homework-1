//
// Created by bulat on 05.10.15.
//

#include "Server.h"

Server::Server(Configuration *configuration) : configuration(configuration) {
    port = configuration->getPort();
    threadsCount = configuration->getThreadsCount();
};

void Server::stdin_cb(EV_P_ ev_io *w, int revents) {
    std::cout << "stdin ready";
    // for one-shot events, one must manually stop the watcher
    // with its corresponding stop function.
    ev_io_stop(EV_A_ w);

    // this causes all nested ev_run's to stop iterating
    ev_break(EV_A_ EVBREAK_ALL);
}

void Server::timeout_cb(EV_P_ ev_timer *w, int revents) {
    puts("timeout");
    // this causes the innermost ev_run to stop iterating
    ev_break(EV_A_ EVBREAK_ONE);
}

void Server::start() {
    // use the default event loop unless you have special needs
    struct ev_loop *loop = EV_DEFAULT;
    // initialise an io watcher, then start it
    // this one will watch for stdin to become readable
    ev_io_init (&stdin_watcher, stdin_cb, /*STDIN_FILENO*/ 0, EV_READ);
    ev_io_start(loop, &stdin_watcher);
    // initialise a timer watcher, then start it
    // simple non-repeating 5.5 second timeout
    ev_timer_init (&timeout_watcher, timeout_cb, 5.5, 0.);
    ev_timer_start(loop, &timeout_watcher);
    // now wait for events to arrive
    ev_run(loop, 0);
}