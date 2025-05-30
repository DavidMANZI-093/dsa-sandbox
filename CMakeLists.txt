cmake_minimum_required(VERSION 3.30)
project(dsa-sandbox VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(dsa-sandbox src/core/Application.cpp src/cli/CommandParser.cpp)