//
// Created by bulat on 19.10.15.
//

#include "headers.h"
#include "Request.h"
#include "../main/Configuration.h"
#include "Response.h"

std::string getVersion(Request request) {
    return Versions::map[request.version];
}

std::string getContentTypeHeader(MIMETypes::fileType type) {
    return "Content-Type: " + MIMETypes::map[type] + "\r\n";
}

std::string getConnectionHeader(Request request) {
    if (request.version == Versions::HTTP1_1) {
        return "Connection: keep-alive\r\n";
    }
    return "";
}

std::string getStatusLine(Request request, Response response) { //TODO
    return getVersion(request) + " ";
}

std::string getServerHeader(Request request) {
    return std::string("Server: ") + Configuration::getServerName();
}