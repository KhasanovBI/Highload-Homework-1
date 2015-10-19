//
// Created by bulat on 18.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_HTTPRESPONSE_H
#define HIGHLOAD_HTTP_SERVER_HTTPRESPONSE_H

#include <unistd.h>

class Response {
public:
    unsigned statusCode;
    int dataFD;
    off_t dataSize;
};

#endif //HIGHLOAD_HTTP_SERVER_HTTPRESPONSE_H
