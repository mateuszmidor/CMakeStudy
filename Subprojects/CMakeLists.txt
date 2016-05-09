cmake_minimum_required(VERSION 3.2)

project(Prototype)

set(PROJECT_MAJOR_VERSION 0)
set(PROJECT_MINOR_VERSION 1)
set(PROJECT_PATCH_LEVEL 0)

set(PROJECT_VERSION ${PROJECT_MAJOR_VERSION}.${PROJECT_MINOR_VERSION}.${PROJECT_PATCH_LEVEL})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")

# set "make install" output dir to "cmake_build/RELEASE"
set (BUILD_OUTPUT_DIR "${PROJECT_BINARY_DIR}/RELEASE")

# add subprojects
add_subdirectory(STUBS)
add_subdirectory(Tuner)
add_subdirectory(App)

# copy "data" folder during "make install"
install(DIRECTORY data DESTINATION ${BUILD_OUTPUT_DIR})