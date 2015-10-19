//
// Created by bulat on 18.10.15.
//

#include "Buffer.h"

unsigned Buffer::bufferSize;

Buffer::Buffer(const char *bytes, size_t nbytes) {
    position = 0;
    length = nbytes;
    data = new char[nbytes];
    memcpy(data, bytes, nbytes);
}

Buffer::~Buffer() {
    delete[] data;
}

char *Buffer::dataPosition() {
    return data + position;
}

size_t Buffer::nbytes() {
    return length - position;
}

const unsigned int Buffer::getBufferSize() {
    return bufferSize;
}