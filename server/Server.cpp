//
// Created by bulat on 05.10.15.
//

#include "Server.h"

Server::Server(Configuration *pConfiguration) : pConfiguration(pConfiguration) {
    port = (uint16_t) pConfiguration->getPort();
    workersCount = pConfiguration->getCPUCoresCount() - 1;
    connectionsMaxCount = pConfiguration->getConnectionsMaxCount();
};

void Server::signalCallback(ev::sig &signal, int revents) {
    signal.loop.break_loop();
}

void Server::createWorkers() {
    __pid_t pid = 1;
    for (int i = 0; i < workersCount; ++i) {
        if (pid != 0) {
            pid = fork();
        }
    }
}

void Server::IOAcceptCallback(ev::io &watcher, int revents) {
    if (EV_ERROR & revents) {
        perror("Got invalid event");
        return;
    }

    sockaddr_in clientAddress;
    socklen_t clientLength = sizeof(clientAddress);

    int clientSocketDescriptor = accept(watcher.fd, (struct sockaddr *) &clientAddress, &clientLength);
    if (clientSocketDescriptor == -1) {
        perror("Accept error");
        return;
    }

    std::cout << "Client connected: socket descriptor = " << clientSocketDescriptor << ", worker PID = " << getpid() <<
    std::endl;
    new ClientInstance(clientSocketDescriptor);
}

void Server::instanciateStatics() {
    FileTypes::Instance();
    Methods::Instance();
    MIMETypes::Instance();
    StatusCodes::Instance();
    Versions::Instance();
}

void Server::deleteStaticInstances() {
    FileTypes::DeleteInstance();
    Methods::DeleteInstance();
    MIMETypes::DeleteInstance();
    StatusCodes::DeleteInstance();
    Versions::DeleteInstance();
}

void Server::start() {
    instanciateStatics();
    sockaddr_in socketAddress;
    socketAddress.sin_family = AF_INET; /* IP protocol family.  */
    socketAddress.sin_port = htons(port);
    socketAddress.sin_addr.s_addr = INADDR_ANY;
    _socket = socket(PF_INET, SOCK_STREAM,
                     0); /* SOCK_STREAM - Connectionless, unreliable datagrams of fixed maximum length.  */
    if (_socket == -1) {
        perror("Can't create socket");
    }

    bool flag = true;
    setsockopt(_socket, SOL_SOCKET, SO_REUSEADDR, (const void *) &flag, sizeof flag);

    /* F_GETFL, F_SETFL - Получить, установить флаги статуса файла, ассоциированного с дескриптором fildes соответственно.  */
    fcntl(_socket, F_SETFL, fcntl(_socket, F_GETFL, 0) | O_NONBLOCK);

    /* Give the socket FD the local address ADDR (which is LEN bytes long).  */
    if (bind(_socket, (const sockaddr *) &socketAddress, sizeof(socketAddress)) == -1) {
        perror("Bind error");
    }
    if (listen(_socket, connectionsMaxCount) == -1) {
        perror("Listen error");
    }
    // createWorkers();
    ev::default_loop loop;

    ioWatcher.set<Server, &Server::IOAcceptCallback>(this);
    ioWatcher.start(_socket, ev::READ);

    sigintWatcher.set<&Server::signalCallback>();
    sigintWatcher.start(SIGINT);

    sigtermWatcher.set<&Server::signalCallback>();
    sigtermWatcher.start(SIGTERM);

    loop.run(0);
}

Server::~Server() {
    /* SHUT_RDWR - No more receptions or transmissions.  */
    shutdown(_socket, SHUT_RDWR);
    close(_socket);
    deleteStaticInstances();
}
