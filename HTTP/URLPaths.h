//
// Created by bulat on 19.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_URLPATH_H
#define HIGHLOAD_HTTP_SERVER_URLPATH_H

#include <string>
#include <cstdio>

class URLPath {
public:
    URLPath(char *pCharURLPath);

    ~URLPath();

    std::string getURLPath() const;

private:
    std::string *pURLPath;

    void decodeURL();

    void removeQueryString();
};

#endif //HIGHLOAD_HTTP_SERVER_URLPATH_H
