cmake .. # create makefile project
cpack --config CPackConfig.cmake # bin only
cpack --config CPackSourceConfig.cmake # source code
