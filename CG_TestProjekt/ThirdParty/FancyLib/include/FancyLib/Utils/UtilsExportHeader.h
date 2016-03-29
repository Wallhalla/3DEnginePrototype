#pragma once
#ifdef FANCYLIB_EXPORTS
#define FANCYUTILS_API __declspec(dllexport)
#else
#define FANCYUTILS_API __declspec(dllimport)
#endif