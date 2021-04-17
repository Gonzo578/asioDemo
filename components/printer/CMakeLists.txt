# Component source configuration
set (printer_SRC src/printer.cc)

# Component include pathes
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes)

# Component is compiled into a library
add_library(printerCore ${printer_SRC})

add_subdirectory(test)
