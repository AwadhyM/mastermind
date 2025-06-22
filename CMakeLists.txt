cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(mastermind)
add_executable(mastermind main.cpp source/game.cpp source/computer.cpp source/codePeg.cpp source/player.cpp source/board.cpp source/feedbackPeg.cpp )


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

enable_testing()

FetchContent_MakeAvailable(googletest)

target_include_directories(mastermind
    PUBLIC
    include
)

add_subdirectory(tests)
