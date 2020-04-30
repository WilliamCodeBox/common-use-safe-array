find_package(Catch2 REQUIRED)
if(TARGET Catch2::Catch2)
  message("Found catch2")
else()
  message("Catch2 not found. Fetch Catch2 from github repository...")
  # TODO: add fetchContent
endif()

add_executable(
  CousarTesting 
  main.cpp
  test_array.cpp
)

target_include_directories(
  CousarTesting PRIVATE
  "${PROJECT_SOURCE_DIR}/include"
)
target_link_libraries(
  CousarTesting PRIVATE
  Catch2::Catch2
  cousar
)