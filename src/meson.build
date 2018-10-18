sourcesFiles = files(['main.cpp'])

subdir('core')
subdir('render')
subdir('gui')

executable('cactus', sourcesFiles,
           dependencies: [cactus_gui_dep
                          ],
           include_directories: includeDir)

