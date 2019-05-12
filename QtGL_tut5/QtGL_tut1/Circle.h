#pragma once
#include "IGeomtry.h"

#include <vector>
#include <GraphicsGL.h>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Circle : public IGeomtry
{
public:
	Circle(glm::mat4 VP_Mat);
	~Circle();

	void Draw() override;

	void UpdatePosition(glm::vec2 pos);
	void UpdateScale(glm::vec2 scale);

private:
	void generateCircle(float radus , int segments);
	int windowWidth = 711, windoWheight = 711;

	std::vector<float> g_vertex_buffer_data;
	char *vertexShaderSource;
	char *fragmentShaderSource;
	unsigned int shaderprogram_id = -1;
	unsigned int vertexbuffer_id = -1;
	unsigned int vertexArraybuffer_id = -1;

	glm::mat4 modelMat = glm::mat4(1.0f);
	glm::mat4 viewproj_mat = glm::mat4(1.0f);
	glm::mat4 MVP_Mat = glm::mat4(1.0f);

	float r, g, b, a;

	glm::vec3 pos = glm::vec3(50, 50, 0);
	glm::vec3 scale = glm::vec3(10);

	bool once = true;

};