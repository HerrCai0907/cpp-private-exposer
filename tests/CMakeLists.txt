
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP on
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(ut_exposer ut_exposer.cpp)
target_link_libraries(ut_exposer GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(ut_exposer)
