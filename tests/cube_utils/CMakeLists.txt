add_library(cube_utils cube.h cube.cpp)

target_include_directories(cube_utils PUBLIC
  $<BUILD_INTERFACE:${OPENMESH_INCLUDE_DIRS}>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)

target_link_libraries(cube_utils PUBLIC
  ${OPENMESH_LIBRARIES})

set_target_properties(cube_utils PROPERTIES LINK_FLAGS
  "${OPENMESH_LDFLAGS}")
