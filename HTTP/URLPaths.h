//
// Created by bulat on 19.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_URLPATH_H
#define HIGHLOAD_HTTP_SERVER_URLPATH_H

#include <string>
#include <stdio.h>

class URLPath {
private:
    std::string *pURLPath;

    void decodeURL();

public:
    URLPath(char *pCharURLPath);

    ~URLPath();

    std::string getURLPath() const;
};

#endif //HIGHLOAD_HTTP_SERVER_URLPATH_H
