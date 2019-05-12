#include "Polygon.h"

GPolygon::GPolygon(glm::vec2 startpoint, glm::mat4 VP_Mat, int window_width, int window_height) : viewproj_mat(VP_Mat), 
																			windowWidth(window_width),
																			windoWheight(window_height)
{
	r = g = b = a = 1;

	scale = glm::vec3(windowWidth, window_height, 0);

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

	modelMat = glm::translate(pos) * glm::rotate(angle, glm::vec3(0, 0, 1)) * glm::scale(scale);

	MVP_Mat = viewproj_mat * modelMat;
	//send uniform value to shader... send mvp matrix after calculation..
	GAPI::GAPI_BindShader(shaderprogram_id);
	GAPI::GAPI_SetUniform_mat4(shaderprogram_id, "MVP_Mat", MVP_Mat);

	

	g_vertex_buffer_data.push_back(startpoint.x);
	g_vertex_buffer_data.push_back(startpoint.y);
	g_vertex_buffer_data.push_back(0.0f);

	SetUpPolygon();
}

GPolygon::~GPolygon()
{
}

void GPolygon::Draw()
{
	if (g_vertex_buffer_data.size() > 0)
	{
		GAPI::GAPI_BindShader(shaderprogram_id);
		GAPI::GAPI_SetUniform_vec4(shaderprogram_id, "color", glm::vec4(r, g, b, a));

		modelMat = glm::translate(pos) * glm::rotate(angle, glm::vec3(0, 0, 1)) * glm::scale(scale);
		MVP_Mat = viewproj_mat * modelMat;

		GAPI::GAPI_SetUniform_mat4(shaderprogram_id, "MVP_Mat", MVP_Mat);

		GAPI::GAPI_Draw(GAPI::Primitive::LINES, vertexArraybuffer_id, vertexbuffer_id, g_vertex_buffer_data.size() / 3);
		GAPI::GAPI_Draw(GAPI::Primitive::POINTS, vertexArraybuffer_id, vertexbuffer_id, g_vertex_buffer_data.size() / 3);
	}

}

void GPolygon::UpdatePosition(glm::vec2 pos)
{
	this->pos.x = pos.x;
	this->pos.y = pos.y;
}

void GPolygon::UpdateRotation(float angle)
{
}

void GPolygon::UpdateScale(glm::vec2 scale)
{
}

glm::vec2 GPolygon::transformPoint_from_viewportPixel_to_NDC(glm::vec2 point,int window_width,int window_height)
{
	float x = (2.0f * point.x) / window_width - 1.0f;
	float y = 1.0f - (2.0f * point.y) / window_height;
	float z = 1.0f;
	glm::vec3 ray_nds = glm::vec3(x, y, z);
	glm::vec4 ray_clip = glm::vec4(ray_nds.x, ray_nds.y, -1.0, 1.0);
	glm::vec4 ray_eye = glm::inverse(viewproj_mat) * ray_clip;
	ray_eye = glm::vec4(ray_eye.x , ray_eye.y, -1.0, 0.0);

	glm::vec4 ray_wor = (glm::inverse(glm::mat4(1.0f)) * ray_eye);
	// don't forget to normalise the vector at some point
	ray_wor = glm::normalize(ray_wor);

	glm::vec2 res = glm::vec2(ray_wor.x, ray_wor.y);
	return res;
}

void GPolygon::AddPoint(glm::vec2 point) 
{
	if (once)
	{
		once = false;
		g_vertex_buffer_data[0] = point.x;
		g_vertex_buffer_data[1] = point.y;
	}

		g_vertex_buffer_data.push_back(point.x);
		g_vertex_buffer_data.push_back(point.y);
		g_vertex_buffer_data.push_back(0.0f);
		GAPI::GAPI_UpdateVertexBuffer(vertexbuffer_id, GAPI::RenderType::DYNAMIC, sizeof(float) * g_vertex_buffer_data.size(), &g_vertex_buffer_data[0]);
}

void GPolygon::SetUpPolygon()
{
	//create vertex buffer object to fill
	vertexbuffer_id = GAPI::GAPI_CreateVertexBuffer(GAPI::RenderType::DYNAMIC, sizeof(float) * g_vertex_buffer_data.size(), &g_vertex_buffer_data[0]);

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
