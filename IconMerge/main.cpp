#include "iconmerge.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	IconMerge w;
	w.show();
	return a.exec();
}
