#pragma once

#include "Exports.h"
#include "MemoryElement.h"
#include <vector>


namespace GAPI
{
	struct MemoryLayout
	{
		unsigned int size = 0;
		std::vector<MemoryElement> elements;
	};
}