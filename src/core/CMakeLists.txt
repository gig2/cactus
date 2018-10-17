set (core_sources
     mesh.cpp)
set (core_headers
     mesh.h )

add_library(cactuscore ${core_sources} ${core_headers})

target_include_directories(cactuscore PUBLIC
  $<BUILD_INTERFACE:${OPENMESH_INCLUDE_DIRS}>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}
  $<INSTALL_INTERFACE:include/Cactus/core>)

target_link_libraries(cactuscore PUBLIC
  ${OPENMESH_LIBRARIES})

set_target_properties(cactuscore PROPERTIES LINK_FLAGS
  ${OPENMESH_LDFLAGS})
