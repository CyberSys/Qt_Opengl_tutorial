#pragma once
#include "IGeomtry.h"

#include <GraphicsGL.h>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Point : public IGeomtry
{
public:
	Point(glm::vec2 pos);
	~Point();

	void Draw();

	void UpdatePosition(glm::vec2 pos);

private:
	float g_vertex_buffer_data[3];
	char *vertexShaderSource;
	char *fragmentShaderSource;
	unsigned int shaderprogram_id = -1;
	unsigned int vertexbuffer_id = -1;
	unsigned int vertexArraybuffer_id = -1;

	glm::vec3 pos = glm::vec3(0.0f);
};