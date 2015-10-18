//
// Created by bulat on 05.10.15.
//

#include "Server.h"



Server::Server(Configuration *configuration) : configuration(configuration) {
    port = (uint16_t) configuration->getPort();
    threadsCount = configuration->getThreadsCount();
    connectionsMaxCount = configuration->getConnectionsMaxCount();
};


void Server::start() {
    ev::default_loop loop;
    _socket = socket(PF_INET, SOCK_STREAM, 0); /* SOCK_STREAM - Connectionless, unreliable datagrams of fixed maximum length.  */
    sockaddr_in socketAddress;
    socketAddress.sin_family = AF_INET; /* IP protocol family.  */
    socketAddress.sin_port = htons(port);
    socketAddress.sin_addr.s_addr = INADDR_ANY;
    /* Give the socket FD the local address ADDR (which is LEN bytes long).  */
    if (bind(_socket, (const sockaddr *) &socketAddress, sizeof(socketAddress)) != 0) {
        perror("Bind error.\n");
    }
    if (listen(_socket, connectionsMaxCount) == -1) {
        perror("Listen error\n");
    }
    bool flag = true;
    setsockopt(_socket, SOL_SOCKET, SO_REUSEADDR, (const void *) &flag, sizeof flag);
    /* F_GETFL, F_SETFL - Получить, установить флаги статуса файла, ассоциированного с дескриптором fildes соответственно.  */
    fcntl(_socket, F_SETFL, fcntl(_socket, F_GETFL, 0) | O_NONBLOCK);





    loop.run(0);
}