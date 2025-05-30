#pragma once

namespace utils {
    template <typename T>
    constexpr size_t len(const T& arr) {
        return sizeof(arr) / sizeof(arr[0]);
    }
}