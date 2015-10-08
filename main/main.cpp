//
// Created by bulat on 03.10.15.
//

#include <ev++.h>
#include "Configuration.h"

int main() {
    Configuration configuration("settings.cfg");

    unsigned port = configuration.getPort();
    unsigned threadsCount = configuration.getThreadsCount();

}