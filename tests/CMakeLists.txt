find_package(GTest REQUIRED)

add_executable(tests test_network.cpp)
target_link_libraries(tests GTest::gtest_main neural_net)
add_test(NAME NNTests COMMAND tests)