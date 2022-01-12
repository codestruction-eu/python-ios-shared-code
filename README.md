# Code sharing example Python/iOS using C

## Instructions for Windows

## Instructions for macOS

### Requirements

* Xcode
* [cmake](https://cmake.org/download/#latest)

Ensure `cmake` can be found, e.g.:

```sh
PATH="/install/dir/of/CMake.app/Contents/bin":"$PATH"
```

### Build the shared library (C code)

```sh
( \
    mkdir -p Shared/build-mac && \
    cd Shared/build-mac && \
    cmake .. -G Xcode -DCMAKE_TOOLCHAIN_FILE=../ios.toolchain.cmake -DPLATFORM=OS64COMBINED -DDEPLOYMENT_TARGET=9.0 -DENABLE_STRICT_TRY_COMPILE=1 -DENABLE_VISIBILITY=0 && \
    cmake --build . --config Release
) && \

```
