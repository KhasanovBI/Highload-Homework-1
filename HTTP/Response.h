//
// Created by bulat on 18.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_HTTPRESPONSE_H
#define HIGHLOAD_HTTP_SERVER_HTTPRESPONSE_H

#include <linux/limits.h>
#include <unistd.h>
#include "Request.h"
#include "StatusCodes.h"

class Response {
public:
    StatusCodes::StatusCode statusCode;
    size_t contentLength;
    int dataFD;
    off_t dataSize;
    Response(Request *pRequest);
};

#endif //HIGHLOAD_HTTP_SERVER_HTTPRESPONSE_H