//
// Created by bulat on 20.10.15.
//

#include "Response.h"

Response::Response(Request *pRequest): dataSize(0), dataFD(-1) {
    this->pRequest = pRequest;
    getVersion();
    statusCode = (pRequest->method != Methods::UNSUPPORTED ? StatusCodes::_200 : StatusCodes::_405);
    if (pRequest->pURLPath->getURLPath().find("..") != std::string::npos) {
        statusCode = StatusCodes::_403;
    }
    std::string pURLPath = pRequest->pURLPath->getURLPath();
    if (pURLPath[0] != '/' || pURLPath.size() > PATH_MAX || pRequest->version == Versions::UNSUPPORTED) {
        statusCode = StatusCodes::_400;
    }
    std::string filePath = makeFilePath(pRequest);
    if (statusCode == StatusCodes::_200) {
        if (!access(filePath.c_str(), F_OK)) { /* Test for existence. Success = 0.  */
            if (filePath.back() == '/') {
                struct stat statStruct;
                int FD = open(filePath.c_str(), O_RDONLY);
                /* Get file attributes for the file that file descriptor FD is open on and put them in statStruct.  */
                fstat(FD, &statStruct);
                close(FD);
                if (S_ISDIR(statStruct.st_mode)) { /* st_mode - File mode.  */
                    addDefaultPageToFilePath(filePath);
                }
            }
            if (!access(filePath.c_str(), R_OK)) {
                struct stat statStruct;
                int FD = open(filePath.c_str(), O_RDONLY);
                fstat(FD, &statStruct);
                if (S_ISREG(statStruct.st_mode)) {
                    dataSize = statStruct.st_size;
                    switch (pRequest->method) {
                        case Methods::GET:
                            dataFD = FD;
                            break;
                        case Methods::HEAD:
                            close(FD);
                            break;
                        case Methods::UNSUPPORTED:
                            break;
                    }
                } else {
                    close(FD);
                    statusCode = StatusCodes::_404;
                }
            } else if (!access(filePath.c_str(), F_OK)) {
                statusCode = StatusCodes::_404;
            } else {
                statusCode = StatusCodes::_403;
            }
        } else {
            statusCode = StatusCodes::_404;
        }
    }
    headers = getStatusLine().append(getConnectionHeader());
    if (statusCode == StatusCodes::_200) {
        headers.append(getContentLengthHeader());
    }
    headers.append(getContentTypeHeader(filePath)).append(getDateHeader()).append(getServerHeader()).append("\r\n");
}

void Response::getVersion() {
    if (pRequest->version == Versions::HTTP1_1) {
        version = Versions::HTTP1_1;
    } else {
        version = Versions::HTTP1_0;
    }
}

std::string Response::getStatusLine() {
    return std::string(Versions::map[version]).append(" ").append(StatusCodes::map[statusCode]).append("\r\n");
}

const std::string Response::getConnectionHeader() {
    if (version == Versions::HTTP1_1) {
        return "Connection: keep-alive\r\n";
    }
    return "";
}

const std::string Response::getContentTypeHeader(std::string filePath) {
    return std::string("Content-Type: ").append(MIMETypes::map[FileTypes::getFileTypeFromPath(filePath)]).append(
            "\r\n");
}

const std::string Response::getContentLengthHeader() {
    return std::string("Content-Length: ").append(std::to_string(dataSize)).append("\r\n");
}

const std::string Response::getDateHeader() {
    std::string dateHeader("Date: ");
    time_t now = time(0);
    struct tm timeStruct = *gmtime(&now);
    char formatedDate[100];
    strftime(formatedDate, sizeof(formatedDate), "%a, %d %b %Y %H:%M:%S %Z\r\n", &timeStruct);
    return dateHeader.append(formatedDate);
}

const std::string Response::getServerHeader() {
    return "Server: Neutrino\r\n";
}

Response::~Response() {
    delete pRequest;
}
