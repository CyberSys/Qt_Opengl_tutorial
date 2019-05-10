#include "Point.h"

Point::Point(glm::vec2 pos) : g_vertex_buffer_data{ 0.0f, 0.0f, 0.0f }
{

	vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos,1);\n"
		"}\0";

	fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(1, 1, 1, 1);\n"
		"}\n\0";

	//create shader 
	shaderprogram_id = GAPI::GAPI_CreateProgram(vertexShaderSource, fragmentShaderSource);

	//create vertex buffer object to fill
	vertexbuffer_id = GAPI::GAPI_CreateVertexBuffer(GAPI::RenderType::STATIC, sizeof(g_vertex_buffer_data), g_vertex_buffer_data);

	//create memory layout how vertex buffer will set in memory..
	GAPI::MemoryElement pos_element;
	pos_element.components = 3;
	pos_element.offset = 0;

	GAPI::MemoryLayout ml;
	ml.size = 0;
	ml.elements.push_back(pos_element);

	//create vertex array object to handle all vertex buffers..
	vertexArraybuffer_id = GAPI::GAPI_CreateVertexArray(vertexbuffer_id, 0, ml);
}

Point::~Point()
{
}

void Point::Draw()
{
	GAPI::GAPI_BindShader(shaderprogram_id);
	GAPI::GAPI_Draw(GAPI::Primitive::POINTS, vertexArraybuffer_id, vertexbuffer_id, 1);
}

void Point::UpdatePosition(glm::vec2 pos)
{
	this->pos.x = pos.x;
	this->pos.y = pos.y;

	g_vertex_buffer_data[0] = pos.x;
	g_vertex_buffer_data[1] = pos.y;
	GAPI::GAPI_UpdateVertexBuffer(vertexbuffer_id, GAPI::RenderType::STATIC, sizeof(g_vertex_buffer_data), g_vertex_buffer_data);
	
}
