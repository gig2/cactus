set (render_headers
     shader.h)

set (render_sources
    shader.cpp)


add_library(cactus_render ${render_sources} ${render_headers})

target_link_libraries(cactus_render PUBLIC
  cactus_core
  GLEW::GLEW
  ${GLM_LIBRARIES}
  ${OPENMESH_LIBRARIES})

target_include_directories(cactus_render PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/Cactus/render>)

set_target_properties(cactus_render PROPERTIES LINK_FLAGS
  ${OPENMESH_LDFLAGS})
