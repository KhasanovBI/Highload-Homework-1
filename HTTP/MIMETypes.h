//
// Created by bulat on 19.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_MIMETYPES_H
#define HIGHLOAD_HTTP_SERVER_MIMETYPES_H

#include <string>
#include <map>

class MIMETypes {
public:
    enum fileType {
        html, css, js, jpg, jpeg, png, gif, swf, other
    };
    typedef std::map<fileType, std::string> MIMEType_t;
    static MIMEType_t map;
private:
    static MIMETypes *self;

    MIMETypes();

public:
    static bool DeleteInstance();

    static MIMETypes *Instance();
};

#endif //HIGHLOAD_HTTP_SERVER_MIMETYPES_H
