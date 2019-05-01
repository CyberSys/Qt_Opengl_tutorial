#pragma once
#include "Exports.h"
#include <string>

namespace GAPI
{

	enum Type 
	{
		VEC2 = 0, VEC3, VEC4, FLOAT, INT, BOOL, MAT3, MAT4, NONE
	};

	struct MemoryElement
	{
		Type type;
		unsigned int offset;
		unsigned int size;
		unsigned int components;
		std::string semantic;
	};

	GAPI_API void
		GAPI_MakeMemoryElement(unsigned int _offset, unsigned int _size, unsigned int _components,Type _type = NONE, std::string _semantic = "");

	GAPI_API void
		GAPI_MakeMemoryElement(Type _type, std::string _semantic);

	GAPI_API void
		GAPI_MakeMemoryElement(const MemoryElement& val);

	GAPI_API void
		GAPI_MemoryElementIsEqual(const MemoryElement& val);

}