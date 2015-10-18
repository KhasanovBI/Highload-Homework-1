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
    const char *rootDirectory;
    static unsigned bufferSize;
public:
    Configuration(std::string filepath);

    const unsigned getPort();

    const unsigned getCPUCoresCount();

    const unsigned int getConnectionsMaxCount();

    const char *getRootDirectory() const;

    static const unsigned getBufferSize();
};


#endif //HIGHLOAD_HTTP_SERVER_CONFIGURATION_H
