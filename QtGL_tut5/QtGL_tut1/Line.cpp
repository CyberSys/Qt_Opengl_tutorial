#include "Line.h"

Line::Line(glm::mat4 VP_Mat) : viewproj_mat(VP_Mat),
	g_vertex_buffer_data{
						 0.0f,  0.0f, 0.0f,  
						 1.0f,  0.0f, 0.0f  
						 }
{
	r = 1;
	g = 0;
	b = 0; 
	a = 1;

	vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"uniform mat4 MVP_Mat;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = MVP_Mat * vec4(aPos,1);\n"
		"}\0";

	fragmentShaderSource = "#version 330 core\n"
		"in vec2 TexCoord;\n"
		"out vec4 FragColor;\n"
		"uniform vec4 color;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(color.x, color.y, color.z, color.w);\n"
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
	ml.size = 3 * sizeof(float);
	ml.elements.push_back(pos_element);

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

Line::~Line()
{
}

void Line::Draw()
{
	GAPI::GAPI_BindShader(shaderprogram_id);
	GAPI::GAPI_SetUniform_vec4(shaderprogram_id, "color", glm::vec4(r, g, b, a));

	modelMat = glm::translate(pos) * glm::rotate(angle, glm::vec3(0, 0, 1)) * glm::scale(scale);
	MVP_Mat = viewproj_mat * modelMat;

	GAPI::GAPI_SetUniform_mat4(shaderprogram_id, "MVP_Mat", MVP_Mat);

	GAPI::GAPI_Draw(GAPI::Primitive::LINE_STRIP, vertexArraybuffer_id, vertexbuffer_id, 2);
}

void Line::UpdatePosition(glm::vec2 pos)
{
	this->pos.x = pos.x;
	this->pos.y = pos.y;
}

void Line::UpdateRotation(float angle)
{
	this->angle = angle;
}

void Line::UpdateScale(glm::vec2 scale)
{
	this->scale.x = scale.x;
	this->scale.y = scale.y;
}
