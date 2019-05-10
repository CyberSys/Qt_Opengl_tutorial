#pragma once


class Texture
{
public:
	Texture(char* filename);
	~Texture();

	void Attach_Texture_to_Geomtry();
	void DeleteTextureFromGPU();
private:

	void ReadImageFromFile(char* filename);

	unsigned char* data;
	int width;
	int height;
	int depth;

	unsigned int textureID;
};