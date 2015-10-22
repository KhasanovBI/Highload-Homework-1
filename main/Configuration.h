//
// Created by bulat on 03.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_CONFIGURATION_H
#define HIGHLOAD_HTTP_SERVER_CONFIGURATION_H


#include <iostream>
#include <libconfig.h++>
#include <string>

class Configuration {
    std::string filepath;
    libconfig::Config config;
    unsigned port;
    unsigned CPUCoresCount;
    unsigned connectionsMaxCount;
    static const char *rootDirectory;
    static unsigned bufferSize;
    static const char* serverName;
    static const char* defaultPage;
public:
    Configuration(std::string filepath);

    const unsigned getPort();

    const unsigned getCPUCoresCount();

    const unsigned int getConnectionsMaxCount();

    static const char *getRootDirectory();

    static const unsigned getBufferSize();

    static const char * getDefaultPage();

    static const char* getServerName();


};


#endif //HIGHLOAD_HTTP_SERVER_CONFIGURATION_H
