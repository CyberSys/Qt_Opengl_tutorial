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

protected:
	void initializeGL() override;
	void paintGL() override;
	void resizeGL(int width, int height) override;

private:
	 GLfloat g_vertex_buffer_data[9];
	 unsigned int vertexbuffer_id = -1;
	 unsigned int vertexArraybuffer_id = -1;
	 unsigned int shaderprogram_id = -1;
	 char *vertexShaderSource;
	 char *fragmentShaderSource;

	 float r, g, b, a;
};
