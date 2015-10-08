//
// Created by bulat on 03.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_CONFIGURATION_H
#define HIGHLOAD_HTTP_SERVER_CONFIGURATION_H

#include "string"
#include <iostream>
#include <libconfig.h++>

class Configuration {
    std::string filepath;
    libconfig::Config config;
    unsigned port;
    unsigned threadsCount;
public:
    Configuration(std::string filepath);
    unsigned getPort();
    unsigned getThreadsCount();
};


#endif //HIGHLOAD_HTTP_SERVER_CONFIGURATION_H
