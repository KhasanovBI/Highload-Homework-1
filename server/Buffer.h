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
    Buffer(std::string headers, int dataFD, off_t dataSize);

    static unsigned bufferSize;

    static const unsigned int getBufferSize();

    char *pCharHeaders;
    size_t headersLength;
    size_t headersPosition;

    char *getPHeadersPosition();

    size_t getHeadersRemainBytes();

    int dataFD;
    off_t dataSize;
    off_t *dataOffset;
    size_t dataPosition;

    size_t getDataRemainBytes();
};


#endif //HIGHLOAD_HTTP_SERVER_BUFFER_H
