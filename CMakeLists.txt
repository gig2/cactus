cmake_minimum_required(VERSION 3.5)
project(Cactus CXX)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)
find_package(OpenMVG REQUIRED)

add_subdirectory(src)
