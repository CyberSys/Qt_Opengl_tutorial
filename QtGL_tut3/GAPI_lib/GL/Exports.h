#pragma once

#ifdef GAPI_EXPORTS
#define GAPI_API __declspec(dllexport)
#else
#define GAPI_API __declspec(dllimport)
#endif

