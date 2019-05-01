#pragma once
#include "Exports.h"
#include "Memorylayout.h"

namespace GAPI
{
	//api enums...

	enum TextureFilter
	{
		POINT,
		LINEAR,
		ANISOTROPIC,
		LINEAR_MIP_POINT,
		POINT_MIP_LINEAR,
		MIN_LINEAR_MAG_POINT_MIP_LINEAR,
		MIN_LINEAR_MAG_POINT_MIP_POINT,
		MIN_POINT_MAG_LINEAR_MIP_LINEAR,
		MIN_POINT_MAG_LINEAR_MIP_POINT
	};

	enum TextureAddressMode
	{
		WRAP,
		CLAMP,
		MIRROR,
		BORDER
	};

	enum ComparisonFunction
	{
		ALWAYS,
		NEVER,
		LESS,
		LESS_EQUAL,
		EQUAL,
		GREATER_EQUAL,
		GREATER,
		NOT_EQUAL
	};

	enum RenderType
	{
		STATIC,
		DYNAMIC
	};

	enum Primitive
	{
		POINTS,
		LINES,
		LINE_STRIP,
		LINE_LOOP,
		TRIANGLES,
		TRIANGLE_STRIP,
		TRIANGLE_VAN
	};

	//api functions...

	GAPI_API void
		GAPI_Init();

	GAPI_API void
		GAPI_SetClearColor(float r, float g, float b, float a);

	GAPI_API void
		GAPI_ClearBuffers();

	GAPI_API void
		GAPI_UpdateViewport(int width, int height);

	GAPI_API void
		GAPI_ApplyTextureFilters(TextureFilter filter, bool mipmap, unsigned int target);

	GAPI_API int
		GAPI_ApplyTextureFilters(TextureAddressMode mode);

	GAPI_API int
		GAPI_GetAddressMode(TextureAddressMode mode);

	GAPI_API int
		GAPI_GetCompareFunc(ComparisonFunction func);

	GAPI_API unsigned int
		GAPI_CreateVertexBuffer(RenderType type, unsigned int size, void* data);

	GAPI_API unsigned int
		GAPI_CreateIndexBuffer(RenderType type, unsigned int size, void* data);

	GAPI_API void
		GAPI_MapVertexBuffer(unsigned int VBuf_id, unsigned int size, void* data);

	GAPI_API void
		GAPI_MapIndexBuffer(unsigned int IBuf_id, unsigned int size, void* data);

	GAPI_API void
		GAPI_DeleteBuffer(unsigned int buff_id);

	GAPI_API void
		GAPI_BindVertexBuffer(unsigned int VBuf_id);

	GAPI_API void
		GAPI_BindIndexBuffer(unsigned int IBuf_id);

	GAPI_API unsigned int
		GAPI_CreateProgram(char* vertex , char* pixel);

	GAPI_API void
		GAPI_DeleteShader(unsigned int program_id, unsigned int shader_id);

	GAPI_API void
		GAPI_BindShader(unsigned int program_id);

	GAPI_API unsigned int
		GAPI_CreateUniformBuffer(unsigned int size, void* data, unsigned int slot);

	GAPI_API void
		GAPI_MapUniformBuffer(unsigned int buff_id, unsigned int size, void* data);

	GAPI_API void
		GAPI_BindUniformBuffer(unsigned int buff_id, unsigned int slot);

	GAPI_API unsigned int
		GAPI_CreateTexture2D(int img_width, int img_height, void* img_data, bool mipmaps);

	GAPI_API void
		GAPI_MapTexture2D(unsigned int tex_id, int img_width, int img_height, void* img_data);

	GAPI_API void
		GAPI_DeleteTexture2D(unsigned int tex_id);

	GAPI_API void
		GAPI_BindTexture2D(unsigned int tex_id, unsigned int unit);

	GAPI_API void
		GAPI_ApplySamplerTex2D(unsigned int texture_id, bool mipmap,TextureAddressMode U,
							   TextureAddressMode V, TextureFilter filter, ComparisonFunction func,
							   float red, float green, float blue, float alpha);

	GAPI_API unsigned int
		GAPI_CreateVAO(unsigned int VBuf_id, unsigned int IBuf_id, MemoryLayout* input_layout);

	GAPI_API void
		GAPI_Draw(Primitive type, unsigned int VAOBuf_id, unsigned int VBuf_id, unsigned int Vert_count);

	GAPI_API void
		GAPI_DrawIndexed(Primitive type, unsigned int VAOBuf_id, unsigned int VBuf_id, unsigned int IBuf_id, unsigned int Vert_count);

	GAPI_API void
		GAPI_DeleteVAO(unsigned int VAO_id);

}










