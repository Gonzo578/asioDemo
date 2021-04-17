# Component source configuration
set (toDo_SRC src/ToDo.cc)

# Component include pathes
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes)

# Component is compiled into a library
add_library(toDoCore ${toDo_SRC})

add_subdirectory(test)

