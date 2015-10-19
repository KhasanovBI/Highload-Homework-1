//
// Created by bulat on 18.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_HTTPREQUEST_H
#define HIGHLOAD_HTTP_SERVER_HTTPREQUEST_H

#include <linux/limits.h>

class Request {
public:
    enum HTTPMethod {
        GET, HEAD, UNSUPPORTED
    };
    enum HTTPVersion {
        HTTP1_0, HTTP1_1
    };
    HTTPMethod method;
    char path[PATH_MAX + 1];
    HTTPVersion version;
};

#endif //HIGHLOAD_HTTP_SERVER_HTTPREQUEST_H
