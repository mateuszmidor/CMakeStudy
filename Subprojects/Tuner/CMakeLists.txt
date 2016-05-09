add_library(TUNER source/Tuner.cpp)

target_include_directories(TUNER PUBLIC public PRIVATE ../STUBS/public)

target_link_libraries(TUNER PUBLIC STUBS)