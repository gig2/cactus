project('cactus','cpp', default_options : ['cpp_std=c++14'])

qt5_mod = import('qt5')

qt5_opengl_dep   = dependency('qt5', modules: 'OpenGL' )
qt5_gui_dep      = dependency('qt5', modules: 'Gui')
qt5_widgets_dep  = dependency('qt5', modules: 'Widgets')
qt5_3dcore_dep   = dependency('qt5', modules: '3DCore')
qt5_3dinput_dep  = dependency('qt5', modules: '3DInput')
qt5_3drender_dep = dependency('qt5', modules: '3DRender')
qt5_3dextras_dep = dependency('qt5', modules: '3DExtras')
gl_dep           = dependency('GL')
openmesh_dep     = dependency('openmesh')

includeDir = include_directories('src')

subdir('src')
