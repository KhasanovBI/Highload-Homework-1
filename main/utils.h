//
// Created by bulat on 19.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_UTILS_H
#define HIGHLOAD_HTTP_SERVER_UTILS_H

template<typename T>
struct mapInitHelper {
    T &mapping;

    mapInitHelper(T &d) : mapping(d) { }

    mapInitHelper &operator()(typename T::key_type const &key, typename T::mapped_type const &value) {
        mapping[key] = value;
        return *this;
    }
};

template<typename T>
mapInitHelper<T> mapInit(T &item) {
    return mapInitHelper<T>(item);
}

#endif //HIGHLOAD_HTTP_SERVER_UTILS_H
