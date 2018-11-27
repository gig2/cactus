set (core_sources
     mesh.cpp
     valence.cpp)

set (core_headers
     diedre_stats.h
     equilateral_metric.h
     mesh.h
     meshutilities.h
     stats_utils.h
     valence.h)

add_library(cactus_core ${core_sources} ${core_headers})

target_include_directories(cactus_core PUBLIC
  $<BUILD_INTERFACE:${OPENMESH_INCLUDE_DIRS}>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/Cactus/core>)

target_link_libraries(cactus_core PUBLIC
  ${OPENMESH_LIBRARIES})

set_target_properties(cactus_core PROPERTIES LINK_FLAGS
  "${OPENMESH_LDFLAGS}")
