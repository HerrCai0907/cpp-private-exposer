cmake_minimum_required(VERSION 3.0)
project(cpp-private-exposer)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

if(EXPORSER_EXAMPLE)
    add_subdirectory(example)
endif()
