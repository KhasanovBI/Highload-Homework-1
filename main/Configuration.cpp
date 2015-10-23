//
// Created by bulat on 03.10.15.
//

#include "Configuration.h"

unsigned Configuration::bufferSize;
const char *Configuration::defaultPage;
const char *Configuration::rootDirectory;
bool Configuration::debugMessages;

Configuration::Configuration(int argc, char *argv[], std::string filepath) : filepath(filepath) {
    try {
        config.readFile("settings.cfg");
    } catch (const libconfig::FileIOException) {
        std::cerr << "Невозможно найти конфигурационный файл." << std::endl;
        exit(EXIT_FAILURE);
    } catch (const libconfig::ParseException &parseException) {
        std::cerr << "Ошибка конфигурации " << parseException.getFile() << ":" << parseException.getLine() << " - " <<
        parseException.getError() << std::endl;
        exit(EXIT_FAILURE);
    }
    try {
        bufferSize = config.lookup("buffer_size");
        connectionsMaxCount = config.lookup("connections_max_count");
        CPUCoresCount = config.lookup("CPU_cores_count");
        defaultPage = config.lookup("default_page");
        debugMessages = config.lookup("debug_messages");
        port = config.lookup("port");
        rootDirectory = config.lookup("root_directory");
    } catch (const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "Отсутствует параметр в конфигурационном файле." << std::endl;
        exit(EXIT_FAILURE);
    }
    Buffer::bufferSize = bufferSize;
    parseArgs(argc, argv);
}

void Configuration::parseArgs(int argc, char **argv) {
    int c;
    while ((c = getopt(argc, argv, "r:c:")) != -1) {
        switch (c) {
            case 'r':
                rootDirectory = optarg;
                break;
            case 'c':
                CPUCoresCount = (unsigned int) atoi(optarg);
                break;
            default:
                break;
        }
    }
}

const unsigned int Configuration::getPort() {
    return port;
}

const unsigned int Configuration::getCPUCoresCount() {
    return CPUCoresCount;
}

const unsigned Configuration::getConnectionsMaxCount() {
    return connectionsMaxCount;
}

const char *Configuration::getRootDirectory() {
    return rootDirectory;
}

const unsigned Configuration::getBufferSize() {
    return bufferSize;
}

const char *Configuration::getDefaultPage() {
    return defaultPage;
}

const bool Configuration::isDebugMessages() {
    return debugMessages;
}