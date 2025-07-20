cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(mastermind)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS source/*.cpp)

add_executable(mastermind main.cpp ${SOURCES})

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	target_compile_definitions(mastermind PRIVATE DEBUG_BUILD)
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

enable_testing()

FetchContent_MakeAvailable(googletest)

target_include_directories(mastermind
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

add_subdirectory(tests)
