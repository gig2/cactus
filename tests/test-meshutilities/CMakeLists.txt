add_executable(test-meshutilities
  main.cpp
  cube.h
  cube.cpp
  test_meshutilities.cpp
  )

target_include_directories(test-meshutilities PRIVATE
  $<BUILD_INTERFACE:${gtest_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${gmock_SOURCE_DIR}/include>)

target_link_libraries(test-meshutilities PRIVATE
  cactus_core
  gtest
  gmock)

set_target_properties(test-meshutilities PROPERTIES LINK_FLAGS
  "${OPENMESH_LDFLAGS}")

add_test(NAME test-meshutilities COMMAND test-meshutilities
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
