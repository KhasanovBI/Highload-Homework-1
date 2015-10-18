//
// Created by bulat on 18.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_BUFFER_H
#define HIGHLOAD_HTTP_SERVER_BUFFER_H


class Buffer {
public:
    char *data;
    size_t length;
    size_t position;

    Buffer(const char *bytes, size_t nbytes);

    ~Buffer();

    size_t nbytes();

    char* dataPosition();
};


#endif //HIGHLOAD_HTTP_SERVER_BUFFER_H
