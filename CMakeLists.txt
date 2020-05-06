############################## Project ########################################
cmake_minimum_required(VERSION 3.16)
project               (CommonUsageArray VERSION 1.0.0 LANGUAGES CXX)

############################## Options ########################################
option(BUILD_TESTS "Build tests." ON)
option(BUILD_SHARED_LIBS "Build dynamic library." ON)

############################## Targets ########################################
add_library(
  cousar 
  "${PROJECT_SOURCE_DIR}/source/array.cpp"
  "${PROJECT_SOURCE_DIR}/source/exception.cpp"

)
target_include_directories(
  cousar PUBLIC 
  "${PROJECT_SOURCE_DIR}/include"
)
set_target_properties(
  cousar PROPERTIES 
  CXX_STANDARD 14
)

############################## Testing ########################################
if (BUILD_TESTS)
  add_subdirectory(test)
endif()