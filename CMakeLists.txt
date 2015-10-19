cmake_minimum_required(VERSION 3.2)
project(Highload_HTTP_Server)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main/main.cpp server/Buffer.cpp server/Buffer.h server/ClientInstance.cpp server/ClientInstance.h main/Configuration.cpp main/Configuration.h server/Server.cpp server/Server.h HTTP/Response.h HTTP/Request.h HTTP/Handler.cpp HTTP/Handler.cpp HTTP/Handler.h HTTP/MIMETypes.cpp HTTP/MIMETypes.h)
add_executable(Highload_HTTP_Server ${SOURCE_FILES})

find_package (Threads)
target_link_libraries (Highload_HTTP_Server ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries (Highload_HTTP_Server ev)
target_link_libraries (Highload_HTTP_Server config++)