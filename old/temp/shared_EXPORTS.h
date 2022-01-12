#ifndef SHARED_EXPORTS_H
#define SHARED_EXPORTS_H

#ifdef _WIN32
    #ifdef shared_EXPORTS
        #define SHARED_EXPORT __declspec(dllexport)
    #else
        #define SHARED_EXPORT __declspec(dllimport)
    #endif
#else
    #define SHARED_EXPORT
#endif

#endif // SHARED_EXPORTS_H
