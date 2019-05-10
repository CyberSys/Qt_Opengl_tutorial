#pragma once

#include <QOpenGLWidget>
#include <GraphicsGL.h>

#include "IGeomtry.h"
#include "Rectangle.h"
#include "Point.h"
#include "Line.h"
#include "Polygon.h"

class OpenglWidget : public QOpenGLWidget
{
	Q_OBJECT

public:
	OpenglWidget(QWidget *parent);
	~OpenglWidget();


protected:
	void initializeGL() override;
	void paintGL() override;
	void mousePressEvent(QMouseEvent *event) override;
	void mouseMoveEvent(QMouseEvent *event) override;

private:
	//camera props
	glm::mat4 viewprojMat = glm::mat4(1.0f);
	glm::mat4 projectionMat = glm::mat4(1.0f);

	glm::vec2 m_lastPos = glm::vec2(0);


	//geomtry
	GRectangle *geo;
};
