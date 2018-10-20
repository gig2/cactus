cmake_minimum_required(VERSION 3.5)
project(Cactus CXX)

set(CMAKE_CXX_STANDARD 14)

# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)

find_package(PkgConfig)

find_package(Qt5 COMPONENTS Core Widgets Gui OpenGL REQUIRED)

find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

pkg_check_modules(OPENMESH REQUIRED openmesh)
pkg_check_modules(GLM REQUIRED glm)


# OpenMeshRender support
find_package(OpenGLMeshRender CONFIG QUIET)

if (NOT OpenGLMeshRender_FOUND)

  find_package(Git REQUIRED)

  if (NOT EXISTS ${CMAKE_CURRENT_LIST_DIR}/external/openglmeshrender/CMakeLists.txt)
    message("Init OpenGLMeshRender subprojects")
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule init external/openglmeshrender
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

     execute_process(COMMAND ${GIT_EXECUTABLE} submodule update external/openglmeshrender
                     WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

   endif()

   add_subdirectory(external/openglmeshrender)

endif()


add_subdirectory(src)
