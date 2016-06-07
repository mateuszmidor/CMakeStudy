set(ARCH "64bit")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -m64 -pthread -static")
add_subdirectory(../threadingexample threadingexample-${ARCH})
ADD_EXECUTABLE(${ARCH}
                "../source/main.cpp"
)

target_link_libraries(${ARCH} threadingexample-${ARCH})