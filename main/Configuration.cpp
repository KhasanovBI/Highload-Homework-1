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
        threadsCount = config.lookup("threads");
    } catch (const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "No 'name' setting in configuration file." << std::endl;
        exit(EXIT_FAILURE);
    }
}

unsigned Configuration::getPort() {
    return port;
}

unsigned Configuration::getThreadsCount() {
    return threadsCount;
}