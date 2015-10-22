//
// Created by bulat on 18.10.15.
//

#include "Buffer.h"

unsigned Buffer::bufferSize;

Buffer::Buffer(std::string headers, int dataFD, off_t dataSize) : headersPosition(0),
                                                                  dataFD(dataFD), dataOffset(NULL), dataSize(dataSize) {
    headersLength = headers.size();
    pCharHeaders = new char[headersLength];
    memcpy(pCharHeaders, headers.c_str(), headersLength);
}

Buffer::~Buffer() {
    delete[] pCharHeaders;
}

const unsigned int Buffer::getBufferSize() {
    return bufferSize;
}

char *Buffer::getPHeadersPosition() {
    return pCharHeaders + headersPosition;
}

size_t Buffer::getHeadersRemainBytes() {
    return headersLength - headersPosition;
}

size_t Buffer::getDataRemainBytes() {
    return dataSize - dataPosition;
}
