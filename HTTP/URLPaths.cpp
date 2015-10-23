//
// Created by bulat on 19.10.15.
//

#include "URLPaths.h"

void URLPath::decodeURL() {
    std::string decodedURLPath;
    char c;
    int ii;
    size_t i, length = pURLPath->length();
    for (i = 0; i < length; i++) {
        if ((*pURLPath)[i] != '%') {
            if ((*pURLPath)[i] == '+')
                decodedURLPath += ' ';
            else
                decodedURLPath += (*pURLPath)[i];
        } else {
            sscanf((*pURLPath).substr(i + 1, 2).c_str(), "%x", &ii);
            c = static_cast<char>(ii);
            decodedURLPath += c;
            i += 2;
        }
    }
    *pURLPath = decodedURLPath;
}

void URLPath::removeQueryString() {
    size_t position = pURLPath->find("?");
    if (position != std::string::npos) {
        *pURLPath = pURLPath->substr(0, position);
    }
}

URLPath::URLPath(char *pCharURLPath) {
    pURLPath = new std::string(pCharURLPath);
    removeQueryString();
    decodeURL();
}

URLPath::~URLPath() {
    delete pURLPath;
}

std::string URLPath::getURLPath() const {
    return *pURLPath;
}