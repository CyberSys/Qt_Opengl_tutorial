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

	GAPI_API MemoryLayout
		GAPI_MakeMemoryLayout(std::vector<MemoryElement>& e);

	GAPI_API MemoryLayout
		GAPI_MakeMemoryLayout(MemoryElement* e, unsigned int count);

	GAPI_API MemoryLayout
		GAPI_MakeMemoryLayout(const MemoryLayout& val);

	GAPI_API void
		GAPI_MemoryLayoutAppend(MemoryLayout& val, MemoryElement v);

	GAPI_API bool
		GAPI_MemoryLayoutIsEqual(const MemoryLayout& val);


}