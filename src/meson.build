sourcesFiles = files(['main.cpp'])

subdir('gui')
subdir('core')
subdir('render')

executable('cactus', sourcesFiles,
           dependencies: [cactus_gui_dep,
                          cactus_core_dep,
                          cactus_render_dep
                          ],
           include_directories: includeDir)

