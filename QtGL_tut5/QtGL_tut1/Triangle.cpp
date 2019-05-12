#include "Triangle.h"

Triangle::Triangle(glm::mat4 VP_Mat) : viewproj_mat(VP_Mat),
g_vertex_buffer_data{
	// first triangle        UVs 
	 1.0f,  0.0f, 0.0f,    1.0f, 0.0f,  // top right
	 1.0f,  1.0f, 0.0f,    1.0f, 1.0f,  // bottom right
	 0.0f,  0.0f, 0.0f,    0.0f, 0.0f,  // top left 
}
{
	r = g = b = a = 1;

	vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"layout (location = 1) in vec2 aTexCoord;\n"
		"uniform mat4 MVP_Mat;\n"
		"out vec2 TexCoord;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = MVP_Mat * vec4(aPos,1);\n"
		"   TexCoord = aTexCoord;\n"
		"}\0";

	fragmentShaderSource = "#version 330 core\n"
		"in vec2 TexCoord;\n"
		"out vec4 FragColor;\n"
		"uniform vec4 color;\n"
		"uniform sampler2D ourTexture;\n"
		"void main()\n"
		"{\n"
		"   FragColor = /*texture(ourTexture, TexCoord) */ vec4(color.x, color.y, color.z, color.w);\n"
		"}\n\0";

	//create shader 
	shaderprogram_id = GAPI::GAPI_CreateProgram(vertexShaderSource, fragmentShaderSource);

	//create vertex buffer object to fill
	vertexbuffer_id = GAPI::GAPI_CreateVertexBuffer(GAPI::RenderType::STATIC, sizeof(g_vertex_buffer_data), g_vertex_buffer_data);

	//create memory layout how vertex buffer will set in memory..
	GAPI::MemoryElement pos_element;
	pos_element.components = 3;
	pos_element.offset = 0;

	GAPI::MemoryElement uv_element;
	uv_element.components = 2;
	uv_element.offset = 3 * sizeof(float);

	GAPI::MemoryLayout ml;
	ml.size = 5 * sizeof(float);
	ml.elements.push_back(pos_element);
	ml.elements.push_back(uv_element);

	//create vertex array object to handle all vertex buffers..
	vertexArraybuffer_id = GAPI::GAPI_CreateVertexArray(vertexbuffer_id, 0, ml);


	//send uniform value to shader... once to initialize value let do it white color..
	GAPI::GAPI_BindShader(shaderprogram_id);
	GAPI::GAPI_SetUniform_vec4(shaderprogram_id, "color", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

	modelMat = glm::translate(pos) * glm::rotate(angle, glm::vec3(0, 0, 1)) * glm::scale(scale);

	MVP_Mat = viewproj_mat * modelMat;
	//send uniform value to shader... send mvp matrix after calculation..
	GAPI::GAPI_BindShader(shaderprogram_id);
	GAPI::GAPI_SetUniform_mat4(shaderprogram_id, "MVP_Mat", MVP_Mat);
}

Triangle::~Triangle()
{
}

void Triangle::Draw()
{
	GAPI::GAPI_BindShader(shaderprogram_id);
	GAPI::GAPI_SetUniform_vec4(shaderprogram_id, "color", glm::vec4(r, g, b, a));

	modelMat = glm::translate(pos) * glm::rotate(angle, glm::vec3(0, 0, 1)) * glm::scale(scale);
	MVP_Mat = viewproj_mat * modelMat;

	GAPI::GAPI_SetUniform_mat4(shaderprogram_id, "MVP_Mat", MVP_Mat);

	GAPI::GAPI_Draw(GAPI::Primitive::TRIANGLES, vertexArraybuffer_id, vertexbuffer_id, 3);
}

void Triangle::UpdatePosition(glm::vec2 pos)
{
	this->pos.x = pos.x;
	this->pos.y = pos.y;
}

void Triangle::UpdateRotation(float angle)
{
	this->angle = angle;
}

void Triangle::UpdateScale(glm::vec2 scale)
{
	this->scale.x = scale.x;
	this->scale.y = scale.y;
}

glm::vec2 Triangle::getPosition()
{
	glm::vec2 res;
	res.x = pos.x;
	res.y = pos.y;
	return res;
}
