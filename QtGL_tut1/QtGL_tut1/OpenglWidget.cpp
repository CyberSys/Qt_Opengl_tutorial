#include "OpenglWidget.h"


OpenglWidget::OpenglWidget(QWidget *parent) : 
	QOpenGLWidget(parent),
	g_vertex_buffer_data{-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f,}
{
	

	vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position.xyz = aPos;\n"
		"   gl_Position.w = 1.0;\n"
		"}\0";

	fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"uniform vec4 color;\n"
		"void main()\n"
		"{\n"
		//"   FragColor = vec4(color.x, color.y, color.z, color.w);\n"
		"   FragColor = vec4(1, 1,1,1);\n"
		"}\n\0";

}

OpenglWidget::~OpenglWidget()
{

}

void OpenglWidget::setRed(int val)
{


}

void OpenglWidget::setGreen(int val)
{

}

void OpenglWidget::setBlue(int val)
{

}

void OpenglWidget::setAlpha(int val)
{

}


void OpenglWidget::initializeGL()
{
	//init graphic api..
	GAPI::GAPI_Init();

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
	vertexArraybuffer_id = GAPI::GAPI_CreateVAO(vertexbuffer_id,0, &ml);
}

void OpenglWidget::paintGL()
{
	GAPI::GAPI_ClearBuffers();
	GAPI::GAPI_SetClearColor(0,0,0,1);


	GAPI::GAPI_BindShader(shaderprogram_id);

	GAPI::GAPI_Draw(GAPI::Primitive::TRIANGLES, vertexArraybuffer_id, vertexbuffer_id, 3);
}

void OpenglWidget::resizeGL(int width, int height)
{
}
