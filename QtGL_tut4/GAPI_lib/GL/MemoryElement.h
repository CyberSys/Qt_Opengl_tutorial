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
}