CC = g++
SOURCES = main/main.cpp server/Buffer.cpp server/Buffer.h server/ClientInstance.cpp server/ClientInstance.h main/Configuration.cpp main/Configuration.h server/Server.cpp server/Server.h
all:
	$(SOURCES) -o httpd
