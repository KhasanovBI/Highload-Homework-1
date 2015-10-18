//
// Created by bulat on 03.10.15.
//

#include "Configuration.h"

Configuration::Configuration(std::string filepath) : filepath(filepath) {
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
        port = config.lookup("port");
        CPUCoresCount = config.lookup("CPU_cores_count");
        connectionsMaxCount = config.lookup("connections_max_count");
        rootDirectory = config.lookup("root_directory");
    } catch (const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "Отсутствует параметр в конфигурационном файле." << std::endl;
        exit(EXIT_FAILURE);
    }
}

const unsigned int Configuration::getPort() {
    return port;
}

const unsigned int Configuration::getCPUCoresCount() {
    return CPUCoresCount;
}

unsigned Configuration::getConnectionsMaxCount() {
    return connectionsMaxCount;
}

const char* Configuration::getRootDirectory() const {
    return rootDirectory;
}
