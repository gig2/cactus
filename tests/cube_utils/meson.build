cube_utils_include = include_directories('.')

cube_utils_lib = library('cube_utils', sources: files(['cube.h', 'cube.cpp']),
                         dependencies: [openmesh_dep]
                        , include_directories: [cube_utils_include])

cube_utils_dep = declare_dependency(link_with: cube_utils_lib,
                                    dependencies: openmesh_dep,
                                    include_directories: [cube_utils_include])
