#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	//colors controls
	connect(ui.RedSlider, &QSlider::valueChanged, ui.Gl_widget , &OpenglWidget::setRed);
	connect(ui.GreenSlider, &QSlider::valueChanged, ui.Gl_widget, &OpenglWidget::setGreen);
	connect(ui.BlueSlider, &QSlider::valueChanged, ui.Gl_widget, &OpenglWidget::setBlue);
	connect(ui.AlphaSlider, &QSlider::valueChanged, ui.Gl_widget, &OpenglWidget::setAlpha);

	//transformation 2D controls
	connect(ui.PositionX, qOverload<int>(&QSpinBox::valueChanged), ui.Gl_widget, &OpenglWidget::setPosX);
	connect(ui.PositionY, qOverload<int>(&QSpinBox::valueChanged), ui.Gl_widget, &OpenglWidget::setPosY);
	connect(ui.ScaleX, qOverload<int>(&QSpinBox::valueChanged), ui.Gl_widget, &OpenglWidget::setScaleX);
	connect(ui.ScaleY, qOverload<int>(&QSpinBox::valueChanged), ui.Gl_widget, &OpenglWidget::setScaleY);
	connect(ui.RotationZ, &QSlider::valueChanged, ui.Gl_widget, &OpenglWidget::setRotationZ);

}
