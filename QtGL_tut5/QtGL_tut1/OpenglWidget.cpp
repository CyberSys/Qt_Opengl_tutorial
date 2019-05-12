#include "OpenglWidget.h"
#include <QMouseEvent>


OpenglWidget::OpenglWidget(QWidget *parent) : QOpenGLWidget(parent)
{
}

OpenglWidget::~OpenglWidget()
{
	delete geo;
}

void OpenglWidget::initializeGL()
{
	//init graphic api..
	GAPI::GAPI_Init();
	GAPI::GAPI_Enable(GAPI::GLcapability::BLENDING);
	w = width();
	h = height();

	projectionMat = glm::ortho(0.0f, float(width()), float(height()), 0.0f, 0.0f, 1000.0f);
	viewprojMat = projectionMat * viewprojMat;

	geo = new GPolygon(glm::vec2(0.0f, 0.0f), viewprojMat, w, h);

	circl = new Circle(viewprojMat);

	tri = new Triangle(viewprojMat);
	tri->UpdatePosition(glm::vec2(250,250));

	point = new Point(viewprojMat);
	point->UpdatePosition(glm::vec2(350,50));


	lin = new Line(viewprojMat);
	lin->UpdatePosition(glm::vec2(50,250));

	rect = new GRectangle(viewprojMat);
	rect->UpdatePosition(glm::vec2(500,500));
	rect->UpdateRotation(45);
}

void OpenglWidget::paintGL()
{

	GAPI::GAPI_ClearBuffers();
	GAPI::GAPI_SetClearColor(0,0,0,1);

	if(geo != NULL)
		geo->Draw();

	circl->Draw();

	tri->Draw();

	point->Draw();

	lin->Draw();

	rect->Draw();
}

bool CheckLineTri(glm::vec2 rectpos, glm::vec2 scale, glm::vec2 mousepos)
{
	if (mousepos.x > rectpos.x && mousepos.x < (rectpos.x + scale.x))
	{
		if (mousepos.y > rectpos.y && mousepos.y < (rectpos.y + scale.y))
		{
			return true;
		}
	}
	return false;
}

glm::vec2 NormalizeFromPixelCoordsToNDC(glm::vec2 point, int screenwidth, int screenheight)
{

	/*
	  normalization eq;
	  zi= xi−min(x) / max(x)−min(x); 
	*/

	glm::vec2 res;

	res.x = (point.x - 0) / (screenwidth - 0);
	res.y = (point.y - 0) / (screenheight - 0);

	return res;
}

void OpenglWidget::mousePressEvent(QMouseEvent * eve)
{
	m_lastPos.x = eve->x();
	m_lastPos.y = eve->y();

		glm::vec2 NDC_point = NormalizeFromPixelCoordsToNDC(m_lastPos, w, h);
		geo->AddPoint(NDC_point);

	update();
}

void OpenglWidget::mouseMoveEvent(QMouseEvent * event)
{
	//int dx = event->x() - m_lastPos.x;
	//int dy = event->y() - m_lastPos.y;

	//if (event->buttons() & Qt::LeftButton)
	//{
	//	glm::vec2 tp3 = glm::vec2(m_lastPos.x, m_lastPos.y);
	//	glm::vec2 pos = geo->getPosition();

	//	if (CheckLineTri(pos, geo->getrectSize(), tp3))
	//	{
	//		pos.x = pos.x + dx;
	//		pos.y = pos.y + dy;
	//		geo->UpdatePosition(glm::vec2(pos.x, pos.y));
	//		m_lastPos.x = event->x();
	//		m_lastPos.y = event->y();
	//		update();
	//	}
	//}
}

/*

float sign(fPoint p1, fPoint p2, fPoint p3)
{
	return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool PointInTriangle(fPoint pt, fPoint v1, fPoint v2, fPoint v3)
{
	float d1, d2, d3;
	bool has_neg, has_pos;

	d1 = sign(pt, v1, v2);
	d2 = sign(pt, v2, v3);
	d3 = sign(pt, v3, v1);

	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(has_neg && has_pos);
}
*/