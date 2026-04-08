cmake_minimum_required(VERSION 3.16)
project(NeuralNetworkFromScratch)

set(CMAKE_CXX_STANDARD 17)

# Core implementation sources (no main)
set(NN_SOURCES
    src/impl/NeuralNet.cpp
    src/impl/CSVLoader.cpp
)

# Main executable
add_executable(neural_net src/main.cpp ${NN_SOURCES})
target_include_directories(neural_net PRIVATE src)

# ── Tests ────────────────────────────────────────────────────────────────────
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
# Prevent overriding the parent project's compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(test_neural_net tests/test_network.cpp ${NN_SOURCES})
target_include_directories(test_neural_net PRIVATE src)
target_link_libraries(test_neural_net GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_neural_net)

