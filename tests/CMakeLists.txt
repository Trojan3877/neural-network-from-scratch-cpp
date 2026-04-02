include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP ON
)
# Prevent overriding the parent project's compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(test_network
    test_network.cpp
    ../src/impl/NeuralNet.cpp
    ../src/impl/CSVLoader.cpp
)
target_include_directories(test_network PRIVATE ../src)
target_link_libraries(test_network GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_network)
