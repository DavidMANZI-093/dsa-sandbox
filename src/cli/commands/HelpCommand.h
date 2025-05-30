#pragma once

#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include "../../utils/Exceptions.h"

namespace cli {
    class HelpCommand {
    public:
        void Execute() {
            std::filesystem::path helpPath = std::filesystem::absolute("D:/Project Repositories/dsa-sandbox/docs/help.txt");

            std::ifstream helpFile(helpPath);
            if (helpFile.is_open()) {
                std::stringstream buffer;
                buffer << helpFile.rdbuf();
                std::cout << "\n" << buffer.str() << "\n" << std::endl;
            } else {
                throw utils::Exception("\n  Could not open help file at: " + helpPath.string() + "\n");
            }
        }
    };
}
