
gui_sources = files(['mainwindow.cpp',
                     'modelvisu.cpp',
                     'modelwidget.cpp'])


gui_moc_headers = files(['mainwindow.h',
                         'modelvisu.h',
                         'modelwidget.h'])

gui_ui = files(['ui/mainwindow.ui'])


gui_processed = qt5_mod.preprocess(
  moc_headers : [gui_moc_headers],
  ui_files : [gui_ui]
)

cactusgui_lib = library('cactusgui',
                        sources: [gui_sources,
                               gui_moc_headers,
                               gui_processed],

        dependencies: [ qt5_widgets_dep,
                        qt5_gui_dep,
                        qt5_3dcore_dep,
                        qt5_3dinput_dep,
                        qt5_3drender_dep,
                        qt5_3dextras_dep,
                        qt5_opengl_dep,
                        gl_dep]
        , include_directories: [includeDir]
                       )


cactusgui_dep = declare_dependency(link_with: cactusgui_lib,
                                   include_directories: [includeDir
                                                        ])
