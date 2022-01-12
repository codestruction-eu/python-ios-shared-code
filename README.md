# Code sharing example Python/iOS using C

## Instructions for Windows

### Requirements

* Visual Studio Community Edition 2022
* cmake
* Python3

### Build the library

```
mkdir Shared\build-win
cd Shared\build-win
cmake ..
cmake --build . --target ALL_BUILD --config Release
```

### Prepare the binding

https://cffi.readthedocs.io/en/latest/overview.html#api-mode-calling-c-sources-instead-of-a-compiled-library

* Open Developer Powershell with -DevCmdArguments '-arch=x64' https://developercommunity.visualstudio.com/t/x64-developer-powershell-for-vs-2019/943058

```
C:\Windows\SysWOW64\WindowsPowerShell\v1.0\powershell.exe -noe -c "&{Import-Module """C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\Microsoft.VisualStudio.DevShell.dll"""; Enter-VsDevShell a6de82ea -DevCmdArguments '-arch=x64'}"
```

* Enter Python venv

```
cd Python
& 'C:\Program Files (x86)\Microsoft Visual Studio\Shared\Python39_64\python.exe' -m venv .
Set-ExecutionPolicy RemoteSigned -Scope Process
.\Scripts\Activate.ps1
```

* Restore pip packages

```
pip install -r .\requirements.txt
```

* Compile the interface

```
python.exe .\piapprox_build.py
```

### Run Python code

```
python run.py
```

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
