
#include "CComplier.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CComplier w;
	
	w.show();
	return a.exec();
}
