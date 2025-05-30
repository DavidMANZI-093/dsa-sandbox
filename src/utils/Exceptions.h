#pragma once

#include <string>
#include <stdexcept>

namespace utils {
    class Exception : public std::runtime_error {
    public:
        explicit Exception(const std::string& message) : std::runtime_error(message) {}
    };
}