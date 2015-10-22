//
// Created by bulat on 19.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_PATH_H
#define HIGHLOAD_HTTP_SERVER_PATH_H

#include <string>
#include "../HTTP/Request.h"
#include "../main/Configuration.h"

std::string makeFilePath(Request *pRequest);

void addDefaultPageToFilePath(std::string &filePath);

#endif //HIGHLOAD_HTTP_SERVER_PATH_H
