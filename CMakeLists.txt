cmake_minimum_required(VERSION 2.8)

get_filename_component(ProjectId ${CMAKE_CURRENT_LIST_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId}  DESCRIPTION "crd math shit" CXX)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
#clang --target=wasm32 -emit-llvm -c -S

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fpermissive -O3 -Wall -Wextra ")
include_directories(  include)
file (GLOB_RECURSE SRC_LIST src/*.cpp src/*.c )

#add_library(${PROJECT_NAME} SHARED ${SRC_LIST})

add_executable(${PROJECT_NAME}  ${SRC_LIST} )
target_link_libraries(${PROJECT_NAME} m)

#add_executable("${PROJECT_NAME}-test"  test/main.c )
#target_link_libraries("${PROJECT_NAME}-test" m ${PROJECT_NAME})
