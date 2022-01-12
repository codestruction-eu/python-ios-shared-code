# Code sharing example Python/iOS using C

## Instructions for Windows

## Instructions for macOS

### Requirements

* Xcode

### Build the shared library (C code)

```sh
mkdir -p Shared/build-mac
cat > Shared/build-mac/dukicalculations_EXPORTS.h << "EOF"
#ifndef DUKICALCULATIONS_EXPORTS_H
#define DUKICALCULATIONS_EXPORTS_H

#ifdef _WIN32
    #ifdef shared_EXPORTS
        #define DUKICALCULATIONS_EXPORT __declspec(dllexport)
    #else
        #define DUKICALCULATIONS_EXPORT __declspec(dllimport)
    #endif
#else
    #define DUKICALCULATIONS_EXPORT
#endif

#endif // DUKICALCULATIONS_EXPORTS_H
EOF

( \
    mkdir -p Shared/build-mac/{simulator,ios} && \
    cd Shared/build-mac && \
    clang -I. -arch x86_64 -mios-version-min=9.0 -isysroot `xcode-select -p`/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator.sdk ../dukicalculations.c -c && \
    ar rcs simulator/libdukicalculations.a dukicalculations.o && \
    clang -I. -arch arm64 -mios-version-min=9.0 -isysroot `xcode-select -p`/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk ../dukicalculations.c -c && \
    ar rcs ios/libdukicalculations.a dukicalculations.o && \
    lipo -create ios/libdukicalculations.a simulator/libdukicalculations.a -output libdukicalculations.a && \
    rm -rf ios simulator
) && \

```
