//
// Created by bulat on 03.10.15.
//

#include "Configuration.h"
#include "../server/Server.h"

int main() {
    Configuration *configuration = new Configuration("settings.cfg");
    Server server(configuration);
    server.start();
    delete configuration;
    return 0;
}