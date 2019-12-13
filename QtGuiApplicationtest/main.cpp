#include "QtGuiApplicationtest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtGuiApplicationtest w;
	w.show();
	return a.exec();
}
