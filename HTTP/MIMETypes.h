//
// Created by bulat on 19.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_MIMETYPES_H
#define HIGHLOAD_HTTP_SERVER_MIMETYPES_H

#include <map>
#include <string>
#include "../FS/fileTypes.h"

class MIMETypes {
public:
    typedef std::map<FileType, std::string> MIMEType_t;
    static MIMEType_t map;
private:
    static MIMETypes *self;

    MIMETypes();

public:
    static bool DeleteInstance();

    static MIMETypes *Instance();
};

#endif //HIGHLOAD_HTTP_SERVER_MIMETYPES_H
