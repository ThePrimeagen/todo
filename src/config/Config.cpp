#include "Config.h"
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <map>
#include <cstdlib>
#include <sstream>

namespace Config {
namespace {
std::pair<std::string, std::string> config_value(std::string str) {

    std::istringstream ss(str);
    std::string token;
    std::pair<std::string, std::string> config_line;

    if (std::getline(ss, token, '=')) {
        config_line.first = token;
    }

    if (std::getline(ss, token, '=')) {
        config_line.second = token;
    }

    return config_line;
}

std::filesystem::path get_config_path() {
    // THERE IS NOTHING WRONG HERE
    std::filesystem::path home = std::getenv("HOME");
    std::filesystem::path xdg_config_path = std::getenv("XDG_CONFIG_HOME");
    xdg_config_path /= "todo";
    xdg_config_path /= "todo.conf";

    if (std::filesystem::exists(xdg_config_path)) {
        return xdg_config_path;
    }

    return home;
}

config_t get_config(std::filesystem::path path) {
    config_t config = {
        {"data_path", std::getenv("HOME")},
    };

    if (std::filesystem::exists(path)) {
        std::ifstream readStream(path);
        std::string line;

        while (std::getline(readStream, line)) {
            auto [key, value] = config_value(line);
            config[key] = value;
        }
    }

    return config;
}
}

Config::Config(int argc, char** argv) {
    // read user config
    config = get_config(get_config_path());

    // command line?  We will get there
    // todo --data_path=my/work/path
    for (int i = 0; i < argc; ++i) {
        std::string arg = argv[i];
    }
}

bool Config::has_option(const std::string& str) {
    return config.find(str) != config.end();
}

}
