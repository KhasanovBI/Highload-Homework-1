//
// Created by bulat on 18.10.15.
//

#include "ClientInstance.h"
#include "../HTTP/handlers.h"


int ClientInstance::totalClientsCount = 0;
int ClientInstance::getTotalClientsCount() {
    return totalClientsCount;
}

ClientInstance::ClientInstance(const int clientSocketDescriptor) : clientSocketDescriptor(clientSocketDescriptor) {
    std::cout << "Total " << ++totalClientsCount << " client(s) connected." << std::endl;
    bool flag = true;
    setsockopt(clientSocketDescriptor, SOL_SOCKET, SO_KEEPALIVE, &flag, sizeof(flag));
    fcntl(this->clientSocketDescriptor, F_SETFL, fcntl(this->clientSocketDescriptor, F_GETFL, 0) | O_NONBLOCK);
    ioWatcher.set<ClientInstance, &ClientInstance::routerCallback>(this);
    ioWatcher.start(this->clientSocketDescriptor, ev::READ);
}

void ClientInstance::writeCallback(ev::io &watcher) {
    if (writeQueue.empty()) {
        ioWatcher.set(ev::READ);
        return;
    }

    Buffer* buffer = writeQueue.front();

    ssize_t written = write(watcher.fd, buffer->dataPosition(), buffer->nbytes());
    if (written < 0) {
        perror("read error");
        return;
    }

    buffer->position += written;
    if (buffer->nbytes() == 0) {
        writeQueue.pop_front();
        delete buffer;
    }
}

void ClientInstance::readCallback(ev::io &watcher) {
    char buffer[Buffer::getBufferSize()];
    ssize_t nread = recv(watcher.fd, buffer, sizeof(buffer), 0);
    switch (nread) {
        case -1:
            perror("Read error");
        case 0:
            std::cout << "Socket closed: FD = " << watcher.fd << ", worker's PID = " << getpid() << std::endl;
            delete this;
            return;
        default:
            writeQueue.push_back(new Buffer(buffer, nread));
            break;
    }
    Response *pResponse = makeResponse(buffer);
}

void ClientInstance::routerCallback(ev::io &watcher, int revents) {
    if (revents & EV_ERROR) {
        perror("Got invalid event");
        return;
    }

    if (revents & EV_READ) {
        readCallback(watcher);
    }
    if (revents & EV_WRITE) {
        writeCallback(watcher);
    }
    if (writeQueue.empty()) {
        ioWatcher.set(ev::READ);
    } else {
        ioWatcher.set(ev::READ | ev::WRITE);
    }
}

ClientInstance::~ClientInstance() {
    ioWatcher.stop();
    close(clientSocketDescriptor);
    std::cout << "Total " << --totalClientsCount << " client(s) connected." << std::endl;
}
