#pragma once
#include "IGeomtry.h"

#include <vector>
#include <GraphicsGL.h>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

class GPolygon : public IGeomtry
{
public:
	GPolygon(glm::vec2 startpoint, glm::mat4 VP_Mat,int window_width, int window_height);
	~GPolygon();

	void Draw() override;


	void UpdatePosition(glm::vec2 pos);
	void UpdateRotation(float angle);
	void UpdateScale(glm::vec2 scale);

	void AddPoint(glm::vec2 point);


private:
	void SetUpPolygon();
	glm::vec2 transformPoint_from_viewportPixel_to_NDC(glm::vec2 point, int window_width, int window_height);
	int windowWidth, windoWheight;

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

	glm::vec3 pos = glm::vec3(0,0,0);
	float angle = 0.0f;
	glm::vec3 scale = glm::vec3(1);

	bool once = true;
};

