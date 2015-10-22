//
// Created by bulat on 19.10.15.
//

#include "MIMETypes.h"
#include "../main/utils.h"

MIMETypes *MIMETypes::self;
MIMETypes::MIMEType_t MIMETypes::map;
MIMETypes::MIMETypes() {
    mapInit(map)
            (FileTypes::html, "text/html")
            (FileTypes::css, "text/css")
            (FileTypes::js, "application/javascript")
            (FileTypes::swf, "application/x-shockwave-flash")
            (FileTypes::gif, "image/gif")
            (FileTypes::jpeg, "image/jpeg")
            (FileTypes::jpg, "image/jpeg")
            (FileTypes::png, "image/png")
            (FileTypes::other, "text/plain");
}

MIMETypes *MIMETypes::Instance() {
    if (!self) {
        self = new MIMETypes();
    }
    return self;
}

bool MIMETypes::DeleteInstance() {
    if (self) {
        delete self;
        self = NULL;
        return true;
    }
    return false;
}