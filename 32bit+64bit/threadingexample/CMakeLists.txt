ADD_LIBRARY(threadingexample-${ARCH}
                "source/threadingexample.cpp"
)

target_include_directories(threadingexample-${ARCH}
                            PUBLIC
                                "source/"
)

target_link_libraries(threadingexample-${ARCH}
                        PUBLIC
                            pthread
)