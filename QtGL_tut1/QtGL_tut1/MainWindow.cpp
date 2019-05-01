#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	
	connect(ui.RedSlider, &QSlider::valueChanged, ui.Gl_widget , &OpenglWidget::setRed);
	connect(ui.GreenSlider, &QSlider::valueChanged, ui.Gl_widget, &OpenglWidget::setRed);
	connect(ui.BlueSlider, &QSlider::valueChanged, ui.Gl_widget, &OpenglWidget::setRed);
	connect(ui.AlphaSlider, &QSlider::valueChanged, ui.Gl_widget, &OpenglWidget::setRed);

}
