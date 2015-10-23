//
// Created by bulat on 19.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_MIMETYPES_H
#define HIGHLOAD_HTTP_SERVER_MIMETYPES_H

#include <map>
#include <string>

#include "../FS/FileTypes.h"

class MIMETypes {
public:
    typedef std::map<FileTypes::FileType, std::string> MIMEType_t;
    static MIMEType_t map;

    static MIMETypes *Instance();

    static bool DeleteInstance();

private:
    static MIMETypes *self;

    MIMETypes();
};

#endif //HIGHLOAD_HTTP_SERVER_MIMETYPES_H
