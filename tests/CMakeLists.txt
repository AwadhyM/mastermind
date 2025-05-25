add_executable(
    hello_test
    hello_test.cpp
)
target_link_libraries(
    hello_test
    GTest::gtest_main
)

# TODO - target_include_directories()
# TODO - target_link_libraries()

include(GoogleTest)
gtest_discover_tests(hello_test)
