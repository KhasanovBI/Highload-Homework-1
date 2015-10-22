//
// Created by bulat on 20.10.15.

//

#include <iostream>
#include "Request.h"

Request::Request(Methods::Method method, URLPath *pURLPath, Versions::Version version) : method(method),
                                                                                         pURLPath(pURLPath),
                                                                                         version(version) { }

Request::Request(char *pCharRequest) {
    std::cout << pCharRequest << std::endl;
    char *pRequestLine = strtok(pCharRequest, "\r\n");
    char *pCharMethod = strtok(pRequestLine, " ");
    method = Methods::getMethodFromString(pCharMethod);
    char *pCharURLPath = strtok(NULL, " ");
    pURLPath = new URLPath(pCharURLPath);
    char* pCharVersion = strtok(NULL, " ");
    version = Versions::getVersionFromString(pCharVersion);
};

Request::~Request() {
    delete pURLPath;
}