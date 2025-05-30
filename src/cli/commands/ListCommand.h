#pragma once

#include <iostream>
#include <filesystem>
#include <vector>
#include <algorithm>
#include "../../utils/Exceptions.h"

namespace cli {
    class ListCommand {
    private:
        std::vector<std::string> listFilesInDirectory(const std::filesystem::path& directory) {
            std::vector<std::string> files;
            try {
                for (const auto& entry : std::filesystem::directory_iterator(directory)) {
                    if (entry.is_regular_file() && entry.path().extension() == ".cpp") {
                        files.push_back(entry.path().filename().string());
                    }
                }
                std::sort(files.begin(), files.end());
            } catch (const std::filesystem::filesystem_error& e) {
                throw utils::Exception("\n  Could not access " + directory.string() + " - " + e.what() + "\n");
            }
            return files;
        }

        void printFileList(const std::string& category, const std::vector<std::string>& files) {
            std::cout << "\n  " << (files.empty() ? "[\033[31m-\033[0m]" : "[\033[32m+\033[0m]") << " " << category;
            if (!files.empty()) {
                std::cout << "\n";
                for (const auto& file : files) {
                    std::cout << "   :.. \033[36m" << file << "\033[0m\n";
                }
            } else {
                std::cout << "\n";
            }
        }

    public:
        void Execute() {
            const std::filesystem::path basePath = "D:/Project Repositories/dsa-sandbox/examples/";
            const std::filesystem::path algorithmsPath = basePath / "algorithms";
            const std::filesystem::path dataStructuresPath = basePath / "data-structures";

            std::vector<std::string> algorithms = listFilesInDirectory(algorithmsPath);
            printFileList("Algorithms", algorithms);

            std::vector<std::string> dataStructures = listFilesInDirectory(dataStructuresPath);
            printFileList("Data Structures", dataStructures);

            std::cout << std::endl;
        }
    };
}
