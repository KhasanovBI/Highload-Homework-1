//
// Created by bulat on 21.10.15.
//

#include "FileTypes.h"
#include "../main/utils.h"

FileTypes *FileTypes::self;
FileTypes::FileType_t FileTypes::map;
FileTypes::FileTypes() {
    mapInit(map)
            (html, "html")
            (css, "css")
            (js, "js")
            (swf, "swf")
            (gif, "gif")
            (jpeg, "jpeg")
            (jpg, "jpg")
            (png, "png")
            (other, "");
}

FileTypes *FileTypes::Instance() {
    if (!self) {
        self = new FileTypes();
    }
    return self;
}

bool FileTypes::DeleteInstance() {
    if (self) {
        delete self;
        self = NULL;
        return true;
    }
    return false;
}

FileTypes::FileType FileTypes::getFileTypeFromPath(std::string &path) {
    size_t dotPosition = path.rfind('.');
    if (dotPosition != std::string::npos) {
        std::string fileType = path.substr(dotPosition + 1);
        for (auto &it: map) {
            if (it.second.compare(fileType) == 0) {
                return it.first;
            }
        }
    }
    return other;
}