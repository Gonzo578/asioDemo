#
# add_gmock_test(<target> <sources>...)
#
# Adds a Google Mock based test executable, <target>, build from <sources> and
# adds the test so that CTest will run it. Both the executable and the test
# will be named <target>.
#
function(add_gmock_test target)
    add_executable(${target} ${ARGN})
    target_link_libraries(${target} ${CONAN_LIBS})
    
    add_test(${target} ${target})
    
    add_custom_command( TARGET ${target}
                        POST_BUILD
                        COMMAND ${target} --gtest_output=xml:./${target}_report.xml
                        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                        COMMENT "Running ${target}" VERBATIM)   
endfunction()