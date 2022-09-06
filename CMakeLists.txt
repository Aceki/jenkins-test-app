cmake_minimum_required(VERSION 3.9)

project(jenkins-test-app)

enable_testing()

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(prog)
target_sources(prog PUBLIC ${CMAKE_SOURCE_DIR}/src/main.cpp)

add_executable(prog_test)
set_property(TARGET prog_test PROPERTY RUNTIME_OUTPUT_DIRECTORY tests)
target_sources(prog_test PUBLIC ${CMAKE_SOURCE_DIR}/test/main_test.cpp)
add_test(NAME prog_test COMMAND prog_test)
