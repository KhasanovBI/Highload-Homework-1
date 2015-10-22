//
// Created by bulat on 19.10.15.
//

#include "paths.h"

std::string makeFilePath(Request *pRequest) {
    return std::string(Configuration::getRootDirectory()).append(pRequest->pURLPath->getURLPath());
}

void addDefaultPageToFilePath(std::string &filePath) {
    filePath.append("/").append(Configuration::getDefaultPage());
}