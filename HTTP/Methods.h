//
// Created by bulat on 19.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_METHODS_H
#define HIGHLOAD_HTTP_SERVER_METHODS_H

#include <map>
#include <string>

class Methods {
public:
    enum Method {
        GET, HEAD, UNSUPPORTED
    };
    typedef std::map<Method, std::string> Method_t;
    static Method_t map;

    static Methods *Instance();

    static bool DeleteInstance();

    static Method getMethodFromString(char *pCharMethod);

private:
    static Methods *self;

    Methods();
};

#endif //HIGHLOAD_HTTP_SERVER_METHODS_H
