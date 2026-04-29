#include "ghost-daemon.h"
#include <gpiod.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib> // For system() calls to PipeWire

// GPIO Pin Definitions for RK3588 (Mapping to docs/carrier-board-io.md)
const std::string CHIP_NAME = "gpiochip1"; 
const unsigned int PIN_VGL_U47 = 24;  // GPIO1_D0
const unsigned int PIN_VGL_4038 = 25; // GPIO1_D1
const unsigned int PIN_LOMO_DET = 26; // GPIO1_D2 (Hall Sensor)

bool GhostDaemon::initialize() {
    try {
        chip = gpiod::chip(CHIP_NAME);
        // Request pins as inputs with internal pull-up resistors
        u47_line = chip.get_line(PIN_VGL_U47);
        u47_line.request({"ghost-daemon", gpiod::line_request::DIRECTION_INPUT, gpiod::line_config::FLAGS_BIAS_PULL_UP});

        ribbon_line = chip.get_line(PIN_VGL_4038);
        ribbon_line.request({"ghost-daemon", gpiod::line_request::DIRECTION_INPUT, gpiod::line_config::FLAGS_BIAS_PULL_UP});

        lomo_line = chip.get_line(PIN_LOMO_DET);
        lomo_line.request({"ghost-daemon", gpiod::line_request::DIRECTION_INPUT, gpiod::line_config::FLAGS_BIAS_PULL_UP});

        return true;
    } catch (const std::exception& e) {
        std::cerr << "GPIO Error: " << e.what() << std::endl;
        return false;
    }
}

void GhostDaemon::run() {
    int last_mode = -1; // 0: Clinical, 1: U47, 2: 4038
    bool last_lomo = false;

    while (running) {
        // 1. Poll Audio Switches
        int current_mode = 0; // Default Clinical (A=A)
        if (u47_line.get_value() == 0) current_mode = 1;
        else if (ribbon_line.get_value() == 0) current_mode = 2;

        if (current_mode != last_mode) {
            updateAudioProfile(current_mode);
            last_mode = current_mode;
        }

        // 2. Poll Lomo Hall Sensor
        bool current_lomo = (lomo_line.get_value() == 0);
        if (current_lomo != last_lomo) {
            updateCameraProfile(current_lomo);
            last_lomo = current_lomo;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void GhostDaemon::updateAudioProfile(int mode) {
    switch(mode) {
        case 1:
            std::cout << "[VGL-1] Engaging U47 Profile (Silk/Tube)." << std::endl;
            system("pw-link -d raw_mic_source vgl1_sink && pw-link u47_node vgl1_sink"); 
            break;
        case 2:
            std::cout << "[VGL-1] Engaging 4038 Profile (Mass/Iron)." << std::endl;
            system("pw-link -d raw_mic_source vgl1_sink && pw-link ribbon_node vgl1_sink");
            break;
        default:
            std::cout << "[VGL-1] Returning to Clinical (A=A)." << std::endl;
            system("pw-link -d u47_node vgl1_sink && pw-link -d ribbon_node vgl1_sink && pw-link raw_mic_source vgl1_sink");
            break;
    }
}

void GhostDaemon::updateCameraProfile(bool engaged) {
    if (engaged) {
        std::cout << "[Lomo] Sled Detected. Activating LomoDSP Shaders." << std::endl;
        system("v4l2-ctl --set-ctrl=lomo_dsp_active=1");
    } else {
        std::cout << "[Lomo] Sled Disengaged. Restoring Raw Sensor Data." << std::endl;
        system("v4l2-ctl --set-ctrl=lomo_dsp_active=0");
    }
}
