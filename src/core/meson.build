
core_sources = files(['mesh.cpp',
                     ])

core_headers = files(['mesh.h'])

cactuscore_lib = library('cactuscore',
                        sources: [core_sources,
                                  core_headers],

        dependencies: [ openmesh_dep
                        ]
        , include_directories: [includeDir]
                       )


cactuscore_dep = declare_dependency(link_with: cactuscore_lib,
                                   include_directories: [includeDir
                                                        ])
