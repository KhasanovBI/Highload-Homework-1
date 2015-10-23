//
// Created by bulat on 03.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_CONFIGURATION_H
#define HIGHLOAD_HTTP_SERVER_CONFIGURATION_H

#include <getopt.h>
#include <iostream>
#include <libconfig.h++>
#include <string>

#include "../server/Buffer.h"

class Configuration {
public:
    Configuration(int argc, char *argv[], std::string filepath);

    const unsigned getPort();

    const unsigned getCPUCoresCount();

    const unsigned int getConnectionsMaxCount();

    static const char *getRootDirectory();

    static const unsigned getBufferSize();

    static const char *getDefaultPage();

    static const bool isDebugMessages();

private:
    std::string filepath;
    libconfig::Config config;
    static bool debugMessages;
    static unsigned bufferSize;
    unsigned connectionsMaxCount;
    unsigned CPUCoresCount;
    unsigned port;
    static const char *rootDirectory;
    static const char *defaultPage;

    void parseArgs(int argc, char **argv);

};

#endif //HIGHLOAD_HTTP_SERVER_CONFIGURATION_H
