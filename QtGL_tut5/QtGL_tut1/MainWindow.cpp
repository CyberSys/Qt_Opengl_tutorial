#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	//toolbar
	QPixmap pointpix("Resources/Points.png");
	QPixmap trianglepix("Resources/triangles.png");
	QPixmap linepix("Resources/lines.png");
	QPixmap rectpix("Resources/rectangles.png");
	QPixmap polypix("Resources/polygon.png");
	QPixmap circlepix("Resources/circle.png");

	QToolBar *toolbar = addToolBar("main toolbar");
	toolbar->setIconSize(QSize(35, 35));
	toolbar->setMovable(false);

	toolbar->addAction(QIcon(pointpix), "New Point");
	toolbar->addAction(QIcon(linepix), "New Line");
	toolbar->addAction(QIcon(trianglepix), "New Triangle");
	toolbar->addAction(QIcon(rectpix), "New Rectangle");
	toolbar->addAction(QIcon(circlepix), "New Circle");
	toolbar->addAction(QIcon(polypix), "New Polygon");
}
