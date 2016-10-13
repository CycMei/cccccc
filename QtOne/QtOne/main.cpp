#include "qtone.h"
#include <QtWidgets/QApplication>
#include<QtSql\qsqldatabase.h>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtOne w;
	w.show();
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","one");
	return a.exec();
}
