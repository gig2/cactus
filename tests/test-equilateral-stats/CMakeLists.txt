add_executable(test-equilateral-stats
  main.cpp
  test_equilateral_stats.cpp
  )

target_include_directories(test-equilateral-stats PRIVATE
  $<BUILD_INTERFACE:${gtest_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${gmock_SOURCE_DIR}/include>)

target_link_libraries(test-equilateral-stats PRIVATE
  cactus_core
  cube_utils
  gtest
  gmock)

set_target_properties(test-equilateral-stats PROPERTIES LINK_FLAGS
  "${OPENMESH_LDFLAGS}")

add_test(NAME test-equilateral-stats COMMAND test-equilateral-stats
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
