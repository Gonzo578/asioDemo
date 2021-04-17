
add_executable(test_ToDo ToDoTest.cc)
target_link_libraries(test_ToDo PRIVATE toDoCore ${CONAN_LIBS})

add_test(NAME test_ToDo COMMAND test_ToDo)
