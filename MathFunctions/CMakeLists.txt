add_custom_command (
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    COMMAND python ${CMAKE_CURRENT_BINARY_DIR}/../../MathFunctions/MakeTable.py ${CMAKE_CURRENT_BINARY_DIR}/Table.h
)

include_directories ( ${CMAKE_CURRENT_BINARY_DIR} ) # search for Table.h here

add_library(MathFunctions mysqrt.cxx ${CMAKE_CURRENT_BINARY_DIR}/Table.h)

install (TARGETS MathFunctions DESTINATION bin)
install (FILES MathFunctions.h DESTINATION include)
