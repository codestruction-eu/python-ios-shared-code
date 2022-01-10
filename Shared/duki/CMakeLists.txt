# create the shared library
add_library(shared SHARED shared.c)

# Always include the source and build directories in the include path.
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# state that anybody linking to us needs to include the current source dir
target_include_directories(shared
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
GENERATE_EXPORT_HEADER(shared
             BASE_NAME shared
             EXPORT_MACRO_NAME SHARED_EXPORT
             EXPORT_FILE_NAME shared_EXPORTS.h
             STATIC_DEFINE SHARED_EXPORTS_BUILT_AS_STATIC)
