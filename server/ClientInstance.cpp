//
// Created by bulat on 05.10.15.
//


#include "ClientInstance.h"

int ClientInstance::totalClientsCount = 0;

ClientInstance::ClientInstance(const Configuration *configuration, const int clientSocketDescriptor)
        : clientSocketDescriptor(clientSocketDescriptor) {
    bool flag = true;
    setsockopt(clientSocketDescriptor, SOL_SOCKET, SO_KEEPALIVE, &flag, sizeof(flag));
    fcntl(this->clientSocketDescriptor, F_SETFL, fcntl(this->clientSocketDescriptor, F_GETFL, 0) | O_NONBLOCK);
    ioWatcher.set<ClientInstance, &ClientInstance::router_cb>(this);
    ioWatcher.start(this->clientSocketDescriptor, ev::READ);
}

void ClientInstance::write_cb(ev::io &watcher) {

}

int ClientInstance::getTotalClientsCount() {
    return totalClientsCount;
}

void ClientInstance::read_cb(ev::io &watcher) {

}

void ClientInstance::router_cb(ev::io &watcher, int revents) {
    if (revents & EV_ERROR) {
        perror("Got invalid event");
        return;
    }

    if (revents & EV_READ) {
        read_cb(watcher);
    }
    if (revents & EV_WRITE) {
        write_cb(watcher);
    }
    if (writeQueue.empty()) {
        ioWatcher.set(ev::READ);
    } else {
        ioWatcher.set(ev::READ | ev::WRITE);
    }
}
