#include "pass_scheduler.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QPalette pal = a.palette();
	QColor color(0,220,255,255);
	pal.setColor(QPalette::Window,color);
	a.setPalette(pal);
	Pass_scheduler w;
	w.show();
	return a.exec();
}
