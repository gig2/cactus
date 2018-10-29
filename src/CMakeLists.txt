set (sourcesFiles
    main.cpp)

add_subdirectory(core)
add_subdirectory(render)
add_subdirectory(gui)


add_executable(cactus ${sourcesFiles} )

target_include_directories(cactus PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    )

target_link_libraries(cactus PUBLIC
   cactus_gui
    )

set_target_properties(cactus PROPERTIES LINK_FLAGS
  "${OPENMESH_LDFLAGS}")
