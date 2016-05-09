# NOTICE: BUILD_OUTPUT_DIR is being set in master CMakeLists.txt

add_executable(App source/Main.cpp)

target_include_directories(App PUBLIC public PRIVATE ../Tuner/public)

target_link_libraries(App PUBLIC TUNER )


install(TARGETS App DESTINATION ${BUILD_OUTPUT_DIR})