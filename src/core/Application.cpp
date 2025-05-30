#include <iostream>
#include "../cli/CommandParser.h"

int main(int argc, char** argv) {
    try {
        CommandParser parser;
        parser.Parse(argc, argv);
        return 0;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}
