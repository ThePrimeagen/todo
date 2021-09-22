#include <string>
#include <map>

namespace Config {

using config_t = std::map<std::string, std::string>;
class Config {
    public:
    Config(int argc, char** argv);
    bool has_option(const std::string& str);

    private:
    config_t config;
};

}
