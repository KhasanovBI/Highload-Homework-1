//
// Created by bulat on 19.10.15.
//

#include "handlers.h"

Request *makeRequest(char *pCharRequest) {
    return new Request(pCharRequest);
}

Response *makeResponse(char *pCharRequest) {
    Request *pRequest = makeRequest(pCharRequest);
}