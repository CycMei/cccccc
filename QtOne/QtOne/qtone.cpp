#include "qtone.h"

QtOne::QtOne(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("cyc");
	this->setMaximumSize(300, 300);
	this->setMinimumSize(300, 300);
	this->move(100, 100);
	this->setStyleSheet("background:red");
	this->setWindowIcon(QIcon(":/new/prefix1/icn"));
	this->setWindowFlags(Qt::FramelessWindowHint);
	btnClose = new QPushButton(this);
	btnClose->setText("butclose");
	connect(btnClose, SIGNAL(clicked()), this, SLOT(close()));
	this->setWindowFlags(Qt::WindowCloseButtonHint);
}
void QtOne::mousePressEvent(QMouseEvent *e) {
	last = e->globalPos();
}
void QtOne::mouseMoveEvent(QMouseEvent *e) {
	int dx = e->globalX() - last.x();
	int dy = e->globalY() - last.y();
	last = e->globalPos();
	move(x() + dx, y() + dy);
}
void QtOne::mouseReleaseEvent1(QMouseEvent *e) {
	int dx = e->globalX() - last.x();
	int dy = e->globalY() - last.y();
	move(x() + dx, y() + dy);
}
QtOne::~QtOne()
{

}
