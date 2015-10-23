//
// Created by bulat on 19.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_STATUSCODES_H
#define HIGHLOAD_HTTP_SERVER_STATUSCODES_H

#include <string>
#include <map>

#include "../main/utils.h"

class StatusCodes {
public:
    enum StatusCode {
        _200, _400, _403, _404, _405
    };
    typedef std::map<StatusCode, std::string> StatusCode_t;
    static StatusCode_t map;

    static StatusCodes *Instance();

    static bool DeleteInstance();

private:
    static StatusCodes *self;

    StatusCodes();
};


#endif //HIGHLOAD_HTTP_SERVER_STATUSCODES_H
