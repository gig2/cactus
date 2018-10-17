sourcesFiles = files(['main.cpp'])

subdir('gui')
subdir('core')
subdir('render')

executable('cactus', sourcesFiles,
           dependencies: [cactusgui_dep,
                          cactuscore_dep,
                          cactusrender_dep
                          ],
           include_directories: includeDir)

