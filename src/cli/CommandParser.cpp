#include <iostream>
#include <map>
#include <vector>
#include "CommandParser.h"
#include "../utils/Exceptions.h"
#include "commands/HelpCommand.h"
#include "commands/ListCommand.h"

void CommandParser::Parse(int argc, char** argv) {
    if (argc < 2) { throw utils::Exception("\n  No arguments were provided.\n  Please use '--help' or '-h' for more information.\n"); }
    std::vector<std::map<std::string, int>> args = {
        {
            {"--run", 1}, {"-r", 1},
            {"--help", 2}, {"-h", 2},
            {"--version", 3}, {"-v", 3},
            {"--list", 4}, {"-l", 4}
        }
    };

    auto arg = args.at(0).find(argv[1]);
    if (arg == args.at(0).end()) { throw utils::Exception("\n  dsa-sandbox: Unknown argument " + std::string(argv[1]) + " was provided.\n  Please use '--help' or '-h' for more information.\n"); }

    switch (arg->second) {
        case 1:
            std::cout << "\n  Run\n" << std::endl;
            break;
        case 2:
            cli::HelpCommand().Execute();
            break;
        case 3:
            std::cout << "\n  dsa-sandbox v0.1.0\n" << std::endl;
            break;
        case 4:
            cli::ListCommand().Execute();
            break;
        default:
            utils::Exception ex("\n  No valid argument was provided.\n  Please use '--help' or '-h' for more information.\n");
            throw ex;
    }
}   