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
    const char* rootDirectory;

public:
    Configuration(std::string filepath);

    const unsigned getPort();

    const unsigned getCPUCoresCount();

    unsigned int getConnectionsMaxCount();

    const char * getRootDirectory() const;
};


#endif //HIGHLOAD_HTTP_SERVER_CONFIGURATION_H
