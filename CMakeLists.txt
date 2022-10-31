cmake_minimum_required(VERSION 3.15)
project(esl CXX)

add_library(esl src/esl.cpp)
target_include_directories(esl PUBLIC include)

set_target_properties(esl PROPERTIES PUBLIC_HEADER "include/esl.h")
install(TARGETS esl)
