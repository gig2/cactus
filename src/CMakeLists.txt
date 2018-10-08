set (sourcesFiles
    main.cpp)

add_subdirectory(gui)


add_executable(cactus ${sourcesFiles} )

target_include_directories(cactus PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    )

target_link_libraries(cactus PUBLIC
   cactusgui
    #OpenMVG::openMVG_camera
    #OpenMVG::openMVG_numeric
    )
