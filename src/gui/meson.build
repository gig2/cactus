gui_sources = files(['mainwindow.cpp',
                     'modelvisu.cpp'])


gui_moc_headers = files(['mainwindow.h',
                         'modelvisu.h'])

gui_ui = files(['ui/mainwindow.ui'])


gui_processed = qt5_mod.preprocess(
  moc_headers : [gui_moc_headers],
  ui_files : [gui_ui]
)


gui_include = include_directories('.')

cactus_gui_lib = library('cactus_gui',
                        sources: [gui_sources,
                               gui_moc_headers,
                               gui_processed],

        dependencies: [ qt5_widgets_dep,
                        qt5_gui_dep,
                        qt5_opengl_dep,
                        gl_dep,
                        cactus_core_dep,
                        cactus_render_dep]
        , include_directories: gui_include
                       )


cactus_gui_dep = declare_dependency(link_with: cactus_gui_lib,
                                    dependencies:
                                             [qt5_widgets_dep,
                                              qt5_gui_dep,
                                              qt5_opengl_dep,
                                              gl_dep,
                                              cactus_core_dep,
                                              cactus_render_dep],
                                   include_directories: [gui_include])
