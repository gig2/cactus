set (render_sources
    shader.cpp)

set (render_headers
     shader.h)

add_library(cactusrender ${render_sources} ${render_headers})

target_link_libraries(cactusrender PUBLIC
  cactuscore
  GLEW::GLEW
  ${GLM_LIBRARIES})

target_include_directories(cactusrender PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/Cactus/render>)

set_target_properties(cactusrender PROPERTIES LINK_FLAGS
  ${OPENMESH_LDFLAGS})
