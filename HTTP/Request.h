//
// Created by bulat on 18.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_HTTPREQUEST_H
#define HIGHLOAD_HTTP_SERVER_HTTPREQUEST_H

#include <cstring>
#include "Methods.h"
#include "Versions.h"
#include "URLPaths.h"

class Request {
public:
    Methods::Method method;
    URLPath *pURLPath;
    Versions::Version version;

    Request(char *pCharRequest);

    Request(Methods::Method method, URLPath *pURLPath, Versions::Version version);

    ~Request();
};

#endif //HIGHLOAD_HTTP_SERVER_HTTPREQUEST_H
