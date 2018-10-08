sourcesFiles = files(['main.cpp'])

subdir('gui')

executable('cactus', sourcesFiles,
           dependencies: [cactusgui_dep,
                          qt5_widgets_dep,
                          qt5_3dcore_dep,
                          qt5_3drender_dep,
                          qt5_3dextras_dep,
                          gl_dep],
           include_directories: includeDir)

