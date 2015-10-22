//
// Created by bulat on 19.10.15.
//

#include "Methods.h"
#include "../main/utils.h"

Methods *Methods::self;
Methods::Method_t Methods::map;
Methods::Methods() {
    mapInit(map)
            (GET, "GET")
            (HEAD, "HEAD")
            (UNSUPPORTED, "Not Allowed");
}


Methods *Methods::Instance() {
    if (!self) {
        self = new Methods();
    }
    return self;
}

bool Methods::DeleteInstance() {
    if (self) {
        delete self;
        self = NULL;
        return true;
    }
    return false;
}

Methods::Method Methods::getMethodFromString(char *pCharMethod) {
    std::string stringMethod(pCharMethod);
    for (auto &it: map) {
        if (it.second.compare(stringMethod) == 0) {
            return it.first;
        }
    }
    return UNSUPPORTED;
}
