set( guiSources
  mainwindow.cpp
  modelvisu.cpp
  modelwidget.cpp)


qt5_wrap_cpp( mocHeader
   mainwindow.h
   modelvisu.h
   modelwidget.h)


qt5_wrap_ui( UiFiles
    ui/mainwindow.ui)

   
add_library(cactusgui ${guiSources}  ${UiFiles}
                      ${mocHeader})

target_include_directories(cactusgui PRIVATE
    $<BUILD_INTERFACE:${CMAKE_PROJECT_SOURCE_DIR}/src>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    $<INSTALL_INTERFACE:include/Cactus/gui)

target_link_libraries(cactusgui PUBLIC
    Qt5::Widgets
    Qt5::Gui
    Qt5::3DCore
    Qt5::3DRender
    Qt5::3DInput
    Qt5::3DExtras
    )
