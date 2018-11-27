add_executable(test-diedre-stats
  main.cpp
  test_diedre_stats.cpp
  )

target_include_directories(test-diedre-stats PRIVATE
  $<BUILD_INTERFACE:${gtest_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${gmock_SOURCE_DIR}/include>)

target_link_libraries(test-diedre-stats PRIVATE
  cactus_core
  cube_utils
  gtest
  gmock)

set_target_properties(test-diedre-stats PROPERTIES LINK_FLAGS
  "${OPENMESH_LDFLAGS}")

add_test(NAME test-diedre-stats COMMAND test-diedre-stats
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
