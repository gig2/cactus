qt5_wrap_ui( UiFiles
    ui/mainwindow.ui)


qt5_wrap_cpp( mocHeader
   mainwindow.h
   objwindow.h)

set( guiSources
  mainwindow.cpp
  objwindow.cpp
     )

set (guiHeaders
     )
   
add_library(cactusgui ${guiSources} ${guiHeaders}  ${UiFiles}
                      ${mocHeader})

target_include_directories(cactusgui PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    $<INSTALL_INTERFACE:include/Cactus)

target_link_libraries(cactusgui PUBLIC
    Qt5::Widgets
    Qt5::Gui
    Qt5::3DCore
    Qt5::3DRender
    Qt5::3DInput
    Qt5::3DExtras
    )
