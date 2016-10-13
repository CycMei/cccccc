#ifndef QTONE_H
#define QTONE_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/qmouseeventtransition.h>
#include "ui_qtone.h"
#include<qevent.h>
#include<qpushbutton.h>

class QtOne : public QMainWindow
{
	Q_OBJECT

public:
	QtOne(QWidget *parent = 0);
	~QtOne();
private:
	Ui::QtOneClass ui;
	QPoint last;
	QPushButton *btnClose;
protected:
	void mousePressEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);
	void mouseReleaseEvent1(QMouseEvent *e);
};

#endif // QTONE_H
