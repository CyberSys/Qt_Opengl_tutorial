#include "OpenglWidget.h"

#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp> 


OpenglWidget::OpenglWidget(QWidget *parent) :
	QOpenGLWidget(parent),
	g_vertex_buffer_data{
							// first triangle
							 1.0f,  0.0f, 0.0f,  // top right
							 1.0f,  1.0f, 0.0f,  // bottom right
							 0.0f,  0.0f, 0.0f,  // top left 
							// second triangle
							 1.0f,  1.0f, 0.0f,  // bottom right
							 0.0f,  1.0f, 0.0f,  // bottom left
							 0.0f,  0.0f, 0.0f   // top left
						}
{
	

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

	r = g = b = 1.0f;
	a = 1.0f;

}

OpenglWidget::~OpenglWidget()
{

}

void OpenglWidget::setRed(int val)
{
	r = val / 100.0f;
	update();
}

void OpenglWidget::setGreen(int val)
{
	g = val / 100.0f;
	update();
}

void OpenglWidget::setBlue(int val)
{
	b = val / 100.0f;
	update();
}

void OpenglWidget::setAlpha(int val)
{
	a = val / 100.0f;
	update();
}

void OpenglWidget::setPosX(int val)
{
	rectPosition.x = val;
	update();
}

void OpenglWidget::setPosY(int val)
{
	rectPosition.y = val;
	update();
}

void OpenglWidget::setScaleX(int val)
{
	rectScale.x = val;
	update();
}

void OpenglWidget::setScaleY(int val)
{
	rectScale.y = val;
	update();
}

void OpenglWidget::setRotationZ(float val)
{
	rectRotation_Angle = val / 50.0f;
	update();
}


void OpenglWidget::initializeGL()
{
	//init graphic api..
	GAPI::GAPI_Init();
	GAPI::GAPI_Enable(GAPI::GLcapability::BLENDING);

	//create shader 
	shaderprogram_id = GAPI::GAPI_CreateProgram(vertexShaderSource, fragmentShaderSource);
	
	//create vertex buffer object to fill
	vertexbuffer_id = GAPI::GAPI_CreateVertexBuffer(GAPI::RenderType::STATIC, sizeof(g_vertex_buffer_data), g_vertex_buffer_data);


	//create memory layout how vertex buffer will set in memory..
	GAPI::MemoryElement el;
	el.components = 3;
	el.offset = 0;

	GAPI::MemoryLayout ml;
	ml.size = 0;
	ml.elements.push_back(el);

	//create vertex array object to handle all vertex buffers..
	vertexArraybuffer_id = GAPI::GAPI_CreateVertexArray(vertexbuffer_id,0, ml);

	
	//send uniform value to shader... once to initialize value let do it white color..
	GAPI::GAPI_BindShader(shaderprogram_id);
	GAPI::GAPI_SetUniform_vec4(shaderprogram_id, "color", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));


	//lets initialize transformation matrix to draw our triangle..
	//3d looking
	//projectionMat = glm::perspective(45.0f, float(width())/float(height()), 0.1f, 10000.0f);
	//viewMat = glm::lookAt(camPos, camTarget, camUp);

	//2d looking
	projectionMat = glm::ortho(0.0f ,float(width()), float(height()), 0.0f,0.0f,1000.0f);
	viewMat = glm::mat4(1.0f);
	modelMat = glm::translate(rectPosition) * glm::rotate(rectRotation_Angle,glm::vec3(0,0,1)) * glm::scale(rectScale);
	MVP_Mat = projectionMat * viewMat * modelMat;

	//send uniform value to shader... send mvp matrix after calculation..
	GAPI::GAPI_BindShader(shaderprogram_id);
	GAPI::GAPI_SetUniform_mat4(shaderprogram_id, "MVP_Mat", MVP_Mat);
}

void OpenglWidget::paintGL()
{
	GAPI::GAPI_ClearBuffers();
	GAPI::GAPI_SetClearColor(0,0,0,1);


	GAPI::GAPI_BindShader(shaderprogram_id);
	GAPI::GAPI_SetUniform_vec4(shaderprogram_id, "color", glm::vec4(r, g, b, a));

	modelMat = glm::translate(rectPosition) * glm::rotate(rectRotation_Angle, glm::vec3(0, 0, 1)) * glm::scale(rectScale);
	MVP_Mat = projectionMat * viewMat * modelMat;
	GAPI::GAPI_SetUniform_mat4(shaderprogram_id, "MVP_Mat", MVP_Mat);

	GAPI::GAPI_Draw(GAPI::Primitive::TRIANGLES, vertexArraybuffer_id, vertexbuffer_id, 6);
}

void OpenglWidget::resizeGL(int width, int height)
{
}
