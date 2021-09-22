#include <iostream>
#include "config/Config.h"

int main(int argc, char* argv[]) {
    std::cout << "First try" << std::endl;

    // We have to have a stored todo database
    //  - You should be able to point to it, or default in home directory
    //  - .config/todo/todo.conf | .todorc
    //  - todo.dat | conf.data_path
    Config config(argc - 1, argv + 1);
}
