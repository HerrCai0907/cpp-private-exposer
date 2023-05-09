cmake_minimum_required(VERSION 3.0)
project(cpp-private-exposer)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

if(EXPORSER_DEV)
    add_subdirectory(example)
    enable_testing()
    add_subdirectory(tests)
endif()
