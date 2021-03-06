cmake_minimum_required(VERSION 3.0)
project(dukicalculations)

# control where the static and shared libraries are built so that on windows
# we don't need to tinker with the path to run the executable
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

# create the shared library
add_library(dukicalculations dukicalculations.c)

# state that anybody linking to us needs to include the current source dir
target_include_directories(dukicalculations
                           PUBLIC
                            ${CMAKE_CURRENT_BINARY_DIR}
                           INTERFACE
                            ${CMAKE_CURRENT_SOURCE_DIR}
                           )

# Export no symbols by default (if the compiler supports it).
# This makes e.g. GCC's "visibility behavior" consistent with MSVC's. 
# On Windows/MSVC this is a noop.
set(CMAKE_C_VISIBILITY_PRESET hidden)

# generate export header automatically
include (GenerateExportHeader)
GENERATE_EXPORT_HEADER(dukicalculations
             BASE_NAME dukicalculations
             EXPORT_MACRO_NAME DUKICALCULATIONS_EXPORT
             EXPORT_FILE_NAME dukicalculations_EXPORTS.h
             STATIC_DEFINE SHARED_EXPORTS_BUILT_AS_STATIC)
