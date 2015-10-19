//
// Created by bulat on 19.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_MIMETYPES_H
#define HIGHLOAD_HTTP_SERVER_MIMETYPES_H


#include <string>
#include <map>

class MIMETypes {
    static MIMETypes *self;
    MIMETypes();
    enum fileType {
        html, css, js, jpg, jpeg, png, gif, swf
    };
    typedef std::map<fileType, std::string> MIMEType_t;
    MIMEType_t map;
public:
    static MIMETypes* Instance()
    {
        if(!self)
        {
            self = new MIMETypes();
        }
        return self;
    }

    static bool DeleteInstance()
    {
        if(self)
        {
            delete self;
            self = NULL;
            return true;
        }
        return false;
    }
};
#endif //HIGHLOAD_HTTP_SERVER_MIMETYPES_H
