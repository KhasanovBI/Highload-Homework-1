//
// Created by bulat on 18.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_HTTPRESPONSE_H
#define HIGHLOAD_HTTP_SERVER_HTTPRESPONSE_H

#include <fcntl.h>
#include <linux/limits.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../FS/FileTypes.h"
#include "../FS/paths.h"
#include "MIMETypes.h"
#include "Request.h"
#include "StatusCodes.h"

class Response {
public:
    Request *pRequest;
    StatusCodes::StatusCode statusCode;
    int dataFD;
    off_t dataSize;
    std::string headers;
    Versions::Version version;

    Response(Request *pRequest);
    ~Response();

private:
    void getVersion();

    std::string getStatusLine();

    const std::string getConnectionHeader();

    const std::string getContentLengthHeader();

    const std::string getDateHeader();

    const std::string getServerHeader();

    const std::string getContentTypeHeader(std::string filePath);
};

#endif //HIGHLOAD_HTTP_SERVER_HTTPRESPONSE_H