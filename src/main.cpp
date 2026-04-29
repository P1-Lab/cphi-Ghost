#include <iostream>
#include <thread>
#include "service/ghost-daemon.h"

int main(int argc, char** argv) {
    std::cout << "--- cphi-Ghost Sovereign Terminal ---" << std::endl;
    std::cout << "Initializing System Service..." << std::endl;

    GhostDaemon daemon;

    if (!daemon.initialize()) {
        std::cerr << "Hardware Initialization Failed. Check GPIO permissions." << std::endl;
        return 1;
    }

    std::cout << "A=A. Ghost Protocol Active." << std::endl;

    // The daemon runs in its own thread to poll physical switches
    std::thread serviceThread(&GhostDaemon::run, &daemon);

    serviceThread.join();

    return 0;
}
