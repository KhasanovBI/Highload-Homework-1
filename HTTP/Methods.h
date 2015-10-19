//
// Created by bulat on 19.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_METHODS_H
#define HIGHLOAD_HTTP_SERVER_METHODS_H

#include <string>
#include <map>
#include <string.h>

class Methods {
public:
    enum Method {
        GET, HEAD, UNSUPPORTED
    };
    typedef std::map<Method, std::string> Method_t;
    static Method_t map;
private:
    static Methods *self;

    Methods();

public:
    static bool DeleteInstance();

    static Method getMethodFromString(char *pCharMethod);

    static Methods *Instance();
};

#endif //HIGHLOAD_HTTP_SERVER_METHODS_H
