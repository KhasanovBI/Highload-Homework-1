//
// Created by bulat on 03.10.15.
//

#include "Configuration.h"
#include "../server/Server.h"

int main() {
    Configuration *pConfiguration = new Configuration("settings.cfg");
    Server server(pConfiguration);
    server.start();
    delete pConfiguration;
    return 0;
}