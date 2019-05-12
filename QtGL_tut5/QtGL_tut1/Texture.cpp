#include "Texture.h"

#include <qpixmap.h>
#include <GraphicsGL.h>

#include "stb_image.h"

Texture::Texture(char* filename)
{
	ReadImageFromFile(filename);
	
	if (data)
	{
		textureID = GAPI::GAPI_CreateTexture2D(width, height, data, true);

		GAPI::GAPI_ApplySamplerTex2D(textureID, true,
			GAPI::TextureAddressMode::WRAP,
			GAPI::TextureAddressMode::WRAP,
			GAPI::TextureFilter::LINEAR,
			GAPI::ComparisonFunction::NEVER, 0, 0, 0, 1);
	}

}

Texture::~Texture()
{
}

void Texture::Attach_Texture_to_Geomtry()
{
	GAPI::GAPI_BindTexture2D(textureID, 0);
}

void Texture::DeleteTextureFromGPU()
{
	GAPI::GAPI_DeleteTexture2D(textureID);
}


void Texture::ReadImageFromFile(char * filename)
{
	data = stbi_load(filename, &width, &height, &depth, 0);
}
