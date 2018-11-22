add_executable(test-stats-utils
  main.cpp
  test_stats-utils.cpp
  )

target_include_directories(test-stats-utils PRIVATE
  $<BUILD_INTERFACE:${gtest_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${gmock_SOURCE_DIR}/include>)

target_link_libraries(test-stats-utils PRIVATE
  cactus_core
  gtest
  gmock)

set_target_properties(test-stats-utils PROPERTIES LINK_FLAGS
  "${OPENMESH_LDFLAGS}")

add_test(NAME test-stats-utils COMMAND test-stats-utils
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
