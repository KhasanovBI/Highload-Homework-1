//
// Created by bulat on 18.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_BUFFER_H
#define HIGHLOAD_HTTP_SERVER_BUFFER_H

#include <stddef.h>
#include <string.h>
#include "../main/Configuration.h"

class Buffer {
public:
    static const unsigned bufferSize;
    char *data;
    size_t length;
    size_t position;

    Buffer(const char *bytes, size_t nbytes);

    ~Buffer();

    size_t nbytes();

    char *dataPosition();

    static const unsigned int getBufferSize();
};


#endif //HIGHLOAD_HTTP_SERVER_BUFFER_H
