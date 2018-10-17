render_headers = files(['shader.h'])

render_sources = files(['shader.cpp'])

cactusrender_lib = library('cactusrender',
                           sources: [render_sources,
                                     render_headers],
                           dependencies: [glew_dep, glm_dep,cactuscore_dep],
                          include_directories: [includeDir])

cactusrender_dep = declare_dependency(link_with: cactusrender_lib,
                                      dependencies: [glew_dep, glm_dep, cactuscore_dep],
                                     include_directories: [includeDir])
