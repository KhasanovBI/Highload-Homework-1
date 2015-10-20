//
// Created by bulat on 19.10.15.
//

#ifndef HIGHLOAD_HTTP_SERVER_HANDLER_H
#define HIGHLOAD_HTTP_SERVER_HANDLER_H

#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include "Request.h"
#include "Response.h"

Request *makeRequest(char *pCharRequest);

Response *makeResponse(char *pCharRequest);

#endif //HIGHLOAD_HTTP_SERVER_HANDLER_H
