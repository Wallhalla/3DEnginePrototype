#pragma once
#ifdef FANCYLIB_EXPORTS
#define FANCYMATH_API __declspec(dllexport)
#else
#define FANCYMATH_API __declspec(dllimport)
#endif