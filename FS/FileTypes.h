//
// Created by bulat on 21.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_FILETYPES_H
#define HIGHLOAD_HTTP_SERVER_FILETYPES_H

#include <map>
#include <string>

#include "../FS/FileTypes.h"

class FileTypes {
public:
    enum FileType {
        html, css, js, jpg, jpeg, png, gif, swf, other
    };
    typedef std::map<FileType, std::string> FileType_t;
    static FileType_t map;

    static FileTypes *Instance();

    static bool DeleteInstance();

    static FileType getFileTypeFromPath(std::string &path);

private:
    static FileTypes *self;

    FileTypes();
};

#endif //HIGHLOAD_HTTP_SERVER_FILETYPES_H
