//
// Created by bulat on 19.10.15.
//


#include "handler.h"

Methods::Method_t Methods::map;
Request *makeRequest(char *pCharRequest) {
    Request *pRequest = new Request();
    char *requestLine = strtok(pCharRequest, "\r\n");
    char *method = strtok(requestLine, " ");
    pRequest->method = Methods::getMethodFromString(method);
    std::cout << Methods::map[pRequest->method]<< std::endl;
    //pRequest->path = ;
    return pRequest;
}


Response makeResponse(char *pCharRequest) {
    makeRequest(pCharRequest);

}