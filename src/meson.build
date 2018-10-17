sourcesFiles = files(['main.cpp'])

subdir('gui')
subdir('core')

executable('cactus', sourcesFiles,
           dependencies: [cactusgui_dep,
                          cactuscore_dep,
                          openmesh_dep,
                          qt5_widgets_dep,
                          qt5_3dcore_dep,
                          qt5_3drender_dep,
                          qt5_3dextras_dep,
                          gl_dep],
           include_directories: includeDir)

