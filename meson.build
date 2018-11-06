project('cactus','cpp', default_options : ['cpp_std=c++14'])

qt5_mod = import('qt5')

qt5_opengl_dep   = dependency('qt5', modules: 'OpenGL' , required:true)
qt5_gui_dep      = dependency('qt5', modules: 'Gui', required:true)
qt5_widgets_dep  = dependency('qt5', modules: 'Widgets', required:true)
gl_dep           = dependency('GL', required:true)
openmesh_dep     = dependency('openmesh', required:true)
glm_dep = dependency('glm',required:true)
glew_dep = dependency('glew', required:true)


openglmeshrender_dep = dependency('OpenGLMeshRender', fallback: ['openglmeshrender', 'openglmeshrender_dep'])

test_option = get_option('test')
if (test_option)
  gtest_dep = dependency('gtest', required:false,fallback:['gtest','gtest_dep'])
  gmock_dep = dependency('gmock', required:false,fallback:['gtest','gmock_dep'])
endif

includeDir = include_directories('src')

subdir('src')

if (test_option)
  subdir('tests')
endif
