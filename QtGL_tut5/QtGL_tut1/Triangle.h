#pragma once
#include "IGeomtry.h"

#include <GraphicsGL.h>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Triangle : public IGeomtry
{
public:
	Triangle(glm::mat4 VP_Mat);
	~Triangle();

	void Draw() override;

	void UpdatePosition(glm::vec2 pos);
	void UpdateRotation(float angle);
	void UpdateScale(glm::vec2 scale);

	glm::vec2 getPosition();


private:
	float g_vertex_buffer_data[30];
	char *vertexShaderSource;
	char *fragmentShaderSource;
	unsigned int shaderprogram_id = -1;
	unsigned int vertexbuffer_id = -1;
	unsigned int vertexArraybuffer_id = -1;

	glm::mat4 modelMat = glm::mat4(1.0f);
	glm::mat4 viewproj_mat = glm::mat4(1.0f);
	glm::mat4 MVP_Mat = glm::mat4(1.0f);

	float r, g, b, a;

	glm::vec3 pos = glm::vec3(0.0f);
	float angle = 0.0f;
	glm::vec3 scale = glm::vec3(50.0f);
};