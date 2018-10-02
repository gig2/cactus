set (sourcesFiles
    main.cpp)

#QT5_WRAP_UI(UiGenerated_SRCS
#    ui/window.ui)

add_executable(cactus ${sourcesFiles} ${UiGenerated_SRCS})

target_include_directories(cactus PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    )

target_link_libraries(cactus PUBLIC
    Qt5::Widgets
    Qt5::Core
    Qt5::Gui
    OpenMVG::openMVG_camera
    OpenMVG::openMVG_numeric
    )
