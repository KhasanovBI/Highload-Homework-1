//
// Created by bulat on 19.10.15.
//

#include "StatusCodes.h"
#include "utils.h"

StatusCodes *StatusCodes::self;
StatusCodes::StatusCode_t StatusCodes::map;

StatusCodes::StatusCodes() {
    mapInit(map)
            (_200, "200 OK")
            (_400, "400 Bad Request")
            (_403, "403 Forbidden")
            (_404, "404 Not Found")
            (_405, "405 Method Not Allowed");
}

StatusCodes *StatusCodes::Instance() {
    if (!self) {
        self = new StatusCodes();
    }
    return self;
}

bool StatusCodes::DeleteInstance() {
    if (self) {
        delete self;
        self = NULL;
        return true;
    }
    return false;
}

