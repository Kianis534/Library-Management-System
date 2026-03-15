cmake_minimum_required(VERSION 3.10)

# Project metadata
project(LibraryManagementSystem 
        VERSION 1.0 
        DESCRIPTION "A professional-grade C++ Library Management System"
        LANGUAGES CXX)

# Use C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Source files directory
set(SRC_DIR "LibraryManagementSystem")

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/${SRC_DIR})

# Set executable output directory to the root of the project
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# List all source files
set(SOURCES
    "${SRC_DIR}/Source.cpp"
    "${SRC_DIR}/User.cpp"
    "${SRC_DIR}/Student.cpp"
    "${SRC_DIR}/Faculty.cpp"
    "${SRC_DIR}/Staff.cpp"
    "${SRC_DIR}/Document.cpp"
    "${SRC_DIR}/Book.cpp"
    "${SRC_DIR}/Journal.cpp"
    "${SRC_DIR}/Magzine.cpp"
    "${SRC_DIR}/Newspaper.cpp"
    "${SRC_DIR}/DirectoryUser.cpp"
    "${SRC_DIR}/DirectoryDocument.cpp"
    "${SRC_DIR}/Types.cpp"
)

# List all header files
set(HEADERS
    "${SRC_DIR}/User.h"
    "${SRC_DIR}/Student.h"
    "${SRC_DIR}/Faculty.h"
    "${SRC_DIR}/Staff.h"
    "${SRC_DIR}/Document.h"
    "${SRC_DIR}/Book.h"
    "${SRC_DIR}/Journal.h"
    "${SRC_DIR}/Magzine.h"
    "${SRC_DIR}/Newspaper.h"
    "${SRC_DIR}/DirectoryUser.h"
    "${SRC_DIR}/DirectoryDocument.h"
    "${SRC_DIR}/Types.h"
)

# Create the executable
add_executable(LibraryManagementSystem ${SOURCES} ${HEADERS})

# Compiler-specific settings
if(MSVC)
    target_compile_options(LibraryManagementSystem PRIVATE /W3)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
else()
    target_compile_options(LibraryManagementSystem PRIVATE -Wall -Wextra)
endif()

# Installation rules
install(TARGETS LibraryManagementSystem DESTINATION bin)
