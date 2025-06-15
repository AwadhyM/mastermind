add_executable(
    computer_test
    computer_test.cpp
	../source/computer.cpp
	../source/colorPeg.cpp
)
target_link_libraries(
    computer_test
    GTest::gtest_main
)

# TODO - target_include_directories()
# TODO - target_link_libraries()

include(GoogleTest)
gtest_discover_tests(computer_test)
