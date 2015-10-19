//
// Created by bulat on 19.10.15.
//


#include "Handler.h"
#include "MIMETypes.h"


Request *makeRequest(char *pCharRequest) {
    Request *pRequest = new Request();
    char *requestLine = strtok(pCharRequest, "\r\n");
    char *method = strtok(requestLine, " ");
    std::cout << method;

    return pRequest;
}



Response makeResponse(char* pCharRequest) {
    makeRequest(pCharRequest);
}