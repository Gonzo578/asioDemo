add_executable(test_Printer printerTest.cc)
target_link_libraries(test_Printer PRIVATE printerCore ${CONAN_LIBS})

add_test(NAME test_Printer COMMAND test_Printer)