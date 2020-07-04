cmake_minimum_required(VERSION 3.5)

project(DateL LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(DateL SHARED
  DateL_global.h
  datel.cpp
  datel.h
)

target_compile_definitions(DateL PRIVATE DATEL_LIBRARY)
