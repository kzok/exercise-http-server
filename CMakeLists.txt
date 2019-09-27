cmake_minimum_required(VERSION 3.0)
project(http-server CXX)

#
# Dependencies
#

add_subdirectory(deps/libuv)
include_directories(
	deps
	deps/libuv/include
	deps/uvw/src
)

#
# Targets
#

file(GLOB_RECURSE source_files src/*.cpp)
add_executable(${PROJECT_NAME} ${source_files})

file(GLOB_RECURSE test_source_files src/*.cpp test/*.cpp)
add_executable(run_tests ${test_source_files})

add_definitions("-Wall -std=c++17")
target_compile_definitions(run_tests PUBLIC "-DUNITTEST -g -O0 -pg -coverage")
target_link_libraries(${PROJECT_NAME} uv_a)
target_link_libraries(run_tests PUBLIC uv_a "-coverage")
