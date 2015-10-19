//
// Created by bulat on 19.10.15.
//

#include "MIMETypes.h"
#include "utils.h"

MIMETypes *MIMETypes::self;
MIMETypes::MIMEType_t MIMETypes::map;
MIMETypes::MIMETypes() {
    mapInit(map)
            (html, "text/html")
            (css, "text/css")
            (js, "application/javascript")
            (swf, "application/x-shockwave-flash")
            (gif, "image/gif")
            (jpeg, "image/jpeg")
            (jpg, "image/jpeg")
            (png, "image/png")
            (other, "Not Allowed");
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