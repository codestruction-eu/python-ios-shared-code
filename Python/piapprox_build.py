from cffi import FFI
ffibuilder = FFI()

# cdef() expects a single string declaring the C types, functions and
# globals needed to use the shared object. It must be in valid C syntax.
ffibuilder.cdef("""
    float pi_approx(int n);
""")

# set_source() gives the name of the python extension module to
# produce, and some C source code as a string.  This C code needs
# to make the declarated functions, types and globals available,
# so it is often just the "#include".
ffibuilder.set_source("_pi_cffi",
"""
     #include "../shared.h"   // the C header of the library
""",
     libraries=['shared'],   # library name, for the linker
     extra_link_args=['-L/Users/christoph/Documents/Codestruction-tmp/python-ios-shared-code/Shared/build'])

if __name__ == "__main__":
    ffibuilder.compile(verbose=True)
