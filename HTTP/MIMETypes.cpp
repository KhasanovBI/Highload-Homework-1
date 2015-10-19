//
// Created by bulat on 19.10.15.
//

#include "MIMETypes.h"

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

MIMETypes::MIMETypes() {
    MIMEType_t map;
    mapInit(map)
            (html, "text/html")
            (css, "text/css")
            (js, "application/javascript")
            (swf, "application/x-shockwave-flash")
            (gif, "image/gif")
            (jpeg, "image/jpeg")
            (jpg, "image/jpeg")
            (png, "image/png");
}
