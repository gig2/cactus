set (core_source 
     mesh.h mesh.cpp)

add_library(cactuscore ${core_source})

target_include_directories(cactuscore PUBLIC 
$<BUILD_INTERFACE:${OPENMESH_INCLUDE_DIRS}>)

target_link_libraries(cactuscore PUBLIC
${OPENMESH_LIBRARIES})


