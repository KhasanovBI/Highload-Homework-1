//
// Created by bulat on 20.10.15.
//

#include "Response.h"
#include "headers.h"

Response::Response(Request *pRequest) {
    statusCode = (pRequest->method != Methods::UNSUPPORTED ? StatusCodes::_200 : StatusCodes::_405);
    if (pRequest->pURLPath->getURLPath().find("..")) {
        statusCode = StatusCodes::_403;
    }
    std::string pURLPath = pRequest->pURLPath->getURLPath();
    if (pURLPath[0] != '/' || pURLPath.size() > PATH_MAX || pRequest->version == Versions::UNSUPPORTED) {
        statusCode = StatusCodes::_400;
    }
    dataFD = -1;
    std::string responseHeadersBlock;
    if (statusCode != StatusCodes::_200) {
        responseHeadersBlock += getStatusLine(pRequest, this);
    }

}
