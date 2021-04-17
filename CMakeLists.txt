cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "
            FATAL: In-source builds are not allowed.
            You should create a separate directory for build files.
")
endif()

# Global project name
project ("Project Template")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Add local module path to the cmake modules search path
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)

# Testing configuration
enable_testing()

add_subdirectory(components)

# Project source files
set (project_SRC
    src/main.cc
)

# Main project target configuration
add_executable (asioDemo ${project_SRC})

# Target link libraries
target_link_libraries(asioDemo pthread ${CONAN_LIBS})
