//
// Created by bulat on 19.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_VERSIONS_H
#define HIGHLOAD_HTTP_SERVER_VERSIONS_H

#include <map>
#include <string>

class Versions {
public:
    enum Version {
        HTTP1_0, HTTP1_1, UNSUPPORTED
    };
    typedef std::map<Version, std::string> Version_t;
    static Version_t map;
private:
    static Versions *self;

    Versions();

public:
    static Versions *Instance();

    static bool DeleteInstance();

    static Version getVersionFromString(char *pCharVersion);
};


#endif //HIGHLOAD_HTTP_SERVER_VERSIONS_H
