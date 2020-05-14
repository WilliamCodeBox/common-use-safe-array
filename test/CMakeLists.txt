enable_testing()
#################################################################
###                       Dependencies                        ###
#################################################################
find_package(Catch2 CONFIG REQUIRED)

#################################################################
###                         Sources                           ###
#################################################################
set(COUSAR_SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/source/test_array.cpp)

#################################################################
###                         Targets                           ###
#################################################################
add_executable            (CousarTesting main.cpp ${COUSAR_SOURCE_FILES})
target_include_directories(CousarTesting PRIVATE "${PROJECT_SOURCE_DIR}/include")
target_link_libraries     (CousarTesting PRIVATE Catch2::Catch2 cousar)

add_test(NAME CousarTesting COMMAND CousarTesting)