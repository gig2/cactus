cmake_minimum_required(VERSION 3.5)
project(Cactus CXX)

set(CMAKE_CXX_STANDARD 14)

# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)

find_package(PkgConfig)

find_package(Qt5 COMPONENTS Core Widgets Gui 3DCore 3DInput 3DRender 3DExtras REQUIRED)

find_package(GLEW REQUIRED)

pkg_check_modules(OPENMESH REQUIRED openmesh)
pkg_check_modules(GLM REQUIRED glm)

add_subdirectory(src)
