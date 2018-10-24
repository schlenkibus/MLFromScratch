cmake_minimum_required(VERSION 3.9)
project(MLFromScratch)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

add_executable(MLFromScratch ${SOURCE_FILES})
