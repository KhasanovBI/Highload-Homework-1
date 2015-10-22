//
// Created by bulat on 18.10.15.
//

#include "ClientInstance.h"

int ClientInstance::totalClientsCount = 0;

int ClientInstance::getTotalClientsCount() {
    return totalClientsCount;
}

void ClientInstance::routerCallback(ev::io &watcher, int revents) {
    if (revents & ev::ERROR) {
        perror("Got invalid event");
        return;
    }
    if (revents & ev::READ) {
        readCallback(watcher);
    }
    if (revents & ev::WRITE) {
        writeCallback(watcher);
    }
    if (writeQueue.empty()) {
        ioWatcher.set(ev::READ);
    } else {
        ioWatcher.set(ev::READ | ev::WRITE);
    }
}

void ClientInstance::writeCallback(ev::io &watcher) {
    if (writeQueue.empty()) {
        ioWatcher.set(ev::READ);
        return;
    }

    Buffer *pBuffer = writeQueue.front();

    size_t headersRemainBytes = pBuffer->getHeadersRemainBytes();
    if (headersRemainBytes > 0) {
        ssize_t writtenBytesCount = write(watcher.fd, pBuffer->getPHeadersPosition(), headersRemainBytes);
        if (writtenBytesCount < 0) {
            perror("Write error");
            return;
        }
        pBuffer->headersPosition += writtenBytesCount;
    } else if (pBuffer->dataFD != -1){
        ssize_t writtenBytesCount = sendfile(watcher.fd, pBuffer->dataFD, pBuffer->dataOffset, pBuffer->getDataRemainBytes());
        if (writtenBytesCount == -1) {
            perror("Sendfile error");
            return;
        } else {
            pBuffer->dataPosition += writtenBytesCount;
        }
    }

    if (pBuffer->getHeadersRemainBytes() == 0 && (pBuffer->dataFD == -1 || pBuffer->getDataRemainBytes() == 0)) {
        writeQueue.pop_front();
        delete pBuffer;
        delete this;
    }

}

void ClientInstance::readCallback(ev::io &watcher) {
    char buffer[Buffer::getBufferSize()];
    ssize_t readBytesCount = recv(watcher.fd, buffer, sizeof(buffer), 0);
    switch (readBytesCount) {
        case -1:
            perror("Read error");
            return;
        case 0:
            std::cout << "Socket closed: FD = " << watcher.fd << ", worker's PID = " << getpid() << std::endl;
            return;
        default:
            Response *pResponse = makeResponse(buffer);
            Buffer *pBuffer = new Buffer(pResponse->headers, pResponse->dataFD, pResponse->dataSize);
            writeQueue.push_back(pBuffer);
            delete pResponse;
            break;
    }
    return;
}

ClientInstance::ClientInstance(const int clientSocketDescriptor) : clientSocketDescriptor(clientSocketDescriptor) {
    std::cout << "Total " << ++totalClientsCount << " client(s) connected." << std::endl;
    bool flag = true;
    setsockopt(clientSocketDescriptor, SOL_SOCKET, SO_KEEPALIVE, &flag, sizeof(flag));
    fcntl(this->clientSocketDescriptor, F_SETFL, fcntl(this->clientSocketDescriptor, F_GETFL, 0) | O_NONBLOCK);
    ioWatcher.set<ClientInstance, &ClientInstance::routerCallback>(this);
    ioWatcher.start(this->clientSocketDescriptor, ev::READ);
}

ClientInstance::~ClientInstance() {
    ioWatcher.stop();
    close(clientSocketDescriptor);
    std::cout << "Total " << --totalClientsCount << " client(s) connected." << std::endl;
}
