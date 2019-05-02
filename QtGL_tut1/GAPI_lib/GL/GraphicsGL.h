#pragma once

#include "Exports.h"
#include "Enums.h"
#include "MemoryLayout.h"

#include <glm/glm.hpp>

namespace GAPI
{

	GAPI_API void
	GAPI_Init();

	GAPI_API void
	GAPI_Enable(GLcapability cap);

	GAPI_API void
	GAPI_Disable(GLcapability cap);

	GAPI_API void
	GAPI_SetClearColor(float r, float g, float b, float a);

	GAPI_API void
	GAPI_ClearBuffers();

	GAPI_API void
	GAPI_UpdateViewport(int width, int height);

	GAPI_API void
	GAPI_ApplyTextureFilters(TextureFilter filter, bool mipmap, unsigned int target);

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
	GAPI_CreateProgram(char* vertex, char* pixel);

	GAPI_API unsigned int
	GAPI_CreateVertexShader(char* vertex);

	GAPI_API unsigned int
	GAPI_CreatePixelShader(char* pixel);

	GAPI_API unsigned int
	GAPI_CreateGeomtreyShader(char* GS);

	GAPI_API unsigned int
	GAPI_CreateComputeShader(char* CS);

	GAPI_API void
	GAPI_CheckCompileErrors(unsigned int shader_id, std::string type);

	GAPI_API void
	GAPI_DeleteShader(unsigned int program_id, unsigned int shader_id);

	GAPI_API void
	GAPI_BindShader(unsigned int program_id);

	GAPI_API void
	GAPI_SetUniform_int(unsigned int program_id, char* name, int val);

	GAPI_API void
	GAPI_SetUniform_float(unsigned int program_id, char* name, float val);

	GAPI_API void
	GAPI_SetUniform_vec2(unsigned int program_id, char* name, glm::vec2 &value);

	GAPI_API void
	GAPI_SetUniform_vec3(unsigned int program_id, char* name, glm::vec3 &value);

	GAPI_API void
	GAPI_SetUniform_vec4(unsigned int program_id, char* name, glm::vec4 &value);

	GAPI_API void
	GAPI_SetUniform_mat2(unsigned int program_id, char* name, glm::mat2 &mat);

	GAPI_API void
	GAPI_SetUniform_mat3(unsigned int program_id, char* name, glm::mat3 &mat);

	GAPI_API void
	GAPI_SetUniform_mat4(unsigned int program_id, char* name, glm::mat2 &mat);

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
	GAPI_ApplySamplerTex2D(unsigned int texture_id, bool mipmap, TextureAddressMode U,
			TextureAddressMode V, TextureFilter filter, ComparisonFunction func,
			float red, float green, float blue, float alpha);

	GAPI_API unsigned int
	GAPI_CreateVertexArray(unsigned int VBuf_id, unsigned int IBuf_id, MemoryLayout& input_layout);

	GAPI_API void
	GAPI_Draw(Primitive type, unsigned int VAOBuf_id, unsigned int VBuf_id, unsigned int Vert_count);

	GAPI_API void
	GAPI_DrawIndexed(Primitive type, unsigned int VAOBuf_id, unsigned int VBuf_id, unsigned int IBuf_id, unsigned int Vert_count);

	GAPI_API void
	GAPI_DeleteVertexArray(unsigned int VAO_id);
}