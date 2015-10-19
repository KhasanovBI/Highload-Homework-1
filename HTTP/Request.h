//
// Created by bulat on 18.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_HTTPREQUEST_H
#define HIGHLOAD_HTTP_SERVER_HTTPREQUEST_H

#include <linux/limits.h>
#include "Methods.h"
#include "Versions.h"

class Request {
public:
    Methods::Method method;
    std::string path[PATH_MAX + 1];
    Versions::Version version;
};

#endif //HIGHLOAD_HTTP_SERVER_HTTPREQUEST_H
