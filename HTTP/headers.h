//
// Created by bulat on 19.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_HEADERS_H
#define HIGHLOAD_HTTP_SERVER_HEADERS_H

#include <ctime>

#include "../main/Configuration.h"
#include "MIMETypes.h"
#include "Request.h"
#include "Response.h"
#include "StatusCodes.h"

std::string getStatusLine(Request *request, Response *response);

std::string getConnectionHeader(Request request);

std::string getContentTypeHeader(FileType fileType);

std::string getDateHeader();

std::string getServerHeader(Request request);

#endif //HIGHLOAD_HTTP_SERVER_HEADERS_H
