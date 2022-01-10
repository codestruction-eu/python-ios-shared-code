cmake_minimum_required(VERSION 3.0)
project(sharedLibs)

# control where the static and shared libraries are built so that on windows
# we don't need to tinker with the path to run the executable
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

# create the executable
add_executable(main main.c)

add_subdirectory(duki)

# link our executable "main" with the shared library "shared"
target_link_libraries(main shared)