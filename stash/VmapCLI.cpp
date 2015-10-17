#include "stdafx.h"
#include <msclr\marshal_cppstd.h>
#include "VMapCLI.h"

using namespace msclr::interop;

namespace VMapCLIR
{
	void VMap::Initialize(String^ vmapsPath)
	{
		vmapsFolderPath = vmapsPath;
		if (!vmapsFolderPath->EndsWith("\\"))
			vmapsFolderPath += "\\";
	}

	void VMap::LoadTile(int tileX, int tileY, int mapID)
	{
		vmapManager->loadMap(marshal_as<std::string>(vmapsFolderPath).c_str(), mapID, tileX, tileY);
	}

	float VMap::GetHeight(float X, float Y, float Z, int mapID)
	{
		return vmapManager->getHeight(mapID, X, Y, Z + SAFE_Z_HIGHER_BIAS, DEFAULT_HEIGHT_SEARCH);
	}
}
