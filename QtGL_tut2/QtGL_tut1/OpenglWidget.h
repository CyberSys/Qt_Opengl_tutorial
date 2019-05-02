#pragma once

#include <QOpenGLWidget>
#include <GraphicsGL.h>

class OpenglWidget : public QOpenGLWidget
{
	Q_OBJECT

public:
	OpenglWidget(QWidget *parent);
	~OpenglWidget();

public slots:
	void setRed(int val);
	void setGreen(int val);
	void setBlue(int val);
	void setAlpha(int val);

	//transformations 2D
	void setPosX(int val);
	void setPosY(int val);
	void setScaleX(int val);
	void setScaleY(int val);
	void setRotationZ(float val);

protected:
	void initializeGL() override;
	void paintGL() override;
	void resizeGL(int width, int height) override;

private:
	 GLfloat g_vertex_buffer_data[18];
	 unsigned int vertexbuffer_id = -1;
	 unsigned int vertexArraybuffer_id = -1;
	 unsigned int shaderprogram_id = -1;
	 char *vertexShaderSource;
	 char *fragmentShaderSource;

	 float r, g, b, a;

	 //simple camera..
	 glm::vec3 camPos = glm::vec3(3.0f, 4.0f, -3.0f);
	 glm::vec3 camTarget = glm::vec3(0.0f);
	 glm::vec3 camUp = glm::vec3(0.0f,1.0f,0.0f);

	 //transfomrmations
	 glm::vec3 rectPosition = glm::vec3(50.0f, 50.0f, 0.0f);
	 glm::vec3 rectScale = glm::vec3(100.0f);
	 float rectRotation_Angle = 0.0f;

	 glm::mat4 modelMat = glm::mat4(1.0f);
	 glm::mat4 viewMat = glm::mat4(1.0f);
	 glm::mat4 projectionMat = glm::mat4(1.0f);

	 glm::mat4 MVP_Mat = glm::mat4(1.0f);
};
