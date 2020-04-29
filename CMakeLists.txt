############################## Project ########################################
cmake_minimum_required(VERSION 3.16)
project               (CommonUsageArray VERSION 1.0.0 LANGUAGES CXX)

############################## Options ########################################
option(BUILD_TESTS "Build tests." OFF)
option(BUILD_SHARED_LIBS "Build dynamic library." ON)

############################## Targets ########################################
add_library(cousar )
target_include_directories(
  cousar PUBLIC 
  "${PROJECT_SOURCE_DIR}/include"
)
set_target_properties(
  cousar PROPERTIES 
  CXX_STANDARD 14
)