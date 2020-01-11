#pragma once
#ifdef _WIN32
#include "SDKDDKVer.h"
#define SHARED_EXPORT __declspec(dllexport)
#define SHARED_IMPORT __declspec(dllimport)
#else
#define SHARED_EXPORT
#define SHARED_IMPORT
#endif

#ifdef PLOTTER_STATIC
#define PLOTTER_EXPORT
#elif PLOTTER_DYNAMIC
#define PLOTTER_EXPORT SHARED_EXPORT
#else
#define PLOTTER_EXPORT SHARED_IMPORT
#endif