#################################################################
###                         Options                           ###
#################################################################
option(BUILD_TESTS "Build the tests" ON)

#################################################################
###                          vcpkg                            ###
#################################################################
if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
      CACHE STRING "")
endif()

#################################################################
###                         Project                           ###
#################################################################
cmake_minimum_required(VERSION 3.7)
project               (cousar VERSION 1.0.0 LANGUAGES CXX)

#################################################################
###                         Guards                            ###
#################################################################
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(WARNING "In-source build detected")
    message(STATUS "Out-of-source build is preferred")
    message(STATUS "   Create a separate directory, named `build` for convention")
    message(STATUS "   and run CMake again")
endif()

#################################################################
###                       Dependencies                        ###
#################################################################




#################################################################
###                         Sources                           ###
#################################################################
set(
    COUSAR_SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/source/vector2d.cpp
    ${PROJECT_SOURCE_DIR}/source/exception.cpp
    )


#################################################################
###                         Targets                           ###
#################################################################
set                       (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
add_library               (${PROJECT_NAME} SHARED ${COUSAR_SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_INCLUDE_DIR})
set_target_properties     (${PROJECT_NAME} PROPERTIES CXX_STANDARD 11)


#################################################################
###                        Install                            ###
#################################################################


#################################################################
###                          Tests                            ###
#################################################################
if(BUILD_TESTS)
    add_subdirectory(test)
endif()
