core_sources = files(['mesh.cpp',
                      'valence.cpp',])

core_headers = files(['mesh.h',
                      'valence.h'])

core_include = include_directories('.')

cactus_core_lib = library('cactus_core',
                        sources: [core_sources,
                                  core_headers],

        dependencies: [ openmesh_dep]
        , include_directories: [core_include]
                       )


cactus_core_dep = declare_dependency(link_with: cactus_core_lib,
                                    dependencies: openmesh_dep,
                                   include_directories: [core_include])
