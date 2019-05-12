#include "Circle.h"

Circle::Circle(glm::mat4 VP_Mat) : viewproj_mat(VP_Mat)
{
	r = 0;
	g = 0.5;
	b = 1;
	a = 1;



	vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"uniform mat4 MVP_Mat;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = MVP_Mat * vec4(aPos,1);\n"
		"}\0";

	fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"uniform vec4 color;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(color.x, color.y, color.z, color.w);\n"
		"}\n\0";

	//create shader 
	shaderprogram_id = GAPI::GAPI_CreateProgram(vertexShaderSource, fragmentShaderSource);

	//send uniform value to shader... once to initialize value let do it white color..
	GAPI::GAPI_BindShader(shaderprogram_id);
	GAPI::GAPI_SetUniform_vec4(shaderprogram_id, "color", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

	modelMat = glm::translate(pos) * glm::scale(scale);

	MVP_Mat = viewproj_mat * modelMat;
	//send uniform value to shader... send mvp matrix after calculation..
	GAPI::GAPI_BindShader(shaderprogram_id);
	GAPI::GAPI_SetUniform_mat4(shaderprogram_id, "MVP_Mat", MVP_Mat);

	generateCircle(1, 1000);

	//create vertex buffer object to fill
	vertexbuffer_id = GAPI::GAPI_CreateVertexBuffer(GAPI::RenderType::STATIC, sizeof(float) * g_vertex_buffer_data.size(), &g_vertex_buffer_data[0]);

	//create memory layout how vertex buffer will set in memory..
	GAPI::MemoryElement pos_element;
	pos_element.components = 3;
	pos_element.offset = 0;

	GAPI::MemoryLayout ml;
	ml.size = 3 * sizeof(float);
	ml.elements.push_back(pos_element);

	//create vertex array object to handle all vertex buffers..
	vertexArraybuffer_id = GAPI::GAPI_CreateVertexArray(vertexbuffer_id, 0, ml);
}

Circle::~Circle()
{
}

void Circle::Draw()
{
	if (g_vertex_buffer_data.size() > 0)
	{
		GAPI::GAPI_BindShader(shaderprogram_id);
		GAPI::GAPI_SetUniform_vec4(shaderprogram_id, "color", glm::vec4(r, g, b, a));

		modelMat = glm::translate(pos) * glm::scale(scale);
		MVP_Mat = viewproj_mat * modelMat;

		GAPI::GAPI_SetUniform_mat4(shaderprogram_id, "MVP_Mat", MVP_Mat);

		GAPI::GAPI_Draw(GAPI::Primitive::TRIANGLE_VAN, vertexArraybuffer_id, vertexbuffer_id, g_vertex_buffer_data.size() / 3);
	}
}

void Circle::UpdatePosition(glm::vec2 pos)
{
}

void Circle::UpdateScale(glm::vec2 scale)
{
}

void Circle::generateCircle(float radus, int segments)
{
	const float PI = 3.1415926f;


	float increment = 2.0f * PI / segments;

	for (float currAngle = 0.0f; currAngle <= 2.0f * PI; currAngle += increment)
	{
		g_vertex_buffer_data.push_back(radus * cos(currAngle));
		g_vertex_buffer_data.push_back(radus * sin(currAngle));
		g_vertex_buffer_data.push_back(0.0f);
	}
}
