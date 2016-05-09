cmake_minimum_required (VERSION 2.6)
project (CMakeTutorial)

set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

option (USE_MYMATH "User tutorial provided math implementation" ON)
include (CheckLibraryExists)
CHECK_LIBRARY_EXISTS (m log "cmath" HAVE_LOG)
CHECK_LIBRARY_EXISTS (m exp_ "cmath" HAVE_EXP)

configure_file (
    "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
    "${PROJECT_BINARY_DIR}/TutorialConfig.h"
    )

include_directories("${PROJECT_BINARY_DIR}")

if (USE_MYMATH)
    include_directories("${PROJECT_BINARY_DIR}/MathFunctions") # so the lib header path is known
    add_subdirectory(MathFunctions) # so cmake builds in this dir also
    set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)


add_executable (CMakeTutorial tutorial.cxx)
target_link_libraries (CMakeTutorial ${EXTRA_LIBS})

install (TARGETS CMakeTutorial DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"  DESTINATION include)


###############################################################################
# INSTALLER 
###############################################################################
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_license "${CMAKE_CURRENT_SOUCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
include (CPack)

###############################################################################
# TESTS 
###############################################################################
include (CTest)

# does the binary run without crashing and returns 0?
add_test (TutorialRuns CMakeTutorial 64)

# no arguments supplied
add_test (NoEnoughArgs CMakeTutorial)
set_tests_properties (NoEnoughArgs PROPERTIES PASS_REGULAR_EXPRESSION "Please provide one argument")

# too many arguments supplied
add_test (TooManyArgs CMakeTutorial 9 25)
set_tests_properties (TooManyArgs PROPERTIES PASS_REGULAR_EXPRESSION "Please provide one argument")
 
# test generator: compare printout with result
macro (do_test arg result)
    add_test (TutorialComp${arg} CMakeTutorial ${arg})
    set_tests_properties (TutorialComp${arg} PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)

do_test (100, "10")
do_test (64, "8")
do_test (36, "6")
