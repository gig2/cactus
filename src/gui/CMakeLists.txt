set( gui_sources
  mainwindow.cpp
  modelvisu.cpp)


qt5_wrap_cpp( gui_moc_headers
   mainwindow.h
   modelvisu.h)


qt5_wrap_ui( gui_ui
    ui/mainwindow.ui)


add_library(cactus_gui ${gui_sources}  ${gui_ui}
                      ${gui_moc_headers})

target_include_directories(cactus_gui PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)

target_include_directories(cactus_gui PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/Cactus/gui)

target_link_libraries(cactus_gui PUBLIC
  Qt5::Widgets
  Qt5::Gui
  Qt5::OpenGL
  cactus_core
  cactus_render)

set_target_properties(cactus_gui PROPERTIES LINK_FLAGS
  ${OPENMESH_LDFLAGS})
