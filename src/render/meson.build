render_headers = files(['shader.h'])

render_sources = files(['shader.cpp'])

render_include = include_directories('.')

cactus_render_lib = library('cactus_render',
                           sources: [render_sources,
                                     render_headers],
                           dependencies: [glew_dep, glm_dep,cactus_core_dep],
                           include_directories: [render_include])

cactus_render_dep = declare_dependency(link_with: cactus_render_lib,
                                       dependencies: [glew_dep,
                                                      glm_dep,
                                                      cactus_core_dep],
                                     include_directories: [render_include])
