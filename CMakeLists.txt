cmake_minimum_required(VERSION 3.15)
set (CMAKE_CXX_STANDARD 14)

# Export all symbols
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

project(esl CXX)

# Adjust compiler flags
if(CMAKE_COMPILER_IS_GNUCXX)
    # Enable warnings
    SET(CMAKE_CXX_FLAGS "-Wall -Wno-long-long -pedantic" CACHE STRING "compile flags" FORCE)
    # Disable optimization for RelWithDebInfo
    SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g -DNDEBUG" CACHE STRING "compile flags" FORCE)
endif(CMAKE_COMPILER_IS_GNUCXX)

# Include own header
include_directories("include/")

# Build library
file(GLOB_RECURSE SRCS
  "include/*.h"
  "src/*.h"
  "src/*.cpp")
set_target_properties(${name} PROPERTIES DEBUG_POSTFIX d)
add_library(esl SHARED ${SRCS})

# Add test
find_package(GTest REQUIRED)
enable_testing()
file(GLOB_RECURSE TEST_SRCS
  "include/*.h"
  "test/*.h"
  "test/*.cpp")
add_executable(esl_test ${TEST_SRCS})
target_link_libraries(
  esl_test
  esl
  GTest::gtest_main
)
