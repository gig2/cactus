project('cactus','cpp', default_options : ['cpp_std=c++14'])

qt5_mod = import('qt5')

qt5_opengl_dep   = dependency('qt5', modules: 'OpenGL' , required:true)
qt5_gui_dep      = dependency('qt5', modules: 'Gui', required:true)
qt5_widgets_dep  = dependency('qt5', modules: 'Widgets', required:true)
gl_dep           = dependency('GL', required:true)
openmesh_dep     = dependency('openmesh', required:true)
glm_dep = dependency('glm',required:true)
glew_dep = dependency('glew', required:true)

includeDir = include_directories('src')

subdir('src')
