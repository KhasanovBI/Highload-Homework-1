CXX = g++
CFLAGS = -std=c++11
LFLAGS = -lconfig++ -lev
TARGET = httpd

FS = FS/FileTypes.cpp FS/FileTypes.h FS/paths.cpp FS/paths.h
HTTP = HTTP/handlers.cpp HTTP/handlers.h HTTP/Methods.cpp HTTP/Methods.h HTTP/MIMETypes.cpp HTTP/MIMETypes.h HTTP/Request.cpp HTTP/Request.h HTTP/Response.cpp HTTP/Response.h HTTP/StatusCodes.cpp HTTP/StatusCodes.h HTTP/URLPaths.cpp HTTP/URLPaths.h HTTP/Versions.cpp HTTP/Versions.h
main = main/Configuration.cpp main/Configuration.h main/main.cpp main/utils.h
server = server/Buffer.cpp server/Buffer.h server/Server.cpp server/Server.h
SOURCES = $(FS) $(HTTP) $(main) $(server)

all:
	$(CXX) $(CFLAGS) $(SOURCES) -o $(TARGET) $(LFLAGS)
