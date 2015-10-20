//
// Created by bulat on 19.10.15.
//

#include "headers.h"

std::string getVersion(Request *pRequest) {
    return Versions::map[pRequest->version];
}

std::string getStatusLine(Request *pRequest, Response *pResponse) {
    return getVersion(pRequest) + " " + StatusCodes::map[pResponse->statusCode] + "\r\n";
}

std::string getConnectionHeader(Request request) {
    if (request.version == Versions::HTTP1_1) {
        return "Connection: keep-alive\r\n";
    }
    return "";
}

std::string getContentTypeHeader(FileType fileType) {
    return "Content-Type: " + MIMETypes::map[fileType] + "\r\n";
}

std::string getDateHeader() {
    std::string dateHeader("Date: ");
    time_t now = time(0);
    struct tm timeStruct = *gmtime(&now);
    char buf[100];
    strftime(buf, sizeof(buf), "%a, %d %b %Y %H:%M:%S %Z\r\n", &timeStruct);
    return dateHeader + buf;
}

std::string getServerHeader(Request request) {
    return std::string("Server: ") + Configuration::getServerName() + "\r\n";
}