#pragma once
#include "UtilsExportHeader.h"
#include <string>

namespace FancyUtils
{	
	namespace FancyFileManager
	{
		// Start filesearch folder is where the vc projectfiles are in
		FANCYUTILS_API std::string ReadFromFile(const char* filepath);	
	}
}

